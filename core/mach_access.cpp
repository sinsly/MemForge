#include "mach_access.h"

bool mach_access_t::get_task(pid_t pid)
{
    return task_for_pid(mach_task_self(), pid, &task) == KERN_SUCCESS;
}

std::vector<uint8_t> mach_access_t::read(std::uintptr_t address, size_t size)
{
    std::vector<uint8_t> buffer(size);
    vm_size_t out;
    vm_read_overwrite(task, address, size, (vm_address_t)buffer.data(), &out);
    return buffer;
}
