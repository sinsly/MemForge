#pragma once
#include <string>
#include <vector>
#include <cstdint>

struct memory_region_t
{
    std::uintptr_t address;
    size_t size;
};

class process_t
{
public:
    process_t() = default;
    bool attach(const std::string& process_name);
    std::vector<memory_region_t> memory_regions();
    std::vector<uint8_t> read(std::uintptr_t address, size_t size);

private:
    pid_t pid = 0;
};
