//Q1.Create a simple JavaScript function called calculateTotal that takes 
// two numbers: itemPrice and quantity, and returns the total bill amount 
// using arithmetic operators.

function calculateTotal(itemPrice, quantity) {
    return itemPrice * quantity;
}

// Example usage:
let totalBill = calculateTotal(250, 3);
console.log(totalBill); // Output: 750

// Explanation:
// function calculateTotal(itemPrice, quantity): Defines a function that 
// accepts two parameters (itemPrice and quantity).

// itemPrice * quantity: Uses the arithmetic multiplication operator (*) 
// to calculate the total cost.

// return: Sends the calculated total back to wherever the function was 
// called.

// Q2.Build a Flipkart-style discount calculator: given product price, 
// discount percentage, and a boolean isMember, use arithmetic and 
// logical operators to calculate the final price (apply an extra 5%
//  off if isMember is true).

#include <stdio.h>
#include <stdbool.h>

// Function to calculate the final price
float calculateFlipkartDiscount(float productPrice, float discountPercentage, bool isMember) {
    // 1. Calculate price after the initial product discount using arithmetic operators
    float baseDiscount = productPrice * (discountPercentage / 100.0);
    float finalPrice = productPrice - baseDiscount;

    // 2. Use a logical condition to apply an extra 5% off if isMember is true
    if (isMember) {
        finalPrice = finalPrice * 0.95; // 5% off means paying 95% of the price
    }

    return finalPrice;
}

int main() {
    float price = 1000.0;
    float discount = 10.0;

    // Test Case 1: Regular customer (isMember = false)
    float regularPrice = calculateFlipkartDiscount(price, discount, false);
    printf("Regular Customer Price: INR %.2f\n", regularPrice); 
    // Output: INR 900.00

    // Test Case 2: Flipkart Plus Member (isMember = true)
    float memberPrice = calculateFlipkartDiscount(price, discount, true);
    printf("Plus Member Price: INR %.2f\n", memberPrice); 
    // Output: INR 855.00

    return 0;
// }
// Explanation of Operators:
// Arithmetic Operators (*, /, -): Used to compute fractions 
// (discountPercentage / 100.0), calculate the deduction amount, 
// and subtract it from the original base price.

// Logical Evaluation (if (isMember)): The statement acts directly on the 
// boolean variable. Since isMember holds true or false, it decides whether 
// to execute the nested arithmetic operations for the additional 5% discount.

// Q3.Write a function isEligibleForOffer that takes a user's age and total
//  order value, and returns true if the user is 18 or older AND the order 
// value is above 500, otherwise false.<br><br><em><strong>Hint:</strong> 
// Use relational and logical operators together.</em>

// Function definition
bool isEligibleForOffer(int age, float totalOrderValue) {
    // Returns true if age >= 18 AND totalOrderValue > 500
    return (age >= 18) && (totalOrderValue > 500.0);
}

int main() {
    // Test Case 1: Eligible user
    if (isEligibleForOffer(20, 600.0)) {
        printf("User 1 is eligible for the offer.\n"); // Will print
    } else {
        printf("User 1 is not eligible.\n");
    }

    // Test Case 2: Underage user
    if (isEligibleForOffer(16, 700.0)) {
        printf("User 2 is eligible for the offer.\n");
    } else {
        printf("User 2 is not eligible.\n"); // Will print
    }

    return 0;
}

// Explanation of Operators Used:
// Relational Operators (>=, >):

// age >= 18 checks if the user is an adult.

// totalOrderValue > 500 checks if the purchase amount crosses the required
//  threshold.

// Logical AND Operator (&&): Joins both expressions together. 
// It ensures that the entire function will evaluate to true only if
//  both sides are true. If even one condition fails, it immediately
//  returns false.

// Q4.Given three variables: likes, comments, and shares (all numbers), 
// write code to check if a post is 'trending' on Instagram 
// (at least 1000 likes OR more than 200 comments AND at least 50 shares). 
// Print the result.

int main() {
    int likes = 800;
    int comments = 250;
    int shares = 55;

    // Condition logic checking using relational and logical operators
    bool isTrending = (likes >= 1000 || comments > 200) && shares >= 50;

    if (isTrending) {
        printf("The post is trending!\n");
    } else {
        printf("The post is not trending.\n");
    }

    return 0;
}
// Operator Explanation:
// likes >= 1000: Checks if likes are at least 1000.

// comments > 200: Checks if comments are strictly more than 200.

// || (Logical OR): Ensures that passing either the likes or comments 
// threshold satisfies the first half of the rule.

// && shares >= 50: Ensures that regardless of likes or comments, 
// the post must have at least 50 shares to be considered trending.

// Q5.Write a code snippet that demonstrates the difference between 
// pre-increment (++count) and post-increment (count++) by logging the 
// values before and after using both on a followerCount variable.

int main() {
    // --- 1. POST-INCREMENT (followerCount++) ---
    // The current value is evaluated/used first, and THEN the variable is incremented in memory.
    int followerCount = 100;

    printf("--- Post-Increment Demo ---\n");
    printf("Initial Value: %d\n", followerCount); // 100

    // Logged during the post-increment operation
    printf("Value during (followerCount++): %d\n", followerCount++); // 100 (Prints original value first!)

    // Logged immediately after the operation
    printf("Value after (followerCount++): %d\n", followerCount); // 101 (Now reflects the change)

    printf("\n-------------------------\n\n");

    // --- 2. PRE-INCREMENT (++followerCount) ---
    // The variable is incremented in memory first, and THEN the updated value is evaluated/used.
    followerCount = 100; // Resetting back to 100

    printf("--- Pre-Increment Demo ---\n");
    printf("Initial Value: %d\n", followerCount); // 100

    // Logged during the pre-increment operation
    printf("Value during (++followerCount): %d\n", ++followerCount); // 101 (Increments first, then prints!)

    // Logged immediately after the operation
    printf("Value after (++followerCount): %d\n", followerCount); // 101

    return 0;
}

// Core Difference Recap:
// Post-Increment (followerCount++): Passes the current value to the 
// printf function execution line, and then increments the value by 1 
// in the background memory.

// Pre-Increment (++followerCount): Increments the value in the background 
// memory first, and then passes that brand new value to the printf function
//  execution line.