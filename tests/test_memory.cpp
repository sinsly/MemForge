#include "../src/memory.h"
#include <iostream>
#include <vector>
#include <cassert>

int main()
{
    memory_t mem;
    std::uintptr_t addr = reinterpret_cast<std::uintptr_t>(new uint8_t[4]{1,2,3,4});
    auto data = mem.read(addr, 4);

    assert(data.size() == 4);
    assert(data[0] == 1 && data[1] == 2 && data[2] == 3 && data[3] == 4);

    std::cout << "Memory read test passed.\n";
    delete[] reinterpret_cast<uint8_t*>(addr);
    return 0;
}
