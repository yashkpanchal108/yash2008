// Q1.Declare a 1D array called dailySteps with 7 elements to store your step count for each day of the week, assign sample values, and print each value using a loop.

#include <stdio.h>

int main() {
    // 1. Declare a 1D array called dailySteps with 7 elements
    int dailySteps[7];

    // 2. Assign sample step counts for each day of the week
    dailySteps[0] = 6500;  // Monday
    dailySteps[1] = 8200;  // Tuesday
    dailySteps[2] = 5000;  // Wednesday
    dailySteps[3] = 10000; // Thursday
    dailySteps[4] = 7400;  // Friday
    dailySteps[5] = 11200; // Saturday
    dailySteps[6] = 4500;  // Sunday

    // 3. Print each value using a loop
    printf("Daily Step Counts for the Week:\n");
    for (int i = 0; i < 7; i++) {
        printf("Day %d: %d steps\n", i + 1, dailySteps[i]);
    }

    return 0;
}

// Q2.Create a 2D array called playlistRatings to store ratings for 3 Spotify playlists over 5 days (rows = playlists, columns = days). Fill it with sample numbers and print the ratings for the second playlist.

int main() {
    // 1. Create a 2D array called playlistRatings 
    // Rows = 3 playlists, Columns = 5 days
    int playlistRatings[3][5] = {
        {4, 5, 4, 3, 5}, // Playlist 1 ratings over 5 days
        {5, 4, 5, 5, 4}, // Playlist 2 ratings over 5 days (Index 1)
        {3, 3, 4, 4, 3}  // Playlist 3 ratings over 5 days
    };

    // 2. Print the ratings for the second playlist
    // The second playlist is at row index 1 (since C arrays are 0-indexed)
    printf("Ratings for the second Spotify playlist over 5 days:\n");
    for (int j = 0; j < 5; j++) {
        printf("Day %d: %d stars\n", j + 1, playlistRatings[1][j]);
    }

    return 0;
}

// Q3.Build a function that takes a 1D array of 7 integers representing your daily Zomato order amounts and calculates the average spend for the week.<br><br><em><strong>Hint:</strong> Use a loop to sum the values, then divide by the array length.</em>

#include <stdio.h>

// Function declaration/prototype
float calculateAverageSpend(int orders[], int length);

int main() {
    // 1. Declare a 1D array of 7 integers representing daily Zomato orders
    int dailyZomatoOrders[7] = {250, 420, 0, 180, 550, 600, 120};

    // 2. Call the function and pass the array along with its length
    float average = calculateAverageSpend(dailyZomatoOrders, 7);

    // 3. Print the calculated average formatted to 2 decimal places
    printf("Your average Zomato spend for the week is: %.2f INR\n", average);

    return 0;
}

// Function definition
float calculateAverageSpend(int orders[], int length) {
    int totalSum = 0;

    // Use a loop to sum the values
    for (int i = 0; i < length; i++) {
        totalSum += orders[i];
    }

    // Divide the sum by the array length
    // (float) is used for type casting to ensure decimal precision in division
    return (float)totalSum / length;
}

// Q4.Given a 2D array called cricketScores where each row represents an IPL match and columns represent runs scored by each team, write code to print the highest score from each match.

#include <stdio.h>

int main() {
    // 1. Create a 2D array called cricketScores
    // Rows = Matches (e.g., 4 matches)
    // Columns = Runs scored by each team (2 teams per match)
    int cricketScores[4][2] = {
        {185, 182}, // Match 1: Team A scored 185, Team B scored 182
        {210, 215}, // Match 2: Team A scored 210, Team B scored 215
        {160, 145}, // Match 3: Team A scored 160, Team B scored 145
        {245, 250}  // Match 4: Team A scored 245, Team B scored 250
    };

    int totalMatches = 4;

    printf("Highest score from each IPL match:\n");
    printf("----------------------------------\n");

    // 2. Loop through each match (row)
    for (int i = 0; i < totalMatches; i++) {
        // Assume the first team's score is the highest initially
        int highestScore = cricketScores[i][0];

        // Compare with the second team's score
        if (cricketScores[i][1] > highestScore) {
            highestScore = cricketScores[i][1];
        }

        // Print the result for the current match
        printf("Match %d Highest Score: %d\n", i + 1, highestScore);
    }

    return 0;
}