#ifndef GUI_HPP
#define GUI_HPP

#include <stdint.h>

// Draws a filled rectangle (GUI box)
void draw_box(int x, int y, int width, int height, uint32_t color);

// Draws text on screen at given coordinates
void draw_text(int x, int y, const char* text, uint32_t color);

// Draws a scrollable file content box
void draw_file_content(int x, int y, const char* content, uint32_t color);
#endif
