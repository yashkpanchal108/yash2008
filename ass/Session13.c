//Q1.Create a file called playlist.txt and write the names of your top 3 favorite songs from Spotify into it using write mode (w).

#include <stdio.h>

int main() {
    // Open the file in write mode ("w")
    // This creates a new file or overwrites it if it already exists
    FILE *file = fopen("playlist.txt", "w");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write the top 3 favorite songs into the file
    fprintf(file, "Bohemian Rhapsody\n");
    fprintf(file, "Blinding Lights\n");
    fprintf(file, "Hotel California\n");

    // Always close the file after operations are complete
    fclose(file);

    printf("Successfully created playlist.txt and added 3 songs!\n");
    return 0;
}

// Q2.Open playlist.txt in read mode (r) and display each song name on a separate line in the console.

#include <stdio.h>

int main() {
    // Open the file in read mode ("r")
    FILE *file = fopen("playlist.txt", "r");

    // Check if the file exists and opened successfully
    if (file == NULL) {
        printf("Error: Could not open playlist.txt. Make sure the file exists!\n");
        return 1;
    }

    // Buffer to hold each line (song name) as it is read
    char song[100];

    printf("--- My Spotify Playlist ---\n");

    // Read line by line until the end of the file (EOF)
    while (fgets(song, sizeof(song), file) != NULL) {
        // Print the song name
        printf("%s", song);
    }

    // Close the file connection
    fclose(file);

    return 0;
}


// Q3.Add two more song names to playlist.txt without deleting the existing ones by opening the file in append mode (a).

#include <stdio.h>

int main() {
    // Open the file in append mode ("a")
    // This preserves existing content and moves the file pointer to the end
    FILE *file = fopen("playlist.txt", "a");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Append two new song names to the file
    fprintf(file, "Stayin' Alive\n");
    fprintf(file, "Shape of You\n");

    // Close the file connection
    fclose(file);

    printf("Successfully appended 2 more songs to playlist.txt!\n");
    return 0;
}

// Q4.Write a program that reads all song names from playlist.txt and prints only those that contain the word 'love' (case-insensitive).<br><br><em><strong>Hint:</strong> Use the 'in' keyword or equivalent string method for filtering.</em>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main() {
    // Open the file in read mode ("r")
    FILE *file = fopen("playlist.txt", "r");

    // Check if the file exists and opened successfully
    if (file == NULL) {
        printf("Error: Could not open playlist.txt. Make sure the file exists!\n");
        return 1;
    }

    char originalSong[100];
    char lowercasedSong[100];
    int found = 0;

    printf("--- Songs containing 'love' (Case-Insensitive) ---\n");

    // Read the file line by line
    while (fgets(originalSong, sizeof(originalSong), file) != NULL) {
        
        // Copy the original song name to convert it to lowercase for filtering
        strcpy(lowercasedSong, originalSong);
        toLowerCase(lowercasedSong);

        // Check if "love" exists in the lowercased version of the string
        if (strstr(lowercasedSong, "love") != NULL) {
            // Print the original song name to maintain proper capitalization
            printf("- %s", originalSong);
            found = 1;
        }
    }

    if (!found) {
        printf("No songs matching 'love' were found in your playlist.\n");
    }

    // Close the file connection
    fclose(file);

    return 0;
}