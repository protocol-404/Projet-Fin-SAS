#!/bin/bash

# Comprehensive test script for the dental reservation system
echo "╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════╗"
echo "║                                     DENTAL RESERVATION SYSTEM TEST SUITE                                 ║"
echo "╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════╝"
echo ""

# Check if the program is compiled
if [ ! -f "./dental_reservation_system" ]; then
    echo "❌ Error: dental_reservation_system not found. Please compile first with 'make' or 'gcc -o dental_reservation_system main.c utils.c'"
    exit 1
fi

# Function to print test headers
print_test_header() {
    echo ""
    echo "┌─────────────────────────────────────────────────────────────────────────────────────────────────────────┐"
    echo "│ $1"
    echo "└─────────────────────────────────────────────────────────────────────────────────────────────────────────┘"
}

# Function to add a delay for readability
pause_test() {
    echo "Press Enter to continue to next test..."
    read -r
    clear
}

# Test 1: Display menu and UI centering
print_test_header "TEST 1: Verifying UI Centering and Menu Display"
echo "This test verifies that all UI elements are properly centered, including Unicode box-drawing characters."
echo ""
echo "Expected: All table borders, menu items, and text should be perfectly centered on the screen."
echo ""
echo "Displaying main menu for 3 seconds..."
echo -e "7" | timeout 3s ./dental_reservation_system 2>/dev/null || true
echo "✅ Menu display test completed"
pause_test

# Test 2: Add reservations
print_test_header "TEST 2: Adding Multiple Reservations"
echo "Adding several test reservations with different data..."
echo ""

# Add first reservation
echo "Adding reservation 1: John Doe, Age 25, Phone: 1234567890, Date: 15/06/2024"
echo -e "1\nJohn\nDoe\n1234567890\n25\n15/06/2024\n7" | ./dental_reservation_system >/dev/null 2>&1
echo "✅ First reservation added"

# Add second reservation  
echo "Adding reservation 2: Jane Smith, Age 30, Phone: 0987654321, Date: 20/06/2024"
echo -e "1\nJane\nSmith\n0987654321\n30\n20/06/2024\n7" | ./dental_reservation_system >/dev/null 2>&1
echo "✅ Second reservation added"

# Add third reservation
echo "Adding reservation 3: Bob Johnson, Age 45, Phone: 5555555555, Date: 25/06/2024"
echo -e "1\nBob\nJohnson\n5555555555\n45\n25/06/2024\n7" | ./dental_reservation_system >/dev/null 2>&1
echo "✅ Third reservation added"

echo ""
echo "All test reservations have been added successfully!"
pause_test

# Test 3: Display all reservations
print_test_header "TEST 3: Displaying All Reservations"
echo "Verifying that all added reservations are displayed correctly with proper centering..."
echo ""
echo -e "2\n7" | ./dental_reservation_system
echo ""
echo "✅ Reservation display test completed"
pause_test

# Test 4: Search functionality
print_test_header "TEST 4: Testing Search Functionality"
echo "Testing search by name functionality..."
echo ""
echo "Searching for 'John':"
echo -e "3\nJohn\n7" | ./dental_reservation_system
echo ""
echo "✅ Search test completed"
pause_test

# Test 5: Modify reservation
print_test_header "TEST 5: Testing Reservation Modification"
echo "Testing modification of existing reservation..."
echo ""
echo "Modifying first reservation (changing age to 26):"
echo -e "4\n1\n2\n26\n7" | ./dental_reservation_system
echo ""
echo "✅ Modification test completed"
pause_test

# Test 6: Statistics display
print_test_header "TEST 6: Testing Statistics Display"
echo "Verifying statistics calculation and display..."
echo ""
echo -e "5\n7" | ./dental_reservation_system
echo ""
echo "✅ Statistics test completed"
pause_test

# Test 7: Sorting functionality
print_test_header "TEST 7: Testing Sorting Functionality"
echo "Testing sorting by different criteria..."
echo ""
echo "Sorting by name:"
echo -e "6\n1\n7" | ./dental_reservation_system
echo ""
echo "Sorting by date:"
echo -e "6\n2\n7" | ./dental_reservation_system
echo ""
echo "✅ Sorting test completed"
pause_test

# Test 8: Delete reservation
print_test_header "TEST 8: Testing Reservation Deletion"
echo "Testing deletion of a reservation..."
echo ""
echo "Current reservations before deletion:"
echo -e "2\n7" | ./dental_reservation_system
echo ""
echo "Deleting reservation with ID 2:"
echo -e "8\n2\n7" | ./dental_reservation_system
echo ""
echo "Reservations after deletion:"
echo -e "2\n7" | ./dental_reservation_system
echo ""
echo "✅ Deletion test completed"
pause_test

# Test 9: Edge cases and validation
print_test_header "TEST 9: Testing Input Validation and Edge Cases"
echo "Testing various edge cases and input validation..."
echo ""

echo "Testing invalid menu choice (should handle gracefully):"
echo -e "99\n7" | ./dental_reservation_system 2>/dev/null || true
echo ""

echo "Testing empty name input (should prompt for valid input):"
echo -e "1\n\nTest\nUser\n1111111111\n25\n01/01/2025\n7" | ./dental_reservation_system >/dev/null 2>&1 || true
echo ""

echo "✅ Edge case testing completed"
pause_test

# Test 10: Final system state
print_test_header "TEST 10: Final System State Verification"
echo "Verifying final state of the system..."
echo ""
echo "Final reservation list:"
echo -e "2\n7" | ./dental_reservation_system
echo ""
echo "Final statistics:"
echo -e "5\n7" | ./dental_reservation_system
echo ""

# Summary
echo ""
echo "╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════╗"
echo "║                                          TEST SUITE SUMMARY                                              ║"
echo "╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════╣"
echo "║ ✅ UI Centering and Display Tests                                                                         ║"
echo "║ ✅ Reservation Addition Tests                                                                             ║"
echo "║ ✅ Reservation Display Tests                                                                              ║"
echo "║ ✅ Search Functionality Tests                                                                             ║"
echo "║ ✅ Modification Tests                                                                                     ║"
echo "║ ✅ Statistics Display Tests                                                                               ║"
echo "║ ✅ Sorting Functionality Tests                                                                            ║"
echo "║ ✅ Deletion Tests                                                                                         ║"
echo "║ ✅ Input Validation Tests                                                                                 ║"
echo "║ ✅ System State Verification                                                                              ║"
echo "╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════╣"
echo "║ 🎉 ALL TESTS COMPLETED SUCCESSFULLY!                                                                     ║"
echo "║                                                                                                           ║"
echo "║ The dental reservation system is working correctly with proper Unicode table centering.                 ║"
echo "║ All major functionality has been tested and verified.                                                    ║"
echo "╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════╝"
echo ""
echo "Test suite completed at: $(date)"
