// Q1.Use nested for loops to print a grid of emojis representing a 5x5 Instagram post feed, where each cell shows a 📷 symbol.

#include <stdio.h>
#include <locale.h>

int main() {
    // Set the locale to utilize UTF-8 formatting for emojis
    setlocale(LC_ALL, "");

    // Outer loop for the 5 rows
    for (int i = 0; i < 5; i++) {
        // Inner loop for the 5 columns
        for (int j = 0; j < 5; j++) {
            printf("📷 ");
        }
        // Print a newline after each row is complete
        printf("\n");
    }

    return 0;
}
// Breakdown of the Code:
// setlocale(LC_ALL, "");: Tells the program to use your environment's default system locale settings, which allows standard printf to output wide UTF-8 emoji strings successfully.

// Outer Loop (int i = 0; i < 5; i++): Controls the row creation, triggering exactly 5 times.

// Inner Loop (int j = 0; j < 5; j++): Controls the columns, printing a camera emoji (📷 ) 5 times sequentially on the same line.

// printf("\n");: Executes immediately after the inner loop finishes to drop down to the next line before the next row begins.

// Q2.Build a right-angled triangle pattern using nested loops, where each row displays increasing numbers starting from 1, similar to how a leaderboard on a gaming app shows rank numbers.

#include <stdio.h>

int main() {
    int rows = 5;

    // Outer loop for the number of rows
    for (int i = 1; i <= rows; i++) {
        // Inner loop to print numbers starting from 1 up to the current row number
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}
//OUTPUT
// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4 
// 1 2 3 4 5


// Q3.Create a pattern that prints a pyramid of stars (*) with 6 rows, centered like the loading animation you see on BookMyShow when a page is loading.<br><br><em><strong>Hint:</strong> Use spaces to align the stars in the center for each row.</em>

#include <stdio.h>

int main() {
    int rows = 6;

    // Outer loop for the 6 rows
    for (int i = 1; i <= rows; i++) {
        
        // Inner loop 1: Prints the spaces to center-align the row
        for (int j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        
        // Inner loop 2: Prints the stars with a trailing space
        for (int k = 1; k <= i; k++) {
            printf("* ");
        }
        
        // Move to the next line after each row is printed
        printf("\n");
    }

    return 0;
}
//      * 
//     * * 
//    * * * 
//   * * * * 
//  * * * * * 
// * * * * * *

// Q4.Write code using nested loops to print a pattern of alternating 0s and 1s in a grid, like the checkered background seen in some Spotify playlist covers (e.g., for a 4x4 grid, alternate 0 and 1 in each cell).

#include <stdio.h>

int main() {
    int grid_size = 4;

    // Outer loop for rows
    for (int i = 0; i < grid_size; i++) {
        // Inner loop for columns
        for (int j = 0; j < grid_size; j++) {
            // Check if the sum of row and column index is even or odd
            if ((i + j) % 2 == 0) {
                printf("0 ");
            } else {
                printf("1 ");
            }
        }
        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}
// 0 1 0 1 
// 1 0 1 0 
// 0 1 0 1 
// 1 0 1 0


// Q5.Modify your pyramid pattern code to accept the number of rows as user input, so the user can set the height of the pyramid before printing.

#include <stdio.h>

int main() {
    int rows;

    // Accept dynamic user input for the number of rows
    printf("Enter the number of rows for the pyramid: ");
    scanf("%d", &rows);

    // Outer loop for the rows
    for (int i = 1; i <= rows; i++) {
        
        // Inner loop 1: Prints the spaces to center-align the row
        for (int j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        
        // Inner loop 2: Prints the stars with a trailing space
        for (int k = 1; k <= i; k++) {
            printf("* ");
        }
        
        // Move to the next line after each row is printed
        printf("\n");
    }

    return 0;
}