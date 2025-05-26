#ifndef UTILS_H
#define UTILS_H

#include "types.h"

// Terminal utilities
int getTerminalWidth();
void centerText(const char* text);
void printCentered(const char* text, const char* color);
void printCenteredPrompt(const char* prompt);

// String utilities (native implementations)
int stringLength(const char* str);
int getVisualWidth(const char* str);
int stringCompare(const char* str1, const char* str2);
int stringCompareIgnoreCase(const char* str1, const char* str2);
void stringCopy(char* dest, const char* src);
int isValidDate(int day, int month, int year);
int isLeapYear(int year);
int getDaysInMonth(int month, int year);

// Input validation
int isValidName(const char* name);
int isValidPhone(const char* phone);
void clearInputBuffer();
int getValidatedInteger(const char* prompt, int min, int max);

// Input validation helpers
int getValidatedString(const char* prompt, char* buffer, int maxLength);
void safeWaitForEnter();

#endif
