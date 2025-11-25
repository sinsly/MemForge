#include "scanner.h"
#include "process.h"
#include "memory.h"
#include "utils.h"

int main(int argc, char** argv)
{
    if (argc < 3) return 0;
    std::string process_name = argv[1];
    std::string pattern = argv[2];

    process_t process;
    if (!process.attach(process_name)) return 0;

    scanner_t scanner(&process);
    auto results = scanner.pattern_scan(pattern);

    for (auto& addr : results)
    {
        utils::print_hex(addr);
    }

    return 0;
}
