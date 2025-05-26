#!/bin/bash

echo "Testing if reservations persist and display correctly..."

# Create a test that adds a reservation and immediately tries to display it
cat > test_display_issue.txt << EOF
1
Bob
Johnson
1234567890
25
01/06/2025
2

7
EOF

echo "Running test..."
./dental_reservation_system < test_display_issue.txt

# Clean up
rm -f test_display_issue.txt

echo "Display test completed!"
