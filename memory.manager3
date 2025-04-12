#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <vector>
#include <unordered_map>
#include <string>

const int MEMORY_SIZE = 65535;

/**
 * @brief Represents a memory block in the manager.
 */
struct Block {
    size_t start;
    size_t size;
    bool is_free;
    int id;

    Block(size_t start, size_t size, bool is_free, int id = -1)
        : start(start), size(size), is_free(is_free), id(id) {}
};

/**
 * @brief A simple buddy-like memory manager that supports
 *        insert, delete, update, find, and dump operations.
 */
class MemoryManager {
private:
    unsigned char memory[MEMORY_SIZE];                   // Raw memory buffer
    std::vector<Block> blocks;                           // List of memory blocks
    std::unordered_map<int, size_t> id_to_block;         // Maps ID to index in blocks
    int next_id;                                         // Unique ID counter

    size_t nextPowerOfTwo(size_t n);                     // Rounds size to next power of two
    int findBestFit(size_t size);                        // Finds best fitting free block
    void mergeBlocks();                                  // Merges adjacent free blocks

public:
    MemoryManager();

    void processCommand(const std::string& command);     // Executes a command
    void insert(size_t size, const std::string& data);   // Allocates memory and stores data
    void find(int id) const;                             // Prints data by ID
    void deleteBlock(int id);                            // Frees a block by ID
    void update(int id, const std::string& new_data);    // Updates a block's contents
    void dump() const;                                   // Dumps all memory blocks
};

#endif // MEMORY_MANAGER_H
