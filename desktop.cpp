#include "desktop.hpp"
#include "filesystem.hpp"      // For file system logic
       // GUI rendering helpers

// Define the app icons for the desktop
AppIcon desktopApps[] = {
    {"File Manager", 50, 50, open_file_manager},
    {"Create Text File", 50, 100, open_text_file_creator},
 
};

// Function to create the desktop and add app icons
void create_desktop() {
    // Add example files to memory for the desktop
    create_file("Test Program", "This is a test EXE program.", "exe");
    create_file("Read Me", "This is a text file. Welcome to the OS!", "txt");

    // Optionally, you can add more files here for testing
    // create_file("Another Program", "Yet another test EXE program.", "exe");
    // create_file("Another File", "This is another text file.", "txt");
}

// Function to draw the desktop background and icons
void draw_desktop() {
    draw_box(0, 0, 640, 480, 0xAAAAAA);  // Background

    // Draw app icons
    for (auto& app : desktopApps) {
        draw_box(app.x, app.y, 120, 40, 0x888888);  // Icon box
        draw_text(app.x + 10, app.y + 10, app.name, 0xFFFFFF);  // Icon text
    }
}


}

// Function to open the file manager app
bool open_file_manager() {
    draw_file_window(0, 0);  // Display file manager window
    return true;
}

// Function to open the text file creator app
bool open_text_file_creator() {
    create_text_file();  // Create a new text file
    return true;
}

// Function to open an EXE file (simulate running it)
bool open_exe_file() {
    run_file("Test Program");  // Simulate running the EXE file
 
}

// Function to open a TXT file (display its content)

