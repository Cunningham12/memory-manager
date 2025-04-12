#include "memory_manager.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <iomanip> // for hex formatting

/**
 * @brief Constructor initializes the memory manager with one large free block.
 */
MemoryManager::MemoryManager() : next_id(0) {
    std::memset(memory, 0, MEMORY_SIZE);
    blocks.emplace_back(0, MEMORY_SIZE, true);
}

/**
 * @brief Returns the next power of two greater than or equal to n.
 */
size_t MemoryManager::nextPowerOfTwo(size_t n) {
    size_t power = 1;
    while (power < n) {
        power <<= 1;
    }
    return power;
}

/**
 * @brief Finds the index of the smallest fitting free block.
 */
int MemoryManager::findBestFit(size_t size) {
    int best_index = -1;
    size_t best_size = MEMORY_SIZE + 1;

    for (size_t i = 0; i < blocks.size(); ++i) {
        if (blocks[i].is_free && blocks[i].size >= size && blocks[i].size < best_size) {
            best_index = static_cast<int>(i);
            best_size = blocks[i].size;
        }
    }
    return best_index;
}

/**
 * @brief Merges adjacent free blocks (basic buddy behavior).
 */
void MemoryManager::mergeBlocks() {
    for (size_t i = 0; i < blocks.size() - 1;) {
        if (blocks[i].is_free && blocks[i + 1].is_free) {
            blocks[i].size += blocks[i + 1].size;
            blocks.erase(blocks.begin() + i + 1);
        } else {
            ++i;
        }
    }
}

/**
 * @brief Parses and executes a command from the input file.
 */
void MemoryManager::processCommand(const std::string& command) 
    std::istringstream iss(command);
    std::string op;
    iss >> op;

    if (op == "INSERT") {
        size_t size;
        std::string data;
        iss >> size;
        std::getline(iss, data);
        if (!data.empty() && data[0] == ' ') data = data.substr(1);
        insert(size, data);
    } else if (op == "READ") {
        int id;
        iss >> id;
        find(id);
    } else if (op == "DELETE") {
        int id;
        iss >> id;
        deleteBlock(id);
    } else if (op == "UPDATE") 
        int id;
        std::string new_data;
        iss >> id;
        std::getline
