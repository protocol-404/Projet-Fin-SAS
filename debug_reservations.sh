#!/bin/bash

echo "Testing with debug info..."

# First, let's add some debug prints to see what's happening
# Create a simple test program that shows the reservation count
cat > debug_reservation_count.c << 'EOF'
#include "types.h"
#include "utils.h"

extern struct Reservation reservations[MAX_RESERVATIONS];
extern int reservationCount;

int main() {
    printf("Current reservation count: %d\n", reservationCount);
    printf("Maximum reservations: %d\n", MAX_RESERVATIONS);
    
    // Add a test reservation
    reservationCount = 1;
    strcpy(reservations[0].firstName, "Test");
    strcpy(reservations[0].lastName, "User");
    strcpy(reservations[0].phone, "1234567890");
    reservations[0].age = 25;
    strcpy(reservations[0].status, "validated");
    reservations[0].date.day = 15;
    reservations[0].date.month = 1;
    reservations[0].date.year = 2025;
    reservations[0].id = 1;
    
    printf("After adding test reservation, count: %d\n", reservationCount);
    printf("Test reservation name: %s %s\n", reservations[0].firstName, reservations[0].lastName);
    
    return 0;
}
EOF

# Try to compile it
if gcc -I. -o debug_count debug_reservation_count.c reservation_manager.o utils.o 2>/dev/null; then
    echo "Running debug test..."
    ./debug_count
    rm -f debug_count
else
    echo "Debug compilation failed, trying different approach..."
fi

# Clean up
rm -f debug_reservation_count.c

echo "Debug test completed!"
