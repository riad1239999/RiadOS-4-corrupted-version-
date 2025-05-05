#ifndef DESKTOP_HPP
#define DESKTOP_HPP

#include <stdint.h>

// Represents an app icon on the desktop
struct AppIcon {
    const char* name;
    int x, y;  // Position of the icon on the desktop
    bool (*action)();  // Function to run when clicked
};

// Create icons for the apps on the desktop
void create_desktop();

// Draw the desktop with icons
void draw_desktop();

// Handle mouse click to launch apps
void handle_desktop_click(int mouseX, int mouseY);

#endif
