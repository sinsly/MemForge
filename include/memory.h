#pragma once
#include <vector>
#include <cstdint>

class memory_t
{
public:
    memory_t() = default;
    std::vector<uint8_t> read(std::uintptr_t address, size_t size);
    bool write(std::uintptr_t address, const std::vector<uint8_t>& data);
};
