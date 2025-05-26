#!/bin/bash

echo "Testing input validation error messages..."

# Create a test input file with invalid data followed by valid data
cat > test_validation.txt << EOF
1
John123
John
Doe456
Doe
12345
1234567890
5
150
25
32/13/2023
15/01/2025
7
EOF

# Run the program with the test input
./dental_reservation_system < test_validation.txt

# Clean up
rm -f test_validation.txt

echo "Validation test completed!"
