#include "utils.h"
#include <sys/ioctl.h>
#include <unistd.h>

// Get terminal width for centering
int getTerminalWidth() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col > 0 ? w.ws_col : 80; // Default to 80 if can't detect
}

// Calculate padding for centering text
void centerText(const char* text) {
    int termWidth = getTerminalWidth();
    int textLen = getVisualWidth(text);
    int padding = (termWidth - textLen) / 2;
    
    if (padding > 0) {
        int i = 0;
        while (i < padding) {
            printf(" ");
            i++;
        }
    }
}

// Print centered text with color
void printCentered(const char* text, const char* color) {
    centerText(text);
    printf("%s%s%s\n", color, text, RESET);
}

// Print centered prompt without newline (for input prompts)
void printCenteredPrompt(const char* prompt) {
    centerText(prompt);
    printf("%s", prompt);
    fflush(stdout);
}

// Native string length implementation (counts bytes)
int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Visual string width implementation (handles Unicode box-drawing characters)
int getVisualWidth(const char* str) {
    int visualWidth = 0;
    int i = 0;
    
    while (str[i] != '\0') {
        unsigned char c = (unsigned char)str[i];
        
        if (c < 0x80) {
            // ASCII character (1 byte, 1 visual width)
            visualWidth++;
            i++;
        } else if ((c & 0xE0) == 0xC0) {
            // 2-byte UTF-8 character
            visualWidth++;
            i += 2;
        } else if ((c & 0xF0) == 0xE0) {
            // 3-byte UTF-8 character (most box-drawing characters)
            visualWidth++;
            i += 3;
        } else if ((c & 0xF8) == 0xF0) {
            // 4-byte UTF-8 character
            visualWidth++;
            i += 4;
        } else {
            // Invalid UTF-8, treat as 1 byte
            visualWidth++;
            i++;
        }
    }
    
    return visualWidth;
}

// Native string comparison implementation
int stringCompare(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

// Native case-insensitive string comparison
int stringCompareIgnoreCase(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        char c1 = str1[i];
        char c2 = str2[i];
        
        // Convert to lowercase manually
        if (c1 >= 'A' && c1 <= 'Z') {
            c1 = c1 + ('a' - 'A');
        }
        if (c2 >= 'A' && c2 <= 'Z') {
            c2 = c2 + ('a' - 'A');
        }
        
        if (c1 != c2) {
            return c1 - c2;
        }
        i++;
    }
    
    char c1 = str1[i];
    char c2 = str2[i];
    if (c1 >= 'A' && c1 <= 'Z') {
        c1 = c1 + ('a' - 'A');
    }
    if (c2 >= 'A' && c2 <= 'Z') {
        c2 = c2 + ('a' - 'A');
    }
    
    return c1 - c2;
}

// Native string copy implementation
void stringCopy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Check if year is leap year
int isLeapYear(int year) {
    if (year % 4 != 0) return 0;
    if (year % 100 != 0) return 1;
    if (year % 400 != 0) return 0;
    return 1;
}

// Get number of days in a month
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    
    return daysInMonth[month - 1];
}

// Validate date with proper logic
int isValidDate(int day, int month, int year) {
    // Check year range
    if (year < 2024 || year > 2035) {
        return 0;
    }
    
    // Check month range
    if (month < 1 || month > 12) {
        return 0;
    }
    
    // Check day range
    if (day < 1 || day > getDaysInMonth(month, year)) {
        return 0;
    }
    
    return 1;
}

// Validate name (only letters and spaces)
int isValidName(const char* name) {
    if (stringLength(name) == 0 || stringLength(name) >= MAX_NAME_LENGTH) {
        return 0;
    }
    
    int i = 0;
    while (name[i] != '\0') {
        char c = name[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
            return 0;
        }
        i++;
    }
    
    return 1;
}

// Validate phone number (only digits and common phone characters)
int isValidPhone(const char* phone) {
    int len = stringLength(phone);
    if (len < 8 || len > 14) {
        return 0;
    }
    
    int i = 0;
    while (phone[i] != '\0') {
        char c = phone[i];
        if (!((c >= '0' && c <= '9') || c == '+' || c == '-' || c == ' ' || c == '(' || c == ')')) {
            return 0;
        }
        i++;
    }
    
    return 1;
}

// Clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Get validated integer input with EOF handling
int getValidatedInteger(const char* prompt, int min, int max) {
    int value;
    int valid = 0;
    int scanResult;
    
    while (!valid) {
        printCenteredPrompt(prompt);
        
        scanResult = scanf("%d", &value);
        
        if (scanResult == EOF) {
            // Handle EOF (e.g., piped input or Ctrl+D)
            printf("\n");
            centerText("Input ended unexpectedly. Exiting program.");
            exit(1);
        } else if (scanResult == 1) {
            if (value >= min && value <= max) {
                clearInputBuffer(); // Clear the newline after successful integer read
                valid = 1;
            } else {
                printCentered("", "");
                char errorMsg[100];
                sprintf(errorMsg, "Please enter a value between %d and %d.", min, max);
                printCentered(errorMsg, RED);
                clearInputBuffer();
            }
        } else {
            // Invalid input (non-numeric)
            printCentered("", "");
            printCentered("Please enter a valid number.", RED);
            clearInputBuffer();
        }
    }
    
    return value;
}

// Get validated string input with EOF handling
int getValidatedString(const char* prompt, char* buffer, int maxLength) {
    printCenteredPrompt(prompt);
    
    if (fgets(buffer, maxLength, stdin) == NULL) {
        // Handle EOF
        printf("\n");
        centerText("Input ended unexpectedly. Exiting program.");
        exit(1);
    }
    
    // Remove newline character if present
    int len = stringLength(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
    
    return 1;
}

// Safe wait for enter with EOF handling
void safeWaitForEnter() {
    printCenteredPrompt("Press Enter to continue...");
    
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("\n");
        centerText("Input ended unexpectedly. Exiting program.");
        exit(1);
    }
}
