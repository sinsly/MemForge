#pragma once
#include <vector>
#include <string>
#include <cstdint>
#include "process.h"

class scanner_t
{
public:
    explicit scanner_t(process_t* proc);
    std::vector<std::uintptr_t> pattern_scan(const std::string& pattern);

private:
    process_t* process;
};
