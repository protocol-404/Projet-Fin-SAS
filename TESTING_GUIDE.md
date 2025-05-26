# Testing Guide for Dental Reservation System

## Overview
This document provides a comprehensive guide for testing the dental reservation system, particularly focusing on the Unicode table centering fix that was implemented.

## Test Scripts Available

### 1. `demo_test.sh` - Quick Demonstration
A streamlined demonstration script that shows the key features and verifies the table centering fix.

**Usage:**
```bash
./demo_test.sh
```

**What it tests:**
- Main menu display with centered Unicode tables
- Sample reservation additions
- Reservation listing display
- Statistics display
- Verification that all box-drawing characters are properly centered

### 2. `test_system.sh` - Comprehensive Test Suite
A full test suite that covers all system functionality with interactive testing.

**Usage:**
```bash
./test_system.sh
```

**What it tests:**
- UI centering and menu display
- Adding multiple reservations
- Displaying all reservations
- Search functionality
- Reservation modification
- Statistics display
- Sorting functionality
- Reservation deletion
- Input validation and edge cases
- Final system state verification

## The Table Centering Fix

### Problem Solved
The original issue was that Unicode box-drawing characters (╔, ╗, ╚, ╝, ║, ═, ╠, ╣) were not properly centered because the `stringLength()` function counted bytes instead of visual character width. Since these Unicode characters are 3-byte UTF-8 sequences but display as single-width characters, the centering calculations were incorrect.

### Solution Implemented
1. **New Function Added**: `getVisualWidth()` in `utils.c`
   - Properly counts visual character width for UTF-8 strings
   - Handles Unicode box-drawing characters correctly

2. **Updated Centering Logic**: Modified `centerText()` function
   - Uses `getVisualWidth()` instead of `stringLength()`
   - Ensures proper centering for all text and table elements

3. **Header Updates**: Added function declaration in `utils.h`

### Verification
The fix ensures that:
- ✅ Menu borders (╔════...════╗) are perfectly centered
- ✅ Content lines (║ text ║) are properly aligned
- ✅ Middle borders (╠════...════╣) are centered
- ✅ Bottom borders (╚════...════╝) are aligned
- ✅ All UI elements maintain consistent centering

## How to Compile and Run

### Compilation
```bash
# Using Makefile (recommended)
make clean && make

# Or manual compilation
gcc -Wall -Wextra -std=c99 -o dental_reservation_system main.c ui.c reservation_manager.c search_sort.c statistics.c utils.c
```

### Running the System
```bash
# Interactive mode
./dental_reservation_system

# Quick demonstration
./demo_test.sh

# Full test suite
./test_system.sh
```

## Expected Output
All table elements should be perfectly centered on the screen, with Unicode box-drawing characters aligned with the text content. The output should show:

```
                                              ╔════════════════════════════════════════════╗
                                              ║     Dental Appointment Reservation System  ║
                                              ╠════════════════════════════════════════════╣
                                              ║  1. Add Reservation                        ║
                                              ║  2. Display All Reservations               ║
                                              ║  3. Update or Delete Reservation           ║
                                              ║  4. Search Reservation                     ║
                                              ║  5. Display Sorting Options                ║
                                              ║  6. Display Statistics                     ║
                                              ║  7. Exit                                   ║
                                              ╚════════════════════════════════════════════╝
```

## Testing Notes
- The test scripts handle both successful operations and edge cases
- Input validation is tested to ensure robust error handling
- All major system functionality is verified through automated testing
- The centering fix works in both interactive and piped input modes

## Troubleshooting
If you encounter compilation errors:
1. Ensure all source files are present
2. Use the provided Makefile
3. Check that you have a C99-compatible compiler
4. Verify that all header files are properly included

If centering appears incorrect:
1. Ensure your terminal supports UTF-8 encoding
2. Verify that the terminal width is sufficient (at least 120 characters recommended)
3. Check that the `getVisualWidth()` function is being used in `centerText()`
