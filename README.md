# Dental Appointment Reservation System

A comprehensive dental clinic management system written in C for managing patient appointments and reservations.

## 📁 Project Structure

The project has been organized into modular files for better maintainability and readability:

```
Projet-Fin-SAS/
├── main.c                  # Entry point of the application
├── types.h                 # Data structures and constants
├── ui.h                    # User interface function declarations
├── ui.c                    # User interface implementations
├── reservation_manager.h   # Reservation management declarations
├── reservation_manager.c   # Core reservation functionality
├── search_sort.h          # Search and sorting declarations
├── search_sort.c          # Search and sorting implementations
├── statistics.h           # Statistics function declarations
├── statistics.c           # Statistics and data analysis
├── Makefile              # Build configuration
└── README.md             # This file
```

## 🏗️ Architecture Overview

### Core Components:

1. **types.h** - Central definitions
   - Data structures (`Date`, `Reservation`)
   - Constants and color codes
   - Global variable declarations

2. **ui.c/ui.h** - User Interface Layer
   - Screen management (`clearScreen`, `displayLogo`)
   - Menu display (`displayMenu`)
   - Data presentation (`displayAll`, `displayReservation`)

3. **reservation_manager.c/h** - Business Logic
   - Adding new reservations (`addReservation`)
   - Updating and deleting reservations (`changeStatus`)
   - Global data storage management

4. **search_sort.c/h** - Data Operations
   - Search functionality (`searchReservation`)
   - Sorting algorithms (`sortingByName`, `sortingByStatus`)
   - Sort menu management (`sortingData`)

5. **statistics.c/h** - Analytics
   - Statistical calculations (`statisticData`)
   - Age group analysis
   - Status distribution reporting

6. **main.c** - Application Controller
   - Main program loop
   - Menu navigation
   - Function coordination

## 🚀 Building and Running

### Using Makefile (Recommended):

```bash
# Build the program
make

# Build and run
make run

# Clean build files
make clean

# Build with debug symbols
make debug

# Show help
make help
```

### Manual Compilation:

```bash
gcc -Wall -Wextra -std=c99 -o dental_reservation_system main.c ui.c reservation_manager.c search_sort.c statistics.c
./dental_reservation_system
```

## 🎯 Features

- **Reservation Management**: Add, update, delete appointments
- **Search Functionality**: Find reservations by ID or last name
- **Sorting Options**: Sort by name or status
- **Statistics**: Age demographics and status distribution
- **User-Friendly Interface**: Colored output and clear menus

## 📊 Status Types

- `validated` - Confirmed appointments
- `canceled` - Cancelled appointments
- `postponed` - Rescheduled appointments
- `treated` - Completed treatments

## 🔧 Technical Details

- **Language**: C (C99 standard)
- **Compiler**: GCC with warnings enabled
- **Memory Management**: Static arrays (configurable size)
- **Platform**: Cross-platform (Linux/Windows)
- **Dependencies**: Standard C library only

## 📋 Code Organization Benefits

1. **Modularity**: Each file has a specific responsibility
2. **Maintainability**: Easy to locate and modify functionality
3. **Reusability**: Functions can be reused across modules
4. **Testability**: Individual components can be tested separately
5. **Scalability**: Easy to add new features without affecting existing code

## 🛠️ Development Guidelines

- Each `.h` file contains function declarations for its corresponding `.c` file
- Global variables are declared in `types.h` and defined in `reservation_manager.c`
- UI functions are separated from business logic
- Color constants are centralized in `types.h`
- Consistent naming conventions across all files

## 📈 Future Enhancements

- Database integration
- File-based data persistence
- Advanced search filters
- Appointment scheduling validation
- Report generation
- Multi-language support
