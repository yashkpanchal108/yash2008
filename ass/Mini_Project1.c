/*1.
Create a console-based app called Music Listening Logger that allows users to enter the number of minutes they listened to music each day for a week and stores this data in an array.
2.
Add a menu-driven interface to your Music Listening Logger so users can choose to log new listening minutes, view their weekly summary, or exit the app.<br><br><em><strong>Hint:</strong> Use a loop to repeatedly show the menu until the user selects exit.</em>
3.
Implement file handling in your Music Listening Logger so that when the user logs their daily listening minutes, the data is saved to a file named music_log.txt for persistence.
4.
Add a feature to your app that reads the saved music_log.txt file and generates a weekly report showing the total, average, and highest listening minutes in the week.
5.
Refactor your Music Listening Logger to allow users to reset their weekly data by clearing the array and deleting the contents of music_log.txt.<br><br><em><strong>Constraint:</strong> Make sure the reset option is available in the menu and asks for confirmation before deleting data.</em>*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DAYS_IN_WEEK 7

// Function Declarations
void logMinutes(int minutes[], const char *days[]);
void viewSummary(const int minutes[], const char *days[]);
void generateWeeklyReport();
void resetData(int minutes[]);
void loadData(int minutes[]);

int main() {
    int minutes[DAYS_IN_WEEK] = {0};
    const char *days[DAYS_IN_WEEK] = {
        "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
    };
    int choice;

    // Load existing data from the file at the start of the program
    loadData(minutes);

    do {
        printf("\n===================================\n");
        printf("      MUSIC LISTENING LOGGER       \n");
        printf("===================================\n");
        printf("1. Log Daily Listening Minutes\n");
        printf("2. View Current Weekly Summary\n");
        printf("3. Generate Weekly Report (From File)\n");
        printf("4. Reset Weekly Data\n");
        printf("5. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice (1-5): ");
        
        // Handle non-integer inputs safely
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                logMinutes(minutes, days);
                break;
            case 2:
                viewSummary(minutes, days);
                break;
            case 3:
                generateWeeklyReport();
                break;
            case 4:
                resetData(minutes);
                break;
            case 5:
                printf("Exiting the application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose an option between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

// 1 & 3. Log data into the array and automatically save it to music_log.txt
void logMinutes(int minutes[], const char *days[]) {
    FILE *file = fopen("music_log.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    printf("\n--- Log New Listening Minutes ---\n");
    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        printf("Enter minutes for %s: ", days[i]);
        while (scanf("%d", &minutes[i]) != 1 || minutes[i] < 0) {
            printf("Invalid input. Enter a positive number for %s: ", days[i]);
            while (getchar() != '\n'); 
        }
        // Write each day's log to the file immediately
        fprintf(file, "%s: %d\n", days[i], minutes[i]);
    }
    fclose(file);
    printf("\nData successfully logged to array and saved to 'music_log.txt'!\n");
}

// 2. View the basic real-time array summary
void viewSummary(const int minutes[], const char *days[]) {
    printf("\n--- Current Weekly Summary ---\n");
    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        printf("%s: %d mins\n", days[i], minutes[i]);
    }
}

// 4. Read from music_log.txt and calculate total, average, and highest statistics
void generateWeeklyReport() {
    FILE *file = fopen("music_log.txt", "r");
    if (file == NULL) {
        printf("\nNo logs found. Please log daily minutes first (Option 1).\n");
        return;
    }

    char day[20];
    int mins;
    int total = 0;
    int highest = -1;
    int count = 0;

    // Parsing "Day: Minutes" structure line by line from file
    while (fscanf(file, "%19[^:]: %d\n", day, &mins) == 2) {
        total += mins;
        if (mins > highest) {
            highest = mins;
        }
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("\nThe log file is currently empty.\n");
        return;
    }

    double average = (double)total / count;

    printf("\n===================================\n");
    printf("          WEEKLY REPORT            \n");
    printf("===================================\n");
    printf("Total Listening Time : %d minutes\n", total);
    printf("Average Daily Time   : %.2f minutes\n", average);
    printf("Highest Single Day   : %d minutes\n", highest);
    printf("===================================\n");
}

// 5. Clear array and delete file contents upon confirmation constraint
void resetData(int minutes[]) {
    char confirm;
    printf("\n[WARNING] Are you sure you want to reset all weekly data? (y/n): ");
    scanf(" %c", &confirm); // Space before %c skips trailing newline characters

    if (confirm == 'y' || confirm == 'Y') {
        // Clear array
        for (int i = 0; i < DAYS_IN_WEEK; i++) {
            minutes[i] = 0;
        }

        // Open file in write mode and immediately close it to wipe data clean/truncate
        FILE *file = fopen("music_log.txt", "w");
        if (file != NULL) {
            fclose(file);
        }

        printf("Weekly data has been reset and 'music_log.txt' cleared.\n");
    } else {
        printf("Reset operation cancelled.\n");
    }
}

// Optional Helper: Prefills the array if data is already present when starting the application
void loadData(int minutes[]) {
    FILE *file = fopen("music_log.txt", "r");
    if (file == NULL) {
        return; // File doesn't exist yet, standard default values apply
    }

    char day[20];
    int mins;
    int i = 0;

    while (fscanf(file, "%19[^:]: %d\n", day, &mins) == 2 && i < DAYS_IN_WEEK) {
        minutes[i] = mins;
        i++;
    }
    fclose(file);
}