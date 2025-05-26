#!/bin/bash

echo "Testing complete reservation flow with all fixes..."

# Create a comprehensive test
cat > test_final_flow.txt << EOF
1
John
Doe
1234567890
25
25/12/2024

2

7
EOF

echo "Testing: Add reservation -> Display all -> Exit"
./dental_reservation_system < test_final_flow.txt

# Clean up
rm -f test_final_flow.txt

echo "Final flow test completed!"
