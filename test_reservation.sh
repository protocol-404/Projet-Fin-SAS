#!/bin/bash

# Test script for dental reservation system
echo "Testing the dental reservation system..."

# Create a test input file
cat > test_input.txt << EOF
1
John
Doe
1234567890
25
25/12/2024
2
7
EOF

# Run the program with the test input
./dental_reservation_system < test_input.txt

# Clean up
rm -f test_input.txt

echo "Test completed!"
