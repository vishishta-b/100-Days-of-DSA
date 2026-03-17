#include <stdio.h>

int leastInterval(char* tasks, int tasksSize, int n) {
    // Array to store the frequency of the 26 English uppercase letters
    int freq[26] = {0};
    int maxFreq = 0;
    int maxCount = 0;

    // Step 1: Count task frequencies and find the maximum frequency
    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
        if (freq[tasks[i] - 'A'] > maxFreq) {
            maxFreq = freq[tasks[i] - 'A'];
        }
    }

    // Step 2: Count how many distinct tasks share this maximum frequency
    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq) {
            maxCount++;
        }
    }

    // Step 3: Apply the greedy math formula
    int calculatedTime = (maxFreq - 1) * (n + 1) + maxCount;

    // Step 4: Return the maximum between the calculated time and the actual number of tasks.
    // If calculatedTime is smaller, it means no idle slots are needed.
    return calculatedTime > tasksSize ? calculatedTime : tasksSize;
}
