#!/bin/bash

echo "Testing only the display function..."

# Test just option 2 first
cat > test_only_display.txt << EOF
2
7
EOF

echo "Testing option 2 (Display All) when no reservations exist:"
./dental_reservation_system < test_only_display.txt

echo -e "\n" "=" "Now testing with a reservation first:"

# Test adding a reservation then displaying
cat > test_add_then_display.txt << EOF
1
Alice
Smith
0987654321
30
15/01/2025
2

7
EOF

echo "Testing add reservation then display:"
./dental_reservation_system < test_add_then_display.txt

# Clean up
rm -f test_only_display.txt test_add_then_display.txt

echo "Display function test completed!"
