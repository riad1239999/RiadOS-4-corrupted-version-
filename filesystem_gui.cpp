#include "gui.hpp"
#include "filesystem.cpp"

// Assume a simple mouse click handler (just a position check here)
bool is_mouse_within(int mouseX, int mouseY, int x, int y, int width, int height) {
    return mouseX >= x && mouseX <= (x + width) && mouseY >= y && mouseY <= (y + height);
}

void draw_file_window(int mouseX, int mouseY) {
    int x = 50, y = 50;
    int width = 300, height = 200;
    draw_box(x, y, width, height, 0xFF4444FF); // Blue window

    draw_text(x + 10, y + 10, "Files:", 0xFFFFFFFF);

    int fileY = y + 30;
    for (const auto& file : get_files()) {
        draw_text(x + 10, fileY, file.name.c_str(), 0xFFFFFF00); // Yellow text

        // Check if the mouse is over the file name and clicked
        if (is_mouse_within(mouseX, mouseY, x + 10, fileY, 200, 15)) {
            // If clicked, show file content
            draw_file_content(x + 10, fileY + 20, get_file_content(file.name).c_str(), 0xFFFFFFFF);
        }

        fileY += 15;
    }
}

// Function to draw file content in the display area
void draw_file_content(int x, int y, const char* content, uint32_t color) {
    draw_box(x, y, 280, 140, 0xFF2222FF);  // Content box
    draw_text(x + 10, y + 10, content, color);
}
