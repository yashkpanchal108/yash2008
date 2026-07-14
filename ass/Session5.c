// Q1.Create a simple IPL Fan Bot that takes your favorite IPL team name as 
// input and uses if-else-if statements to print a unique cheer message for
//  each team (e.g., 'Go Mumbai Indians!', 'Chennai Super Kings for the win!').
//  If the team is not recognized, print 'Team not found!'

#include <stdio.h>
#include <string.h>

void iplFanBot(char team[]) {
    // Check and match the team names using an if-else-if ladder
    if (strcmp(team, "Mumbai Indians") == 0 || strcmp(team, "MI") == 0) {
        printf("Go Mumbai Indians! One Family! 💙\n");
    } 
    else if (strcmp(team, "Chennai Super Kings") == 0 || strcmp(team, "CSK") == 0) {
        printf("Chennai Super Kings for the win! Whistle Podu! 💛\n");
    } 
    else if (strcmp(team, "Royal Challengers Bengaluru") == 0 || strcmp(team, "RCB") == 0) {
        printf("Ee Sala Cup Namde! Play Bold, RCB! ❤️\n");
    } 
    else if (strcmp(team, "Kolkata Knight Riders") == 0 || strcmp(team, "KKR") == 0) {
        printf("Korbo Lorbo Jeetbo Re! Ami KKR! 💜\n");
    } 
    else {
        // If the team name doesn't match any of the above
        printf("Team not found!\n");
    }
}

int main() {
    char userTeam[50];

    // Welcome message and user input
    printf("Welcome to IPL Fan Bot!\n");
    printf("Enter your favorite IPL Team: ");
    
    // Reads string input including spaces
    scanf(" %[^\n]s", userTeam); 

    // Run the bot function
    iplFanBot(userTeam);

    return 0;
}
// Key Technical Points:
// strcmp(str1, str2) == 0: In C, you cannot directly compare strings 
// using ==. The strcmp() function compares two strings character by
//  character and returns 0 if they match perfectly.

// %[^\n]s: This special scanner code ensures that if you type a team 
// name with spaces (like "Mumbai Indians"), it reads the full line
//  instead of cutting off at the first space.

// Q2.Build a Zomato-style food suggestion tool: take the user's preferred
//  meal time ('breakfast', 'lunch', 'dinner', or 'snack') and use a
//  switch-case statement to suggest a popular dish for that time. 
//  If the input doesn't match any meal, suggest 'Try some fruits!'.

int main() {
    char mealTime;

    // Display options to the user
    printf("--- Zomato-style Food Suggestion Tool ---\n");
    printf("b - Breakfast\n");
    printf("l - Lunch\n");
    printf("d - Dinner\n");
    printf("s - Snack\n");
    printf("Enter your preferred meal time shortcut: ");
    scanf(" %c", &mealTime);

    // Switch case to suggest food based on the input
    switch (mealTime) {
        case 'b':
        case 'B':
            printf("Suggestion: How about some hot Chole Bhature or a Masala Dosa?\n");
            break;
            
        case 'l':
        case 'L':
            printf("Suggestion: A grand Veg/Non-Veg Thali or Hyderabadi Biryani sounds perfect!\n");
            break;
            
        case 'd':
        case 'D':
            printf("Suggestion: Treat yourself to Butter Naan with Paneer Butter Masala or Tandoori Chicken!\n");
            break;
            
        case 's':
        case 'S':
            printf("Suggestion: The classic combo of Samosa and Masala Chai is waiting for you!\n");
            break;
            
        default:
            printf("Try some fruits!\n");
            break;
    }

    return 0;
}

// Explanation:
// scanf(" %c", &mealTime);: The space before %c clears any leftover newline 
// character in the input buffer.

// Case Grouping: case 'b': and case 'B': are placed together so the program
//  works seamlessly whether the user types a lowercase or uppercase letter.

// default Case: If the user inputs anything other than the specified options
// , the program automatically branches here and prints 'Try some fruits!'.

// Q3.Create a Flipkart discount calculator that asks the user for the total 
// cart amount. Use nested if statements to check: if amount > 2000, apply 
// 20% discount; else if amount > 1000, apply 10% discount; else, no discount.
//  Print the final amount to pay.<br><br><em><strong>Hint:</strong> 
// Use nested ifs to check each discount slab.</em>

int main() {
    float cartAmount, discount = 0.0, finalAmount;

    // Ask the user for the total cart amount
    printf("--- Flipkart Discount Calculator ---\n");
    printf("Enter the total cart amount: ");
    scanf("%f", &cartAmount);

    // Nested if-else structure to evaluate discount slabs
    if (cartAmount > 1000) {
        if (cartAmount > 2000) {
            discount = 0.20; // 20% discount
        } else {
            discount = 0.10; // 10% discount
        }
    } else {
        discount = 0.0; // No discount
    }

    // Calculate the final amount to pay
    finalAmount = cartAmount - (cartAmount * discount);

    // Print the results
    printf("\n--- Order Summary ---");
    printf("\nOriginal Amount: %.2f", cartAmount);
    printf("\nDiscount Applied: %.0f%%", discount * 100);
    printf("\nFinal Amount to Pay: %.2f\n", finalAmount);

    return 0;
}
// How it works:
// Outer if Condition: The program first checks if the cartAmount is greater
// than 1000. If it isn't, it immediately goes to the outer else block 
// (no discount).

// Inner if Condition: If the amount is greater than 1000, it moves inside
// to a second (nested) check to see if the amount also crosses 2000 to 
// apply either a 20% or 10% discount.

// Formatting: %.2f ensures that the currency amounts are displayed cleanly 
// with exactly two decimal places.

// Q4.Write a program that takes a user's age and checks eligibility for
// three things using if-else statements: if age >= 18, print 'Eligible
// for Driving License'; if age >= 21, also print 'Eligible for Credit 
// Card'; if age >= 25, also print 'Eligible for Car Rental'. Print all 
// applicable messages for the given age.

int main() {
    int age;

    // Ask the user for their age
    printf("--- Eligibility Checker ---\n");
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("\n--- Results ---\n");
    
    // Check all applicable conditions independently
    if (age >= 18) {
        printf("Eligible for Driving License\n");
    }
    
    if (age >= 21) {
        printf("Eligible for Credit Card\n");
    }
    
    if (age >= 25) {
        printf("Eligible for Car Rental\n");
    }

    // Optional: If the user doesn't meet any criteria
    if (age < 18) {
        printf("Not eligible for any of the options yet.\n");
    }

    return 0;
}
// Why independent if statements are used here:
// Instead of an if-else if ladder (which stops executing as soon as it 
// finds the first true condition), using separate if statements allows the 
// program to evaluate every condition independently.

// --If you enter 19, only the first condition triggers.

// --If you enter 26, all three conditions evaluate to true, 
// printing all three applicable messages.