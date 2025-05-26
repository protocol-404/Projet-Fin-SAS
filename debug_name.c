#include <stdio.h>
#include <string.h>

// Simple test to debug the name validation
int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int isValidName(const char* name) {
    printf("Debug: Checking name '%s'\n", name);
    printf("Debug: Name length: %d\n", stringLength(name));
    
    if (stringLength(name) == 0 || stringLength(name) >= 50) {
        printf("Debug: Name length is invalid\n");
        return 0;
    }
    
    int i = 0;
    while (name[i] != '\0') {
        char c = name[i];
        printf("Debug: Checking character '%c' (ASCII: %d)\n", c, c);
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
            printf("Debug: Invalid character found: '%c'\n", c);
            return 0;
        }
        i++;
    }
    
    printf("Debug: Name is valid\n");
    return 1;
}

int main() {
    char name[100];
    printf("Enter a name to test: ");
    if (fgets(name, sizeof(name), stdin) != NULL) {
        // Remove newline if present
        int len = stringLength(name);
        if (len > 0 && name[len - 1] == '\n') {
            name[len - 1] = '\0';
        }
        
        printf("Result: %s\n", isValidName(name) ? "VALID" : "INVALID");
    }
    return 0;
}
