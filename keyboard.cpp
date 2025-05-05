#include "keyboard.hpp"
#include "io.hpp"
#include <stdint.h>

#define KEYBOARD_CMD_PORT 0x64  // The keyboard command port

// Function to initialize the keyboard (set up the IRQ handler)
void init_keyboard() {
    // Set up the interrupt handler for IRQ1 (keyboard)
    // Assuming you're using IDT (interrupt descriptor table)
    // This should connect IRQ1 to the keyboard_handler


}
