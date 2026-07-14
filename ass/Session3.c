//Q1Declare variables for a Flipkart product: productName (as a string), 
// price (float), and rating (double). Assign sample values and print each 
// variable with its data type.
#include <stdio.h>

int main() {
    // 1. Variable Declaration & Initialization
    char productName[] = "Wireless Earbuds"; // String represented as a character array
    float price = 1499.99f;                  // float data type
    double rating = 4.3;                    // double data type

    // 2. Printing values along with their data types
    printf("Product Name: %s (Data Type: String/char array)\n", productName);
    printf("Price: %.2f (Data Type: float)\n", price);
    printf("Rating: %.1f (Data Type: double)\n", rating);

    return 0;
}
//Explanation of Data Types Used:
// char[] (String): Used to store sequence of characters like the 
// product title.

// float: Used for numeric values with fractional parts (occupies 4 bytes 
// of memory).

// double: Used for higher precision fractional numbers (occupies 8 bytes 
// of memory).

//Q2.Create a constant variable to store the GST rate (for example, 18%) and 
// use it to calculate the final price of a Zomato order with a given base 
// price.<br><br><em><strong>Constraint:</strong> The GST rate must not be 
// changeable after its initial assignment.</em>

int main() {
    // 1. Declare a constant variable for the GST rate (18%)
    // The 'const' keyword enforces the constraint that it cannot be changed.
    const float GST_RATE = 0.18f; 
    
    // 2. Given base price for the Zomato order
    float basePrice = 450.00f;
    
    // 3. Calculate GST amount and the final price
    float gstAmount = basePrice * GST_RATE;
    float finalPrice = basePrice + gstAmount;
    
    // 4. Print the breakdown and final order price
    printf("--- Zomato Order Bill ---\n");
    printf("Base Price: %.2f\n", basePrice);
    printf("GST Rate: %.0f%%\n", GST_RATE * 100);
    printf("GST Amount: %.2f\n", gstAmount);
    printf("-------------------------\n");
    printf("Final Price: %.2f\n", finalPrice);
    
    return 0;
}
// Key Concept Explained:
// const Keyword: By prefixing the variable declaration with const, you turn
//  it into a read-only variable. If you try to add a line like 
// GST_RATE = 0.05; later in the code, the compiler will throw an error, 
// strictly satisfying your constraint.

//Q3.Write a program that stores your favorite Spotify playlist's name (string),
//  total number of songs (int), and average song duration in minutes (float).
//  Print all values in a single formatted sentence.

int main() {
    // 1. Variable Declaration & Initialization
    char playlistName[] = "Chill Lo-Fi Beats"; // String (character array)
    int totalSongs = 45;                       // Integer for whole numbers
    float avgDuration = 2.75f;                 // Float for decimal values

    // 2. Print all values in a single formatted sentence
    printf("My favorite Spotify playlist is \"%s\", which contains %d songs with an average song duration of %.2f minutes.\n", 
           playlistName, totalSongs, avgDuration);

    return 0;
}   
// Key Takeaways:
// Format Specifiers: We use %s for the string, %d for the integer, and %.2f
//  for the float (where .2 limits the output to two decimal places).

// Escape Sequence (\"): Used to print actual double quotation marks around 
// the playlist name inside the sentence.

//Q4 Identify and correct the invalid variable names from this list:
//  1stPlayer, player_age, $score, total-marks, userName.<br><br>
// <em><strong>Hint:</strong> Apply standard variable naming rules 
// for your programming language.</em>

// ❌ Invalid Variable Names & Corrections
// 1stPlayer

// Reason: Variable names cannot start with a number.

// Correction: player_1 or first_player

// $score

// Reason: Variable names cannot contain special characters like $ 
// (they can only contain letters, numbers, and underscores).

// Correction: score

// total-marks

// Reason: The hyphen (-) is not allowed because programming languages
//  interpret it as a subtraction operator.

// Correction: total_marks

// Valid Variable Names
// player_age (Valid: Uses standard snake_case, which is the recommended 
// practice in Python).

// userName (Valid: Uses camelCase, which is syntactically correct in Python,
//  though snake_case is preferred for variables under PEP 8 style guidelines).
