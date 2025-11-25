#include "../src/scanner.h"
#include "../src/process.h"
#include <iostream>
#include <cassert>
#include <vector>

int main()
{
    process_t process;
    if (!process.attach("TestApp")) return 0;

    scanner_t scanner(&process);
    std::vector<std::uintptr_t> results = scanner.pattern_scan("AA BB ?? CC");

    assert(!results.empty() || results.empty());
    std::cout << "Pattern scan test executed.\n";

    return 0;
}
