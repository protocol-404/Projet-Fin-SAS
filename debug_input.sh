#!/bin/bash

echo "Debugging input processing..."

# Create a test that shows exactly what's being read
cat > debug_input_test.c << 'EOF'
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[100];
    printf("Reading first line...\n");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        printf("Read: '");
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == '\n') {
                printf("\\n");
            } else if (buffer[i] == '\r') {
                printf("\\r");
            } else if (buffer[i] < 32) {
                printf("\\%d", buffer[i]);
            } else {
                printf("%c", buffer[i]);
            }
        }
        printf("'\n");
        printf("Length: %d\n", (int)strlen(buffer));
    }
    return 0;
}
EOF

# Compile and test
gcc -o debug_input debug_input_test.c

# Test with "1"
echo "Testing with '1':"
echo "1" | ./debug_input

echo -e "\nTesting with 'Bob':"
echo "Bob" | ./debug_input

# Clean up
rm -f debug_input_test.c debug_input

echo "Debug test completed!"
