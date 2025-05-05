#include <vector>
#include <string>
#include <iostream>

// Define a struct to represent a file
struct File {
    std::string name;
    std::string content;
    std::string type;  // "txt", "exe", or other types
};

// List to hold files in memory
std::vector<File> fileList;

// Function to create a new file in memory
void create_file(const std::string& name, const std::string& content, const std::string& type) {
    fileList.push_back({name, content, type});
}

// Get the list of files
const std::vector<File>& get_files() {
    return fileList;
}

// Get the content of a specific file by name
std::string get_file_content(const std::string& name) {
    for (const auto& file : fileList) {
        if (file.name == name) {
            return file.content;
        }
    }
    return "";  // Return empty if file not found
}

// Run a file (simulate execution for .exe files)
void run_file(const std::string& name) {
    for (const auto& file : fileList) {
        if (file.name == name) {
            if (file.type == "exe") {
                // Simulate running an .exe file
                std::cout << "Running " << file.name << "...\n";
                // Actual execution would require a full process manager (this is just a simulation)
            } else if (file.type == "txt") {
                // Open the .txt file (display its contents)
                std::cout << "Opening " << file.name << ":\n" << file.content << "\n";
            } else {
                std::cout << "Unsupported file type.\n";
            }
        }
    }
}

// Function to save file to disk (not yet implemented, just a placeholder)
void save_file(const std::string& name, const std::string& content, const std::string& type) {
    // You can add actual file saving logic here (e.g., using file I/O operations)
    std::cout << "Saving file: " << name << "\n";
}

// Function to delete a file from memory
void delete_file(const std::string& name) {
    for (auto it = fileList.begin(); it != fileList.end(); ++it) {
        if (it->name == name) {
            fileList.erase(it);
            std::cout << "Deleted file: " << name << "\n";
            return;
        }
    }
    std::cout << "File not found: " << name << "\n";
}
