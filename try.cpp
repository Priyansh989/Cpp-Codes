#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

using namespace std;

int main() {
    const int ARRAY_SIZE = 100;
    const int NUM_PARTS = 5;
    int array[ARRAY_SIZE];
    int parts[NUM_PARTS];

    // Initialize array with values from 1 to ARRAY_SIZE
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i + 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Divide the array into random parts
    int remaining = ARRAY_SIZE;
    for (int i = 0; i < NUM_PARTS; i++) {
        if (i == NUM_PARTS - 1) {
            // Last part gets the remaining units
            parts[i] = remaining;
        } else {
            // Randomly choose the size of the current part
            parts[i] = rand() % (remaining - NUM_PARTS + i + 1) + 1;
            remaining -= parts[i];
        }
    }

    // Shuffle the array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int j = rand() % ARRAY_SIZE;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // Print the parts and their contents
    int start = 0;
    for (int i = 0; i < NUM_PARTS; i++) {
        cout << "Part " << i+1 << ": ";
        for (int j = start; j < start + parts[i]; j++) {
            cout << array[j] << " ";
        }
        cout << endl;
        start += parts[i];
    }

    return 0;
}
