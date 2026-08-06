cmake_minimum_required(VERSION 3.20)

project(InventoryManagementSystem C)

set(CMAKE_C_STANDARD 11)

add_executable(InventoryManagementSystem
        main.c
        inventory.c
        search.c
        ui.c
        codegen.c
        fileio.c
)