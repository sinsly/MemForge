#include "memory.h"
#include <mach/mach.h>
#include <vector>

std::vector<uint8_t> memory_t::read(std::uintptr_t address, size_t size)
{
    std::vector<uint8_t> buffer(size);
    mach_port_t task = mach_task_self();
    vm_size_t outSize;
    vm_read_overwrite(task, address, size, (vm_address_t)buffer.data(), &outSize);
    return buffer;
}

bool memory_t::write(std::uintptr_t address, const std::vector<uint8_t>& data)
{
    mach_port_t task = mach_task_self();
    kern_return_t kr = vm_write(task, address, (vm_offset_t)data.data(), (mach_msg_type_number_t)data.size());
    return kr == KERN_SUCCESS;
}
