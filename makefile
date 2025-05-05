# === Tools ===
AS        = nasm
CC        = i686-elf-g++
LD        = i686-elf-ld
GRUBMKRESCUE = grub-mkrescue



# === Flags ===
CFLAGS    = -std=c++17 -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
ASFLAGS   = -f elf
LDFLAGS   = -T linker.ld -nostdlib

# === Source files ===
ASM_SRC   = boot.asm kernel.asm
CPP_SRC   = \
    main.cpp kernel.cpp io.cpp interrupts.cpp timer.cpp keyboard.cpp vga.cpp graphics_loader.cpp \
    desktop.cpp file_creator.cpp filesystem.cpp filesystem_gui.cpp

HEADERS   = \
    io.hpp interrupts.hpp timer.hpp keyboard.hpp vga.hpp kernel.hpp graphics_loader.hpp gui.hpp \
    desktop.hpp

ASM_OBJ   = $(addprefix $(BUILD_DIR)/, $(ASM_SRC:.asm=.o))
CPP_OBJ   = $(addprefix $(BUILD_DIR)/, $(CPP_SRC:.cpp=.o))
OBJ       = $(ASM_OBJ) $(CPP_OBJ)

# === Output ===


# === Targets ===
all: $(ISO_IMAGE)

# Compile ASM
$(BUILD_DIR)/%.o: %.asm
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $< -o $@

# Compile C++
$(BUILD_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Link Kernel
$(KERNEL_BIN): $(OBJ)
	$(LD) $(LDFLAGS) -o $@ $(OBJ)

# Make ISO
$(ISO_IMAGE): $(KERNEL_BIN)
	@mkdir -p $(ISO_DIR)/boot/grub
	cp $(KERNEL_BIN) $(ISO_DIR)/boot/kernel.bin
	echo 'set timeout=0' >  $(ISO_DIR)/boot/grub/grub.cfg
	echo 'set default=0' >> $(ISO_DIR)/boot/grub/grub.cfg
	echo 'menuentry "RiadOS 4" {' >> $(ISO_DIR)/boot/grub/grub.cfg
	echo '  multiboot /boot/kernel.bin' >> $(ISO_DIR)/boot/grub/grub.cfg
	echo '  boot' >> $(ISO_DIR)/boot/grub/grub.cfg
	echo '}' >> $(ISO_DIR)/boot/grub/grub.cfg
	$(GRUBMKRESCUE) -o $(ISO_IMAGE) $(ISO_DIR)

run: all
	qemu-system-i386 -cdrom $(ISO_IMAGE)
