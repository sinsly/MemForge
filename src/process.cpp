#include "process.h"
#include "memory.h"
#include <vector>
#include <mach/mach.h>
#include <libproc.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

bool process_t::attach(const std::string& process_name)
{
    pid_t pids[1024];
    int numberOfProcesses = proc_listpids(PROC_ALL_PIDS, 0, pids, sizeof(pids));
    for (int i = 0; i < numberOfProcesses; i++)
    {
        char name[PROC_PIDPATHINFO_MAXSIZE];
        if (proc_name(pids[i], name, sizeof(name)) > 0)
        {
            if (process_name == std::string(name))
            {
                pid = pids[i];
                return true;
            }
        }
    }
    return false;
}

std::vector<memory_region_t> process_t::memory_regions()
{
    std::vector<memory_region_t> regions;
    if (!pid) return regions;

    mach_port_t task;
    task_for_pid(mach_task_self(), pid, &task);

    mach_vm_address_t address = 0;
    while (true)
    {
        mach_vm_size_t size = 0;
        uint32_t depth = 0;
        vm_region_basic_info_data_64_t info;
        mach_msg_type_number_t infoCount = VM_REGION_BASIC_INFO_COUNT_64;
        mach_port_t objectName;

        kern_return_t kr = mach_vm_region(task, &address, &size, VM_REGION_BASIC_INFO_64,
                                          (vm_region_info_t)&info, &infoCount, &objectName);
        if (kr != KERN_SUCCESS) break;

        regions.push_back({ (std::uintptr_t)address, (size_t)size });
        address += size;
    }

    return regions;
}

std::vector<uint8_t> process_t::read(std::uintptr_t address, size_t size)
{
    memory_t mem;
    return mem.read(address, size);
}
