// Q1.Declare an integer variable called likes and a pointer variable called ptrLikes; assign likes a value, point ptrLikes to likes, and print both the value and the address stored in ptrLikes.

#include <stdio.h>

int main() {
    // 1. Declare an integer variable called likes
    int likes;
    
    // 2. Declare a pointer variable called ptrLikes
    int *ptrLikes;
    
    // 3. Assign likes a value
    likes = 250;
    
    // 4. Point ptrLikes to likes (assign the address of likes to ptrLikes)
    ptrLikes = &likes;
    
    // 5. Print both the value and the address stored in ptrLikes
    // Use %d or *ptrLikes to get the value it points to
    printf("Value pointed to by ptrLikes: %d\n", *ptrLikes);
    
    // Use %p to print the actual memory address stored in the pointer
    printf("Address stored in ptrLikes: %p\n", (void*)ptrLikes);
    
    return 0;
}

// Q2.Write a function swapPlaylistCounts(int *a, int *b) that swaps the number of songs in two Spotify playlists using pointers, then call the function in main and print the swapped values.

#include <stdio.h>

// Function to swap the song counts using pointers
void swapPlaylistCounts(int *a, int *b) {
    int temp = *a; // Store the value pointed to by a in a temporary variable
    *a = *b;       // Assign the value pointed to by b to the address held by a
    *b = temp;     // Assign the temporary value to the address held by b
}

int main() {
    // Initialize the song counts for two Spotify playlists
    int playlist1 = 45;
    int playlist2 = 82;

    printf("--- Before Swapping ---\n");
    printf("Playlist 1 song count: %d\n", playlist1);
    printf("Playlist 2 song count: %d\n", playlist2);

    // Call the function by passing the addresses of the variables
    swapPlaylistCounts(&playlist1, &playlist2);

    printf("\n--- After Swapping ---\n");
    printf("Playlist 1 song count: %d\n", playlist1);
    printf("Playlist 2 song count: %d\n", playlist2);

    return 0;
}


// Q3.Given an array of 5 order amounts (e.g., Zomato orders), use a pointer to iterate through the array and print each amount along with its memory address.<br><br><em><strong>Hint:</strong> Use pointer arithmetic to move to the next element.</em>

#include <stdio.h>

int main() {
    // 1. Initialize an array of 5 order amounts (using float for currency)
    float orders[5] = {249.50, 580.00, 120.25, 899.90, 450.00};
    
    // 2. Declare a pointer pointing to the first element of the array
    float *ptr = orders; // Equivalent to: float *ptr = &orders[0];
    
    printf("--- Zomato Order Details ---\n\n");
    
    // 3. Iterate through the array using pointer arithmetic
    for (int i = 0; i < 5; i++) {
        // *(ptr + i) accesses the value at the current index
        // (ptr + i) gives the exact memory address of that index
        printf("Order %d: Amount = %.2f | Memory Address = %p\n", i + 1, *(ptr + i), (void*)(ptr + i));
    }
    
    return 0;
}

// Q4.Create a function incrementFollowers(int *followers, int n) that increases each follower count in an array (representing Instagram followers for 5 friends) by 100 using pointer arithmetic, then print the updated counts.

#include <stdio.h>

// Function to increase each follower count by 100 using pointer arithmetic
void incrementFollowers(int *followers, int n) {
    for (int i = 0; i < n; i++) {
        // *(followers + i) targets the value at the current index
        *(followers + i) += 100; 
    }
}

int main() {
    // Initialize an array representing Instagram followers for 5 friends
    int instagramFollowers[5] = {250, 480, 1200, 75, 310};
    int n = 5;

    printf("--- Original Follower Counts ---\n");
    for (int i = 0; i < n; i++) {
        printf("Friend %d: %d followers\n", i + 1, instagramFollowers[i]);
    }

    // Call the function passing the array (decays to a pointer) and its size
    incrementFollowers(instagramFollowers, n);

    printf("\n--- Updated Follower Counts (After +100) ---\n");
    for (int i = 0; i < n; i++) {
        printf("Friend %d: %d followers\n", i + 1, instagramFollowers[i]);
    }

    return 0;
}

// Q5.Draw a simple memory diagram (on paper or using any drawing tool) showing how a pointer references the address of a variable, using the variables from your likes and ptrLikes example; label the variable, pointer, and address.
/*
MEMORY LAYOUT (Conceptual)
      ---------------------------
      |      ...            |
Address: 0x1000   +-----------------+
      |      |      10 (Value) | <--- Variable: likes
      |      |                 |
      |      ----------------- |
      |      |      ...        |
      |      |                 |
Address: 0x2000   +-----------------+
      |      |   0x1000 (Value)| <--- Pointer: ptrLikes
      |      | (Address of likes)|
      |      +--------|--------+
      |               |
      |      ...      |
      ----------------|----------
                      |
                      | (References)
                      V
*/
/*Explanation of the Diagram:
Memory Cells: The rectangles represent specific locations in computer memory.

Variable: likes

It is located at memory address 0x1000 (hypothetical).

It stores the integer value 10.

Pointer: ptrLikes

It is a separate variable located at a different memory address, 0x2000 (hypothetical).

The "value" stored inside ptrLikes is not an integer like 10, but rather the address of the variable it points to: 0x1000.

The Arrow (Reference): The arrow demonstrates that by knowing the value inside ptrLikes (0x1000), the program can "point" to or reference the location of the likes variable.
*/