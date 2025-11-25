#include "scanner.h"
#include "memory.h"
#include <sstream>

scanner_t::scanner_t(process_t* proc)
{
    process = proc;
}

std::vector<std::uintptr_t> scanner_t::pattern_scan(const std::string& pattern)
{
    std::vector<std::uintptr_t> results;
    auto regions = process->memory_regions();

    for (auto& region : regions)
    {
        auto data = process->read(region.address, region.size);
        if (data.empty()) continue;

        std::istringstream ss(pattern);
        std::vector<int> bytes;
        std::string byte;

        while (ss >> byte)
        {
            if (byte == "??") bytes.push_back(-1);
            else bytes.push_back(std::stoi(byte, nullptr, 16));
        }

        for (size_t i = 0; i < data.size(); i++)
        {
            bool match = true;
            for (size_t j = 0; j < bytes.size(); j++)
            {
                if (bytes[j] != -1 && data[i + j] != bytes[j])
                {
                    match = false;
                    break;
                }
            }
            if (match) results.push_back(region.address + i);
        }
    }

    return results;
}
