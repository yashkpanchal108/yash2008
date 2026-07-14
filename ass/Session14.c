
// Q1.Given the following buggy code meant to calculate the total price of a Zomato order, identify and fix the syntax and runtime errors:<br><br>let items = ["Burger", "Pizza", "Fries"];<br>let prices = [120, 250, 90];<br>let total = 0;<br>for (i = 0; i < items.length; i++) {<br> total =+ prices[i]<br>}<br>console.log("Total price is: " + total);<br><br><em><strong>Hint:</strong> Watch for assignment and loop variable issues.</em>

#include <stdio.h>

int main() {
    // Array of menu items (array of string literals)
    char *items[] = {"Burger", "Pizza", "Fries"};
    
    // Array of prices corresponding to the items
    int prices[] = {120, 250, 90};
    
    // Calculate the total number of elements in the array
    int length = sizeof(prices) / sizeof(prices[0]);
    
    int total = 0;

    // Fixed: Declared 'i' as an integer and corrected '=+' to '+='
    for (int i = 0; i < length; i++) {
        total += prices[i];
    }

    // Print the final accumulated total
    printf("Total price is: %d\n", total);

    return 0;
}

// Q2.Rewrite the following code to improve its indentation and add comments explaining each step, so that a beginner can understand what it does:<br><br>function isEven(num){if(num%2==0){return true;}else{return false;}}

#include <stdio.h>
#include <stdbool.h> // Required in C to use 'bool', 'true', and 'false'

// This function checks if a given number is even or odd.
// It takes one integer parameter 'num' and returns a boolean value.
bool isEven(int num) {
    
    // The '%' (modulo) operator calculates the remainder of a division.
    // If a number divided by 2 has a remainder of 0, it means it is an even number.
    if (num % 2 == 0) {
        // If the condition is true, return true (the number is even)
        return true; 
    } 
    // If the remainder is anything else (like 1), the number is odd
    else {
        // Return false (the number is not even)
        return false;
    }
}

int main() {
    // Example usage:
    int testNumber = 4;
    
    if (isEven(testNumber)) {
        printf("%d is even.\n", testNumber);
    } else {
        printf("%d is odd.\n", testNumber);
    }
    
    return 0;
}

// Q3.Write a function formatFollowersCount(count) that takes a number and returns a formatted string like Instagram: 1500 as '1.5K', 1200000 as '1.2M', and numbers below 1000 as-is. Add clear comments and use proper indentation.

#include <stdio.h>

// Function to format follower counts like Instagram
// Parameters:
//   - count: The number of followers (long long to handle very large values)
//   - result: The destination character array where the formatted string will be stored
void formatFollowersCount(long long count, char *result) {
    
    // Case 1: Numbers 1,000,000 (1M) and above
    if (count >= 1000000) {
        // If it divides perfectly into millions, don't show trailing decimals (e.g., 2.0M -> 2M)
        if (count % 1000000 == 0) {
            sprintf(result, "%lldM", count / 1000000);
        } else {
            // Otherwise, display with 1 decimal place
            sprintf(result, "%.1fM", (double)count / 1000000.0);
        }
    }
    // Case 2: Numbers between 1,000 (1K) and 999,999
    else if (count >= 1000) {
        // If it divides perfectly into thousands, don't show trailing decimals (e.g., 5.0K -> 5K)
        if (count % 1000 == 0) {
            sprintf(result, "%lldK", count / 1000);
        } else {
            // Otherwise, display with 1 decimal place
            sprintf(result, "%.1fK", (double)count / 1000.0);
        }
    }
    // Case 3: Numbers below 1,000 are displayed exactly as they are
    else {
        sprintf(result, "%lld", count);
    }
}

int main() {
    // Buffer string to store the final formatted output text
    char formattedText[50];

    // Test Case 1: Under 1000
    formatFollowersCount(735, formattedText);
    printf("Followers: %s\n", formattedText); // Output: 735

    // Test Case 2: In thousands (K)
    formatFollowersCount(1500, formattedText);
    printf("Followers: %s\n", formattedText); // Output: 1.5K

    // Test Case 3: In millions (M)
    formatFollowersCount(1200000, formattedText);
    printf("Followers: %s\n", formattedText); // Output: 1.2M

    // Test Case 4: Perfect clean division
    formatFollowersCount(5000, formattedText);
    printf("Followers: %s\n", formattedText); // Output: 5K

    return 0;
}

// Q4.You are given a piece of JavaScript code that should print all even numbers from 1 to 10, but it doesn't work as expected:<br><br>for (let i = 1; i <= 10; i++) {<br> if (i % 2 = 0) {<br> console.log(i)<br> }<br>}<br><br>Find and fix the error, then rewrite the code with good indentation and at least one comment explaining the logic.

#include <stdio.h>

int main() {
    // Loop through numbers from 1 to 10
    for (int i = 1; i <= 10; i++) {
        
        // The '%' (modulo) operator finds the remainder of division by 2.
        // If the remainder equals 0, the number is even.
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}
