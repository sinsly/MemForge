cmake_minimum_required(VERSION 3.16)
project(MachScan VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

file(GLOB_RECURSE SRC_FILES
    src/*.cpp
    core/*.cpp
    cli/*.cpp
)

add_executable(MachScan ${SRC_FILES})

target_link_libraries(MachScan
    "-framework CoreFoundation"
    "-framework ApplicationServices"
    "-framework IOKit"
)

enable_testing()

file(GLOB_RECURSE TEST_FILES
    tests/*.cpp
)

add_executable(MachScanTests ${TEST_FILES})
target_link_libraries(MachScanTests
    "-framework CoreFoundation"
    "-framework ApplicationServices"
    "-framework IOKit"
)
add_test(NAME AllTests COMMAND MachScanTests)
