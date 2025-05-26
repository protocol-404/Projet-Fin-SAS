#include "statistics.h"
#include "ui.h"

// Native average calculation
float calculateAverage(int total, int count) {
    if (count == 0) return 0.0;
    return (float)total / (float)count;
}

void displayAgeStatistics() {
    int totalAge = 0;
    int ageGroups[3] = {0}; // 0-18, 19-35, 36+

    int i = 0;
    while (i < reservationCount) {
        totalAge += reservations[i].age;

        if (reservations[i].age <= 18) {
            ageGroups[0]++;
        } else if (reservations[i].age <= 35) {
            ageGroups[1]++;
        } else {
            ageGroups[2]++;
        }
        i++;
    }

    float averageAge = calculateAverage(totalAge, reservationCount);

    printCentered("╔════════════════════════════════╗", CYAN);
    printCentered("║         Age Statistics         ║", CYAN);
    printCentered("╚════════════════════════════════╝", CYAN);
    printCentered("", "");
    
    centerText("");
    printf("Average Age: %.2f years\n", averageAge);
    printCentered("", "");
    printCentered("Age Groups Distribution:", WHITE);
    centerText("");
    printf("• 0-18 years:  %d patients\n", ageGroups[0]);
    centerText("");
    printf("• 19-35 years: %d patients\n", ageGroups[1]);
    centerText("");
    printf("• 36+ years:   %d patients\n", ageGroups[2]);
}

void displayStatusStatistics() {
    int validCount = 0, canceledCount = 0, postponedCount = 0, treatedCount = 0;

    int i = 0;
    while (i < reservationCount) {
        if (stringCompare(reservations[i].status, "validated") == 0) {
            validCount++;
        } else if (stringCompare(reservations[i].status, "canceled") == 0) {
            canceledCount++;
        } else if (stringCompare(reservations[i].status, "postponed") == 0) {
            postponedCount++;
        } else if (stringCompare(reservations[i].status, "treated") == 0) {
            treatedCount++;
        }
        i++;
    }

    printCentered("", "");
    printCentered("╔════════════════════════════════╗", MAGENTA);
    printCentered("║       Status Statistics        ║", MAGENTA);
    printCentered("╚════════════════════════════════╝", MAGENTA);
    printCentered("", "");
    
    centerText("");
    printf("Total Reservations: %d\n", reservationCount);
    printCentered("", "");
    printCentered("Status Breakdown:", WHITE);
    centerText("");
    printf("• Validated: %d (%.1f%%)\n", validCount, 
           calculateAverage(validCount * 100, reservationCount));
    centerText("");
    printf("• Canceled:  %d (%.1f%%)\n", canceledCount, 
           calculateAverage(canceledCount * 100, reservationCount));
    centerText("");
    printf("• Postponed: %d (%.1f%%)\n", postponedCount, 
           calculateAverage(postponedCount * 100, reservationCount));
    centerText("");
    printf("• Treated:   %d (%.1f%%)\n", treatedCount, 
           calculateAverage(treatedCount * 100, reservationCount));
}

void statisticData() {
    clearScreen();
    displayLogo();
    printCentered("╔══════════════════════════════════════╗", BLUE);
    printCentered("║            System Statistics         ║", BLUE);
    printCentered("╚══════════════════════════════════════╝", BLUE);
    printCentered("", "");

    if (reservationCount == 0) {
        printCentered("No reservations available for statistics.", RED);
        printCentered("Please add some reservations first.", YELLOW);
        printf("\n");
        waitForEnter();
        return;
    } 

    displayAgeStatistics();
    displayStatusStatistics();

    printf("\n");
    waitForEnter();
}
