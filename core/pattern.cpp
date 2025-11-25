#include "pattern.h"
#include <sstream>

std::vector<int> pattern_t::parse(const std::string& pattern)
{
    std::istringstream ss(pattern);
    std::vector<int> bytes;
    std::string byte;

    while (ss >> byte)
    {
        if (byte == "??") bytes.push_back(-1);
        else bytes.push_back(std::stoi(byte, nullptr, 16));
    }

    return bytes;
}
