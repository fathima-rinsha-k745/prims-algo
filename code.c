#include <stdio.h>
#define SIZE 8  // Size of the universal set

// Function to input a set as a bit string
void inputSet(int set[], const char *name) {
    printf("Enter elements of Set %s (0 or 1) of size %d:\n", name, SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("%s[%d] = ", name, i);
        scanf("%d", &set[i]);
    }
}

// Function to print a set
void printSet(const int set[]) {
    printf("{ ");
    for (int i = 0; i < SIZE; i++) {
        if (set[i] == 1)
            printf("%d ", i);
    }
    printf("}");
}

// Function to find Union
void unionSet(const int set1[], const int set2[], int result[]) {
    for (int i = 0; i < SIZE; i++)
        result[i] = set1[i] | set2[i];
}

// Function to find Intersection
void intersectionSet(const int set1[], const int set2[], int result[]) {
    for (int i = 0; i < SIZE; i++)
        result[i] = set1[i] & set2[i];
}

// Function to find Difference (set1 - set2)
void differenceSet(const int set1[], const int set2[], int result[]) {
    for (int i = 0; i < SIZE; i++)
        result[i] = set1[i] & (!set2[i]);
}

int main() {
    int setA[SIZE], setB[SIZE];
    int unionResult[SIZE], intersectionResult[SIZE], differenceResult[SIZE];

    // Input sets
    inputSet(setA, "A");
    inputSet(setB, "B");

    // Perform operations
    unionSet(setA, setB, unionResult);
    intersectionSet(setA, setB, intersectionResult);
    differenceSet(setA, setB, differenceResult);

    // Display results
    printf("\nSet A: ");
    printSet(setA);

    printf("\nSet B: ");
    printSet(setB);

    printf("\n\nUnion (A ∪ B): ");
    printSet(unionResult);

    printf("\nIntersection (A ∩ B): ");
    printSet(intersectionResult);

    printf("\nDifference (A - B): ");
    printSet(differenceResult);

    printf("\n");

    return 0;
}
