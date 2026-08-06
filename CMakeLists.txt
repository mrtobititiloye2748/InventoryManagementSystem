cmake_minimum_required(VERSION 3.16)

project(InventoryManagementSystem C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(InventoryManagementSystem
        main.c
        inventory.c
        fileio.c
        search.c
        codegen.c
)