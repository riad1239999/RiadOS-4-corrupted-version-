#ifndef KERNEL_HPP
#define KERNEL_HPP

// Include necessary headers
#include "boot.asm"
#include "desktop.hpp"
#include "file_creator.hpp"
#include "filesystem.hpp"
#include "filesystem_gui.hpp"
#include "graphics_loader.hpp"
#include "gui.hpp"
#include "interrupts.hpp"
#include "io.hpp"
#include "keyboard.hpp"
#include "timer.hpp"
#include "vga.hpp"

// Function prototypes
void init_kernel();               // Initialize the kernel
void handle_input();              // Handle user input (keyboard, mouse, etc.)
void init_graphics();             // Initialize the graphical system (e.g., VGA mode)
void set_video_mode(uint8_t mode); // Set video mode for the graphical system

// Mouse-related functions (simple placeholders)
int get_mouse_x();
int get_mouse_y();
bool mouse_clicked();

// Other functions you may need
void create_desktop();  // Create and display the desktop GUI
void draw_desktop();    // Render the desktop GUI

#endif // KERNEL_HPP
