// Q1.Declare a string variable called songTitle and assign it the value 'Tum Hi Ho'. Print the length of the string using strlen().

#include <stdio.h>
#include <string.h>

int main() {
    // Declare a string variable and assign the value 'Tum Hi Ho'
    char songTitle[] = "Tum Hi Ho";
    
    // Print the length of the string using strlen()
    printf("The length of the string '%s' is: %zu\n", songTitle, strlen(songTitle));
    
    return 0;
}

// Q2.Take input for two usernames (as strings) and compare them using strcmp(). Display whether they are the same or different.

#include <stdio.h>
#include <string.h>

int main() {
    // Declare two character arrays to store the usernames
    char username1[50];
    char username2[50];

    // Take input for the first username
    printf("Enter the first username: ");
    scanf("%49s", username1);

    // Take input for the second username
    printf("Enter the second username: ");
    scanf("%49s", username2);

    // Compare the two usernames using strcmp()
    if (strcmp(username1, username2) == 0) {
        printf("The usernames are the same.\n");
    } else {
        printf("The usernames are different.\n");
    }

    return 0;
}

// Q3.Copy the string 'Flipkart' into another string variable called shoppingApp using strcpy(), then print the value of shoppingApp.<br><br><em><strong>Hint:</strong> Make sure to declare enough space for the destination string.</em>

#include <stdio.h>
#include <string.h>

int main() {
    // Declare a destination string variable with enough space 
    // ("Flipkart" has 8 characters + 1 for the null terminator '\0')
    char shoppingApp[10];
    
    // Copy the string 'Flipkart' into shoppingApp using strcpy()
    strcpy(shoppingApp, "Flipkart");
    
    // Print the value of shoppingApp
    printf("The value of shoppingApp is: %s\n", shoppingApp);
    
    return 0;
}


// Q4.Build a small script that takes the user's full name as input and creates a username by copying only the first 5 characters using strcpy(). Print the generated username.<br><br><em><strong>Constraint:</strong> If the name is shorter than 5 characters, use the full name as the username.</em>

#include <stdio.h>
#include <string.h>

int main() {
    // Declare a destination string variable with enough space 
    // ("Flipkart" has 8 characters + 1 for the null terminator '\0')
    char shoppingApp[10];
    
    // Copy the string 'Flipkart' into shoppingApp using strcpy()
    strcpy(shoppingApp, "Flipkart");
    
    // Print the value of shoppingApp
    printf("The value of shoppingApp is: %s\n", shoppingApp);
    
    return 0;
}