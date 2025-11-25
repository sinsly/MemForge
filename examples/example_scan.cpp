#include "../src/scanner.h"
#include "../src/process.h"
#include "../src/utils.h"
#include <iostream>

int main()
{
    std::string process_name = "TestApp";
    std::string pattern = "DE AD BE EF ?? 12 34";

    process_t process;
    if (!process.attach(process_name))
    {
        std::cout << "Failed to attach to process.\n";
        return 1;
    }

    scanner_t scanner(&process);
    auto results = scanner.pattern_scan(pattern);

    std::cout << "Found addresses:\n";
    for (auto& addr : results)
    {
        utils::print_hex(addr);
    }

    return 0;
}
