#!/bin/bash

echo "🧪 COMPREHENSIVE SYSTEM TEST - All Functionality"
echo "================================================="

# Test 1: Complete reservation workflow
echo -e "\n✅ Test 1: Complete Reservation Workflow"
cat > comprehensive_test.txt << EOF
1
Alice
Johnson
1234567890
28
15/06/2025

2

1
Bob
Smith
0987654321
35
20/07/2025

2

3
1
1
4

4
1
2

5
1
3

6

7
EOF

echo "Testing complete workflow: Add -> Display -> Add -> Display -> Update -> Search -> Sort -> Statistics -> Exit"
./dental_reservation_system < comprehensive_test.txt

# Test 2: Input validation
echo -e "\n✅ Test 2: Input Validation"
cat > validation_test.txt << EOF
1
John123
John
Doe456
Doe
123
1234567890
5
150
25
32/13/2023
25/12/2024

7
EOF

echo "Testing input validation with invalid and valid inputs"
./dental_reservation_system < validation_test.txt

# Clean up
rm -f comprehensive_test.txt validation_test.txt

echo -e "\n🎉 COMPREHENSIVE TEST COMPLETED!"
echo "============================================"
