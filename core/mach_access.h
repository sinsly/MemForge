#pragma once
#include <vector>
#include <cstdint>
#include <mach/mach.h>

class mach_access_t
{
public:
    mach_access_t() = default;
    bool get_task(pid_t pid);
    std::vector<uint8_t> read(std::uintptr_t address, size_t size);

private:
    mach_port_t task = MACH_PORT_NULL;
};
