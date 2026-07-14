// Q1.Declare a function called getUserInitials that takes a user's full name (like 'Virat Kohli') and returns their initials in uppercase (e.g., 'VK'). Call this function with your favorite cricketer's name and print the result.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 1. Declare the function
void getUserInitials(const char *fullName, char *initials) {
    int i = 0;
    int j = 0;
    int isNewWord = 1; // Flag to identify the start of a word

    while (fullName[i] != '\0') {
        if (fullName[i] == ' ') {
            isNewWord = 1; // The next non-space character starts a new word
        } else if (isNewWord && fullName[i] != ' ') {
            initials[j] = toupper(fullName[i]); // Convert to uppercase and store
            j++;
            isNewWord = 0; // Reset flag until the next space
        }
        i++;
    }
    initials[j] = '\0'; // Null-terminate the destination string
}

int main() {
    // Favorite cricketer's name
    char cricketer[] = "Virat Kohli";
    char result[10]; // Buffer to hold the extracted initials

    // 2. Call the function
    getUserInitials(cricketer, result);

    // 3. Print the result
    printf("The initials of %s are: %s\n", cricketer, result);

    return 0;
}

// Q2.Create a function addToCart that takes a shopping cart array and a product name, adds the product to the cart, and prints the updated cart. Demonstrate how passing the cart array by reference allows changes to persist outside the function.<br><br><em><strong>Hint:</strong> In languages like JavaScript, arrays are passed by reference. In C/C++, use pointers for reference behavior.</em>

#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 5
#define MAX_NAME_LEN 30

// 1. Declare the function
// The cart parameter receives the memory address of the 2D array (pass-by-reference)
void addToCart(char cart[MAX_ITEMS][MAX_NAME_LEN], int *itemCount, const char *productName) {
    if (*itemCount < MAX_ITEMS) {
        // Copy the product name into the cart array at the current item count index
        strcpy(cart[*itemCount], productName);
        (*itemCount)++; // Increment the total number of items using its pointer
        
        // Print the updated cart from inside the function
        printf("--- Updated Cart (Inside Function) ---\n");
        for (int i = 0; i < *itemCount; i++) {
            printf("%d. %s\n", i + 1, cart[i]);
        }
        printf("--------------------------------------\n\n");
    } else {
        printf("Cart is full! Cannot add %s.\n\n", productName);
    }
}

int main() {
    // Initialize an empty shopping cart (2D array) and item counter
    char shoppingCart[MAX_ITEMS][MAX_NAME_LEN] = {0};
    int totalItems = 0;

    printf("Initial total items outside function: %d\n\n", totalItems);

    // 2. Call the function to add products
    // We pass 'shoppingCart' (array address) and '&totalItems' (address of counter)
    addToCart(shoppingCart, &totalItems, "Wireless Mouse");
    addToCart(shoppingCart, &totalItems, "Mechanical Keyboard");

    // 3. Demonstrate that changes persisted outside the function
    printf("=== Verifying Cart Outside Function ===\n");
    printf("Total items tracked in main(): %d\n", totalItems);
    for (int i = 0; i < totalItems; i++) {
        printf("Item %d: %s\n", i + 1, shoppingCart[i]);
    }
    printf("=======================================\n");

    return 0;
}


// Q3.Write two functions: increaseFollowersByValue and increaseFollowersByReference. Each should take a followers count and add 1000 to it, but one should use pass-by-value and the other pass-by-reference. Show how the original followers count changes (or doesn't) after calling each function.

#include <stdio.h>

// 1. Pass-by-Value Function
// This receives a copy of the actual value. Changes remain local to the function.
void increaseFollowersByValue(int followers) {
    followers += 1000;
    printf("Inside increaseFollowersByValue: %d\n", followers);
}

// 2. Pass-by-Reference Function
// This receives the memory address (pointer) of the original variable.
// Modifying it changes the variable outside the function.
void increaseFollowersByReference(int *followers) {
    *followers += 1000; // Dereference pointer to modify the original value
    printf("Inside increaseFollowersByReference: %d\n", *followers);
}

int main() {
    int originalFollowers = 5000;

    printf("--- Initial State ---\n");
    printf("Original Followers Count: %d\n\n", originalFollowers);

    // Testing Pass-by-Value
    printf("--- Calling Pass-by-Value ---\n");
    increaseFollowersByValue(originalFollowers);
    printf("After increaseFollowersByValue (in main): %d\n\n", originalFollowers);

    // Testing Pass-by-Reference
    printf("--- Calling Pass-by-Reference ---\n");
    // We pass the address of originalFollowers using the '&' operator
    increaseFollowersByReference(&originalFollowers);
    printf("After increaseFollowersByReference (in main): %d\n", originalFollowers);

    return 0;
}


// Q4.Build a function formatPrice that takes a price in rupees and returns a string formatted like Flipkart's price tag (e.g., '₹1,599'). Use this function to display prices for three different products.

#include <stdio.h>
#include <string.h>

// 1. Declare the function
void formatPrice(double price, char *formattedPrice) {
    char temp[50];
    // Convert the number to an integer string (ignoring paise for standard price tags)
    long long intPrice = (long long)price;
    sprintf(temp, "%lld", intPrice);

    int len = strlen(temp);
    int j = 0;

    // Copy the Rupee symbol safely into the destination buffer
    // Note: The '₹' symbol takes 3 bytes in UTF-8 encoding
    strcpy(formattedPrice, "₹");
    j = strlen(formattedPrice);

    // If the number is 3 digits or fewer, no formatting commas are needed
    if (len <= 3) {
        strcat(formattedPrice, temp);
        return;
    }

    // Process the string from right to left to apply Indian Currency formatting
    // (Thousands comma after 3 digits, then every 2 digits for Lakhs/Crores)
    for (int i = 0; i < len; i++) {
        formattedPrice[j++] = temp[i];
        
        int remainingDigits = len - 1 - i;
        
        // Place a comma after the thousands position, or every two digits before that
        if (remainingDigits == 3 || (remainingDigits > 3 && (remainingDigits - 3) % 2 == 0)) {
            formattedPrice[j++] = ',';
        }
    }
    formattedPrice[j] = '\0'; // Null-terminate the string
}

int main() {
    // Array of prices for three different products
    double productPrices[3] = {1599.00, 29999.00, 145000.00};
    char productNames[3][30] = {"Wireless Headphones", "Smart Television", "Premium Laptop"};
    char buffer[50];

    printf("=== Flipkart Price Tags ===\n\n");

    // 2 & 3. Call the function and display the prices for three products
    for (int i = 0; i < 3; i++) {
        formatPrice(productPrices[i], buffer);
        printf("%s: %s\n", productNames[i], buffer);
    }

    return 0;
}


// Q5.Refactor an existing function you wrote above to make it reusable for both product names and usernames (for example, a function that capitalizes the first letter of any string).<br><br><em><strong>Constraint:</strong> The refactored function should work for any string input, not just a specific use case.</em>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Universal Constraint: The function accepts ANY string input and alters it in place.
void capitalizeWords(char *str) {
    int i = 0;
    int isNewWord = 1; // Flag to track the start of a word

    while (str[i] != '\0') {
        if (str[i] == ' ') {
            isNewWord = 1; // Next non-space character will be a new word
        } else {
            if (isNewWord) {
                str[i] = toupper(str[i]); // Capitalize the first letter
                isNewWord = 0;
            } else {
                str[i] = tolower(str[i]); // Ensure the rest of the word is lowercase
            }
        }
        i++;
    }
}

int main() {
    // Test Case 1: Product Name
    char product[30] = "nIkE aIr mAx";
    
    // Test Case 2: Username
    char username[30] = "vIrat kOhli";

    printf("--- Before Refactored Function ---\n");
    printf("Product: %s\n", product);
    printf("Username: %s\n\n", username);

    // Reusing the exact same function for completely different use cases
    capitalizeWords(product);
    capitalizeWords(username);

    printf("--- After Refactored Function ---\n");
    printf("Product: %s\n", product);
    printf("Username: %s\n", username);

    return 0;
}