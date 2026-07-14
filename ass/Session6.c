// Q1.Write a program that prints the numbers from 10 down to 1 using a for loop, similar to a countdown timer.
#include <stdio.h>

int main() {
    printf("--- Countdown Timer ---\n");

    // Loop starts at 10 and decrements by 1 each time until it reaches 1
    for (int i = 10; i >= 1; i--) {
        printf("%d\n", i);
    }

    printf("Liftoff! 🚀\n");

    return 0;
}
// How it works:
// Initialization (int i = 10): The loop control variable i starts at 10.

// Condition (i >= 1): The loop keeps running as long as i is greater than 
// or equal to 1.

// Decrement (i--): Every time the loop prints a number, it subtracts 1 from
// i to count backward.

// Q2.Create a menu-driven console app that lets the user: 1) View your 
// favorite 3 IPL teams, 2) Add a new team, 3) Exit. Use a while loop to
//  keep showing the menu until the user chooses Exit.<br><br><em><strong>
// Hint:</strong> Use input() (or Scanner in Java) to get the user's choice 
// each time.</em>

#include <stdio.h>
#include <string.h>

#define MAX_TEAMS 20
#define MAX_NAME_LENGTH 50

int main() {
    // 2D Array initialized with the 3 favorite IPL teams
    char iplTeams[MAX_TEAMS][MAX_NAME_LENGTH] = {
        "Mumbai Indians",
        "Chennai Super Kings",
        "Royal Challengers Bengaluru"
    };
    
    int teamCount = 3; // Keep track of the current number of teams
    int choice;

    // Infinite while loop to keep showing the menu until option 3 is selected
    while (1) {
        printf("\n--- IPL Team Manager ---\n");
        printf("1. View favorite IPL teams\n");
        printf("2. Add a new team\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        
        // Read the user's choice
        scanf("%d", &choice);
        
        // Clear the input buffer to prevent issues with subsequent inputs
        while (getchar() != '\n'); 

        if (choice == 1) {
            printf("\nYour Favorite IPL Teams:\n");
            for (int i = 0; i < teamCount; i++) {
                printf("%d. %s\n", i + 1, iplTeams[i]);
            }
        } 
        else if (choice == 2) {
            // Check if the array has reached its maximum limit
            if (teamCount < MAX_TEAMS) {
                printf("\nEnter the name of the new IPL team: ");
                
                // Read the team name including spaces using fgets
                fgets(iplTeams[teamCount], MAX_NAME_LENGTH, stdin);
                
                // Remove the trailing newline character added by fgets
                iplTeams[teamCount][strcspn(iplTeams[teamCount], "\n")] = '\0';
                
                printf("'%s' has been added successfully!\n", iplTeams[teamCount]);
                teamCount++; // Increment the total count of teams
            } else {
                printf("\nTeam limit reached! Cannot add more teams.\n");
            }
        } 
        else if (choice == 3) {
            printf("\nExiting the app. Thank you!\n");
            break; // Breaks out of the while loop to end the program
        } 
        else {
            printf("\nInvalid choice! Please select a valid option (1, 2, or 3).\n");
        }
    }

    return 0;
}

// Highlights of this C implementation:
// while(1) and break: Creates a continuous loop that runs indefinitely
//  until break is explicitly called when the user chooses option 3.

// Input Buffer Cleansing: The while (getchar() != '\n'); line cleans up the
// terminal input buffer after scanf. This is crucial in C so that the 
// subsequent string inputs (fgets) don't accidentally consume leftover 
// newline characters.

// fgets(): Used instead of scanf for reading the team name because it 
// allows spaces in inputs (e.g., "Kolkata Knight Riders").


// Q3.Build a 'Guess the Song' game like Spotify — the program randomly 
// picks a song name from a list and asks the user to guess it.
// Use a do-while loop so the user can keep guessing until they 
// get it right.<br><br><em><strong>Constraint:</strong> Use at least 3 
// song names of your choice.</em>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// For cross-platform case-insensitive string comparison
#ifdef _WIN32
    #define strcasecmp stricmp
#endif

int main() {
    // 1. Seed the random number generator using current time
    srand(time(NULL));

    // 2. Define a list of at least 3 song names
    char songList[5][50] = {
        "Blinding Lights",
        "Shape of You",
        "Stay",
        "Perfect",
        "Dynamite"
    };

    // 3. Randomly pick a song index from 0 to 4
    int randomIndex = rand() % 5;
    char *targetSong = songList[randomIndex];

    char userGuess[50];
    int attempts = 0;

    printf("--- 🎵 Spotify 'Guess the Song' Game 🎵 ---\n");
    printf("I have picked a popular song from my playlist. Can you guess it?\n");
    printf("(Hint: Popular tracks by Weeknd, Ed Sheeran, BTS, etc.)\n\n");

    // 4. Use a do-while loop to keep asking until they guess correctly
    do {
        printf("Enter your guess: ");
        // Read the full line of text (including spaces if the song has multiple words)
        fgets(userGuess, sizeof(userGuess), stdin);
        
        // Remove the trailing newline character added by fgets
        userGuess[strcspn(userGuess, "\n")] = '\0';
        
        attempts++;

        // 5. Check if the guess matches the target song (case-insensitive)
        if (strcasecmp(userGuess, targetSong) == 0) {
            printf("\n🎉 Correct! You guessed it right in %d attempts!", attempts);
            printf("\nThe song was: %s\n", targetSong);
            break; // Exit the loop safely
        } else {
            printf("❌ Wrong guess! Try again.\n\n");
        }

    } while (1); // Loops indefinitely until the correct answer triggers the 'break'

    return 0;
}
// Key Highlights of this Code:
// do-while Loop: This exit-controlled structure guarantees that the user 
// is prompted to guess at least once, and continues looping indefinitely 
// (while(1)) until they match the correct song, which hits the break 
// statement.

// rand() % 5: Dynamically chooses a random index from our array of 5 tracks 
// every time you launch the game.

// fgets(): Unlike standard scanf, fgets allows you to input song titles 
// that contain spaces (e.g., "Blinding Lights") cleanly.

// strcasecmp(): This handles strings seamlessly regardless of 
// capitalization, so guessing "perfect", "PERFECT", or "Perfect" will all 
// be counted as correct answers.

// Q4.Explain with your own example the difference between entry-controlled 
// and exit-controlled loops by writing a short code snippet for each 
// (for/while vs do-while) and describing what happens if the loop condition
//  is false at the start.

// 1. Entry-Controlled Loops (while / for)
// In an entry-controlled loop, the condition is evaluated before executing the loop body. If the condition is false right at the beginning, the body is completely skipped.

#include <stdio.h>

int main() {
    int availableTickets = 0; // The condition starts as FALSE (not > 0)

    // Checking the entry condition first
    while (availableTickets > 0) {
        printf("Boarding passenger...\n");
        availableTickets--;
    }

    printf("Entry Loop over.\n");
    return 0;
}

// 2. Exit-Controlled Loops (do-while)
// In an exit-controlled loop, the loop body is executed first, and the condition is evaluated at the end of the iteration. This guarantees that the loop runs at least once, no matter what.

#include <stdio.h>

int main() {
    int availableTickets = 0; // The condition will eventually be FALSE

    // Executing the body first before checking the condition
    do {
        printf("Passenger boards the bus and looks for a ticket...\n");
        availableTickets--; 
    } while (availableTickets > 0); // Condition is checked here

    printf("Exit Loop over.\n");
    return 0;
}