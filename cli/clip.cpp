#include "cli.h"
#include <iostream>

void cli_t::run(int argc, char** argv)
{
    if (argc < 3)
    {
        print_usage();
        return;
    }

    std::string process_name = argv[1];
    std::string pattern = argv[2];

    process_t process;
    if (!process.attach(process_name))
    {
        std::cout << "Failed to attach to process.\n";
        return;
    }

    scanner_t scanner(&process);
    auto results = scanner.pattern_scan(pattern);

    for (auto& addr : results)
    {
        utils::print_hex(addr);
    }
}

void cli_t::print_usage()
{
    std::cout << "Usage: MachScan <process_name> <pattern>\n";
    std::cout << "Pattern format: 'AA BB ?? CC'\n";
}
