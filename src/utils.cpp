#include "utils.h"

namespace utils
{
    void print_hex(std::uintptr_t address)
    {
        std::cout << "0x" << std::hex << std::uppercase << address << std::endl;
    }
}
