#include <iostream>      // For input/output
#include <fstream>       // For file reading
#include <sstream>       // For string processing
#include <string>        // For std::string
#include "memory_manager.h" // Your memory manager header

/**
 * @brief Program entry point.
 *
 * This application simulates a memory manager that reads commands
 * from a .cmmd file and executes them (INSERT, READ, DELETE, UPDATE, DUMP).
 *
 * @param argc Number of command-line arguments
 * @param argv Array of arguments (expects path to .cmmd file as argv[1])
 * @return int Exit code (0 = success, 1 = error)
 */
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Expected one argument for .cmmd file path.\n";
        std::cerr << "Usage: " << argv[0] << " <file.cmmd>\n";
        return 1;
    }

    std::ifstream commandFile(argv[1]);
    if (!commandFile) {
        std::cerr << "Error: Could not open file '" << argv[1] << "'\n";
        return 1;
    }

    MemoryManager manager;  // Create memory manager instance

    std::string commandLine;
    while (std::getline(commandFile, commandLine)) {
        manager.processCommand(commandLine);  // Process each line from file
    }

    return 0;
}
