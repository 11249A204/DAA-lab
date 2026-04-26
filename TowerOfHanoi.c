AIM:To implement the Tower of Hanoi problem in C using recursion to move disks from source to destination following the rules.
PROGRAM:
#include <stdio.h>

// Function to solve Tower of Hanoi
void toh(int diskcount, char s, char d, char t){
    
    // Base case: if only one disk, move directly
    if (diskcount == 1)
    {
        printf("\nMove disk %d from %c to %c", diskcount, s, d);
        return;
    }

    // Step 1: Move n-1 disks from source to temporary
    toh(diskcount - 1, s, t, d);

    // Step 2: Move the remaining disk to destination
    printf("\nMove disk %d from %c to %c", diskcount, s, d);

    // Step 3: Move n-1 disks from temporary to destination
    toh(diskcount - 1, t, d, s);
}

int main() {
    int n;

    // Input number of disks
    printf("Enter number of disks: ");
    scanf("%d", &n);

    // Call Tower of Hanoi function
    toh(n, 'S', 'D', 'T');  // S = Source, D = Destination, T = Temporary

    return 0;
}

OUTPUT:
Enter number of disks: 3

Move disk 1 from S to D
Move disk 2 from S to T
Move disk 1 from D to T
Move disk 3 from S to D
Move disk 1 from T to S
Move disk 2 from T to D
Move disk 1 from S to D
