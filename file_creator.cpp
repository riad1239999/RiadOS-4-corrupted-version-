#include "file_creator.hpp"
#include "filesystem.hpp"     // For file creation logic
#include "gui.hpp"            // For GUI rendering helpers
#include <string>

// Function to create a new text file
void create_text_file() {
    std::string fileName;
    std::string fileContent;

    // Simulate asking the user for the file name and content via a basic GUI input
    draw_text_input_box(50, 50, "Enter file name: ", 0xFFFFFF, fileName);
    draw_text_input_box(50, 150, "Enter content: ", 0xFFFFFF, fileContent);

    // Check if the filename and content are valid
    if (!fileName.empty() && !fileContent.empty()) {
        // Create the new file in memory
        create_file(fileName, fileContent, "txt");

        // Notify the user the file has been created
        draw_text(50, 250, "File Created Successfully!", 0x00FF00);
    } else {
        // If filename or content is empty, display an error
        draw_text(50, 250, "Error: Filename or Content is empty!", 0xFF0000);
    }
}

// Function to handle the file creation window
void draw_file_creation_window() {
    draw_box(50, 50, 400, 300, 0x222222);  // Create a background box for the window
    draw_text(60, 60, "Create a New File", 0xFFFFFF);  // Window title

    // Optionally, you can add a "Create" button here and trigger the file creation
    draw_button(50, 200, "Create", 0x888888, 0xFFFFFF, create_text_file);
}

// Function to simulate the text input box (just for demonstration purposes)
void draw_text_input_box(int x, int y, const std::string& prompt, uint32_t textColor, std::string& inputText) {
    // Draw the text input box and prompt
    draw_box(x, y, 300, 30, 0x444444);  // Box for text input
    draw_text(x + 10, y + 10, prompt.c_str(), textColor);  // Text prompt

    // Here, you would normally get input from the user (keyboard events)
    // For simplicity, assume a hardcoded input for now
    inputText = "Example File";  // Example input (can be replaced with real user input logic)
}

// Function to simulate button click (for "Create" button in this case)
void draw_button(int x, int y, const std::string& label, uint32_t buttonColor, uint32_t textColor, void(*action)()) {
    draw_box(x, y, 100, 40, buttonColor);  // Draw the button
    draw_text(x + 20, y + 10, label, textColor);  // Button label text

    // Simulate the button press action
    action();  // Trigger the action (create the file)
}
