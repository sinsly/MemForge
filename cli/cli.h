#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include "scanner.h"
#include "process.h"
#include "utils.h"

class cli_t
{
public:
    void run(int argc, char** argv);

private:
    void print_usage();
};
