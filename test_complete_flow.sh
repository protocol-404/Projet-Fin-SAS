#!/bin/bash

echo "Testing reservation creation and display..."

# Create a test input file with reservation creation and display
cat > test_complete_flow.txt << EOF
1
Alice
Smith
0987654321
30
15/01/2025
2
7
EOF

# Run the program with the test input
./dental_reservation_system < test_complete_flow.txt

# Clean up
rm -f test_complete_flow.txt

echo "Complete flow test finished!"
