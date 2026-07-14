// Q1.Declare a structure named Playlist to store details of a song: title (string), artist (string), and duration in seconds (integer). Initialize one Playlist variable with your favorite song's details and print each field.

#include <stdio.h>

// Define the structure named Playlist
struct Playlist {
    char title[100];
    char artist[100];
    int duration; // Duration in seconds
};

int main() {
    // Initialize one Playlist variable with song details
    struct Playlist myFavoriteSong = {
        "Bohemian Rhapsody",
        "Queen",
        355
    };

    // Print each field of the structure
    printf("--- Favorite Song Details ---\n");
    printf("Title    : %s\n", myFavoriteSong.title);
    printf("Artist   : %s\n", myFavoriteSong.artist);
    printf("Duration : %d seconds\n", myFavoriteSong.duration);

    return 0;
}


// Q2.Create a structure called FoodItem to store Zomato-style menu data: itemName (string), price (float), and rating (float). Initialize an array of 3 FoodItem variables with real menu items and display their details using a loop.

#include <stdio.h>

// Define the structure to store Zomato-style menu data
struct FoodItem {
    char itemName[100];
    float price;
    float rating;
};

int main() {
    // Initialize an array of 3 FoodItem variables
    struct FoodItem menu[3] = {
        {"Paneer Butter Masala", 280.50, 4.5},
        {"Chicken Biryani", 320.00, 4.7},
        {"Garlic Naan", 60.00, 4.2}
    };

    printf("--- Zomato Menu Data ---\n");
    
    // Display the details using a loop
    for (int i = 0; i < 3; i++) {
        printf("Item %d:\n", i + 1);
        printf("  Name   : %s\n", menu[i].itemName);
        printf("  Price  : %.2f INR\n", menu[i].price);
        printf("  Rating : %.1f / 5.0\n", menu[i].rating);
        printf("-----------------------\n");
    }

    return 0;
}


// Q3.Define a nested structure called MovieShow for a BookMyShow-style app: Movie (string), Screen (integer), and a nested structure Time with hours and minutes (integers). Create and initialize a MovieShow variable for any movie and print its details in the format 'Movie: X, Screen: Y, Time: HH:MM'.

#include <stdio.h>

// Define the inner structure for Time
struct Time {
    int hours;
    int minutes;
};

// Define the nested outer structure for MovieShow
struct MovieShow {
    char movie[100];
    int screen;
    struct Time showTime; // Nested structure variable
};

int main() {
    // Initialize a MovieShow variable with movie details
    struct MovieShow currentShow = {
        "Inception",
        3,
        {18, 45} // Initializes hours as 18 and minutes as 45
    };

    // Print details in the format 'Movie: X, Screen: Y, Time: HH:MM'
    // %02d ensures that single digit hours/minutes are padded with a leading zero
    printf("Movie: %s, Screen: %d, Time: %02d:%02d\n", 
            currentShow.movie, 
            currentShow.screen, 
            currentShow.showTime.hours, 
            currentShow.showTime.minutes);

    return 0;
}

// Q4.Build a structure called InstaProfile with fields: username (string), followers (integer), and a nested structure Bio with fields: description (string) and age (integer). Initialize an InstaProfile variable with your own details and display all fields.

#include <stdio.h>

// Define the inner structure for Bio
struct Bio {
    char description[150];
    int age;
};

// Define the outer structure for InstaProfile
struct InstaProfile {
    char username[50];
    int followers;
    struct Bio profileBio; // Nested structure variable
};

int main() {
    // Initialize an InstaProfile variable with sample details
    struct InstaProfile myProfile = {
        "ai_collaborator",
        15000,
        {"An authentic, adaptive AI companion with a touch of wit.", 0} // Age is 0 since I'm an AI!
    };

    // Display all fields
    printf("--- Instagram Profile Details ---\n");
    printf("Username    : @%s\n", myProfile.username);
    printf("Followers   : %d\n", myProfile.followers);
    printf("Bio Desc    : %s\n", myProfile.profileBio.description);
    printf("Bio Age     : %d\n", myProfile.profileBio.age);
    printf("----------------------------------\n");

    return 0;
}