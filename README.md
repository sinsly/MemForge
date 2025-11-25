# MemForge

MemForge is a macOS-focused memory inspection and reverse‑engineering toolkit, inspired by tools such as Cheat Engine but built specifically for the Mach kernel environment. Its purpose is to provide developers, researchers, and security analysts with a clean and modern foundation for working with process memory, pattern scanning, and low-level macOS internals.

This project is still in an early development state. The core memory reading, writing, and pattern scanning systems are established, but many features such as a full GUI, trainers, debugger modules, and scripting support are planned for future updates. The current codebase is intended to be a reliable, modular starting point for anyone interested in macOS reverse‑engineering utilities.

## Project Layout

```
MemForge/
│
├── CMakeLists.txt
├── README.md
├── .gitignore
│
├── src/
│   ├── memory.cpp
│   ├── scanner.cpp
│   ├── process.cpp
│   ├── logger.cpp
│   └── utils.cpp
│
├── include/
│   ├── memory.h
│   ├── scanner.h
│   ├── process.h
│   ├── logger.h
│   └── utils.h
│
├── cli/
│   ├── main.cpp
│   └── commands.cpp
│
├── core/
│   ├── mach_utils.h
│   ├── mach_utils.cpp
│   ├── patterns.h
│   └── patterns.cpp
│
├── examples/
│   ├── example_scan.cpp
│   └── example_attach.cpp
│
└── tests/
    ├── test_memory.cpp
    ├── test_scanner.cpp
    └── test_process.cpp
```

## Current Features

- Process attachment via Mach APIs
- Safe memory read/write interface
- Pattern scanning (AoB scan)
- Basic CLI for development testing
- Organized modular layout for future expansion

## Planned Features

- Full GUI built with ImGui
- Real‑time memory viewers and editors
- Breakpoints, hooks, and debugger primitives
- Scripting system for cheat/trainer creation
- Plugin architecture for tool expansion
