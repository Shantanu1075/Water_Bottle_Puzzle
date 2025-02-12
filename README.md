# Water Bottle Puzzle

## Overview
The **Water Bottle Puzzle** is a C++ implementation of the classic water jug problem, where players must measure a specific amount of water using bottles of different capacities. This project includes game logic, level management, and user data handling.

### Image Results Example

Result Image 1 

Result Image 2

Result Image 3
![Screenshot from 2025-02-12 09-17-55](https://github.com/user-attachments/assets/a9e35fce-7252-46bb-95dd-ebcfefa74d2a)

## Features
- **Game Mechanics**: Solve puzzles by transferring water between bottles.
- **Level Management**: Load and manage multiple levels dynamically.
- **User Data Handling**: Save and load user progress.
- **Simple UI**: Console-based user interface.

## Installation
### Prerequisites
- C++ Compiler (GCC, Clang, or MSVC)
- CMake (Optional, for build automation)

### Build and Run
1. Clone the repository:
   ```sh
   git clone <repository-url>
   cd water-bottle-puzzle
   ```
2. Compile the project using g++:
   ```sh
   g++ -o puzzle main.cpp Bottle.cpp userdata.cpp loadlevel.cpp
   ```
3. Run the executable:
   ```sh
   ./puzzle
   ```

## File Structure
```
water-bottle-puzzle/
│── src/
│   ├── main.cpp          # Main entry point
│   ├── Bottle.cpp        # Bottle class implementation
│   ├── userdata.cpp      # Handles user data
│   ├── loadlevel.cpp     # Level loading logic
│── include/
│   ├── Bottle.h          # Bottle class header
│   ├── userdata.h        # User data header
│   ├── loadlevel.h       # Level management header
│── assets/
│   ├── levels/           # Level configuration files
│── README.md             # Project documentation
│── Makefile              # Build automation (if applicable)
```

## How to Play
1. The game starts with a set of bottles with different capacities.
2. The goal is to measure a specific amount of water.
3. You can:
   - Fill a bottle to its maximum capacity.
   - Empty a bottle completely.
   - Pour water from one bottle to another.
4. Solve the puzzle in the least number of steps.
