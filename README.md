# Inventory Management System

## Overview

The **Inventory Management System** is a modular command-line application written in the C programming language. It was developed as part of **Project II: Team-Based Software Development** at Conestoga College.

The purpose of the application is to provide a simple and efficient way to manage inventory records. Users can add new products, update existing products, remove products, search for products, generate unique restock codes, and save or load inventory information from an ASCII text file.

The application was designed using a modular software architecture where each major feature is implemented in its own source and header files. This approach makes the project easier to understand, maintain, debug, and extend.

The system also demonstrates several important C programming concepts including:

- Modular programming
- Dynamic memory allocation
- Structures
- Pointers
- File handling
- Secure user input
- Random number generation
- Function decomposition
- Separation of concerns

---

# Features

The Inventory Management System includes the following functionality:

## Inventory Management

- Add new inventory items
- Update existing inventory items
- Remove inventory items
- Display all inventory items
- Automatically assign unique restock codes

## Search Module

- Search inventory by item name
- Case-sensitive string comparison
- Read-only search operation that does not modify stored data

## File Management

- Save inventory data to an ASCII text file
- Load inventory data from an ASCII text file
- Supports persistent storage between program executions

## Random Code Generation

Every newly created inventory item receives a randomly generated restock code such as:

```
RSK2773
```

Codes are generated using:

- rand()
- srand()
- time()

## User Interface

The application provides a simple menu-driven command-line interface that allows users to navigate every feature without needing technical knowledge.

## Memory Management

The inventory list grows dynamically using memory allocation functions, allowing the system to support an increasing number of inventory records without requiring a fixed array size.

---

# Project Structure

```
InventoryManagementSystem/

main.c
inventory.c
inventory.h
search.c
search.h
codegen.c
codegen.h
fileio.c
fileio.h
ui.c
ui.h
README.md
```

## File Descriptions

### main.c

The application's entry point.

Responsibilities:

- Starts the program
- Initializes required data
- Calls the menu interface
- Coordinates communication between modules
- Handles program shutdown

---

### inventory.c / inventory.h

Implements the inventory management module.

Responsibilities include:

- Adding items
- Updating items
- Removing items
- Listing inventory
- Managing dynamic memory
- Maintaining inventory records

---

### search.c / search.h

Responsible for searching inventory records.

Functions include:

- Search by item name
- Display matching inventory records
- Preserve original inventory data

---

### codegen.c / codegen.h

Handles random restock code generation.

Responsibilities:

- Generate unique inventory codes
- Seed the random number generator
- Format codes consistently

Example:

```
RSK2773
```

---

### fileio.c / fileio.h

Handles file input and output.

Responsibilities:

- Save inventory
- Load inventory
- Read ASCII text files
- Write ASCII text files
- Validate file operations

---

### ui.c / ui.h

Implements the user interface.

Responsibilities:

- Display menus
- Collect user input
- Validate selections
- Route requests to appropriate modules

---

# System Architecture

The project follows a modular architecture where each component has a single responsibility.

```
               +-----------+
               |   main.c  |
               +-----------+
                     |
      -------------------------------
      |      |      |      |        |
 Inventory Search FileIO CodeGen    UI
```

Each module communicates through clearly defined header files.

---

# Building the Project

## Windows (Visual Studio)

1. Open the project solution.
2. Build the solution.
3. Run the executable.

---

## Linux / macOS

Compile using GCC:

```bash
gcc -o inventory main.c inventory.c search.c fileio.c codegen.c ui.c
```

Run:

```bash
./inventory
```

---

# Running the Program

When the program starts, users are presented with the main menu.

```
-------------------------
Inventory Management Menu
-------------------------

1. Add Item
2. Update Item
3. Remove Item
4. List Items
5. Search Item
6. Save Inventory
7. Load Inventory
0. Exit

Enter choice:
```

---

# Example Usage

## Adding an Item

```
Enter item name:
Airpods

Enter quantity:
10

Enter price:
187

Item added successfully.

Generated Restock Code:
RSK2773
```

---

## Updating an Item

```
Enter item name:
Airpods

Enter new quantity:
15

Inventory updated successfully.
```

---

## Removing an Item

```
Enter item name:
Airpods

Item removed successfully.
```

---

## Searching

```
Enter item name:
Airpods

Item Found

Name: Airpods
Quantity: 15
Price: 187.00
Restock Code: RSK2773
```

---

## Listing Inventory

```
Inventory

--------------------------------------------

Airpods
Quantity : 15
Price    : 187.00
Code     : RSK2773

Keyboard
Quantity : 6
Price    : 45.00
Code     : RSK1987
```

---

## Saving Inventory

```
Enter filename:

inventory.txt

Inventory saved successfully.
```

---

## Loading Inventory

```
Enter filename:

inventory.txt

Inventory loaded successfully.
```

---

# Data Storage

Inventory records are stored in ASCII text files.

Each record contains:

- Item name
- Quantity
- Price
- Restock code

This allows users to preserve inventory information even after the application closes.

---

# Secure Input Handling

To improve program reliability and reduce the risk of memory-related errors, Microsoft's secure CRT library functions are used throughout the application.

Functions include:

- scanf_s()
- fscanf_s()
- fopen_s()

Example:

```c
scanf_s("%49s", item.name, sizeof(item.name));
```

Using these secure functions helps prevent:

- Buffer overflows
- Invalid string input
- File access errors

---

# Dynamic Memory Allocation

Instead of using a fixed-size array, the application allocates memory dynamically.

This enables the inventory to grow as additional products are added.

Memory is managed using standard C allocation functions and is released when the program exits to prevent memory leaks.

---

# Error Handling

The application validates user input and file operations whenever possible.

Examples include:

- Invalid menu selections
- File open failures
- Empty inventory
- Search misses
- Invalid numeric input

Appropriate error messages are displayed to guide the user.

---

# Testing

The system underwent functional and integration testing.

The following features were tested:

- Adding inventory items
- Updating inventory items
- Removing inventory items
- Listing inventory
- Searching inventory
- Saving data
- Loading data
- Dynamic memory allocation
- Secure input functions
- Random restock code generation
- Module integration
- File handling
- Float value accuracy

All tests were completed successfully, and the modules integrated correctly without functional conflicts.

---

# Technologies Used

- C Programming Language
- Visual Studio
- GCC
- Standard C Library
- Microsoft Secure CRT Functions
- CLion

---

# Collaborators

| Team Member | Responsibility |
|-------------|----------------|
| **Tobi Titiloye** | Inventory Module, Core Logic, System Integration, Testing |
| **Walter Wornu** | Search and Filter Module |
| **Bashiru Quadri** | Random Restock Code Generator |
| **Quazim Quadri** | File Input/Output Module |
| **Emmanuel Tally** | User Interface and Menu Navigation |

---

# Learning Outcomes

This project demonstrates practical knowledge of:

- Modular software development
- Team collaboration
- Source code organization
- Dynamic memory management
- File persistence
- Secure programming practices
- Command-line application development
- Software testing and integration
- Version control workflows
- Software engineering principles

---

# License

This project was created for educational purposes as part of **Project II: Team-Based Software Development** at **Conestoga College**.

It is intended for academic use and learning purposes only.
