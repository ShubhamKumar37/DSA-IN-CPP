#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// Convert the 3x3 matrix to a binary representation for easier comparison
int matrixToBinary(const vector<string>& matrix) {
    int value = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == '1') {
                value |= (1 << (i * 3 + j));  // Set the corresponding bit in the integer
            }
        }
    }
    return value;
}

// Check if two binary representations differ by at most one bit
bool isValidWithOneToggle(int faulty, int valid) {
    int diff = faulty ^ valid;  // XOR to find the differing bits
    return __builtin_popcount(diff) <= 1; // Check if there's only one differing bit
}

int main() {
    vector<int> validDigits(10);

    // Input the first 3 lines which represent the valid 7-segment displays for digits 0-9
    vector<string> lines(3);
    for (int i = 0; i < 3; ++i) {
        cin >> lines[i];  // Read each line
    }

    // Convert each 3x3 block into a binary form representing digits 0-9
    for (int i = 0; i < 10; ++i) {
        vector<string> digitMatrix(3);
        for (int j = 0; j < 3; ++j) {
            digitMatrix[j] = lines[j].substr(i * 3, 3);  // Extract the 3x3 block for each digit
        }
        validDigits[i] = matrixToBinary(digitMatrix);  // Convert to binary and store
    }

    // Input the next 3 lines which represent the faulty 7-segment display
    vector<string> faultyLines(3);
    for (int i = 0; i < 3; ++i) {
        cin >> faultyLines[i];  // Read each line
    }

    // Vector to store the valid digits for each faulty digit
    vector<vector<int>> possibleDigits;

    // Process each faulty digit (each 3x3 block)
    for (size_t i = 0; i < faultyLines[0].size(); i += 3) {
        // Extract the 3x3 block representing the current faulty digit
        vector<string> faultyDigit(3);
        for (int j = 0; j < 3; ++j) {
            faultyDigit[j] = faultyLines[j].substr(i, 3);  // Extract 3x3 block
        }

        int faultyValue = matrixToBinary(faultyDigit);  // Convert faulty digit to binary

        vector<int> validForThisDigit;
        // Check each valid digit and see if it matches with the faulty one
        for (int j = 0; j < 10; ++j) {
            if (isValidWithOneToggle(faultyValue, validDigits[j])) {
                validForThisDigit.push_back(j);  // Store valid digits for this position
            }
        }

        // If no valid digit can be formed, print "Invalid" and return
        if (validForThisDigit.empty()) {
            cout << "Invalid" << endl;
            return 0;
        }

        possibleDigits.push_back(validForThisDigit);  // Store the valid digits for this position
    }

    // Now we need to generate all possible numbers and calculate their sum
    long long totalSum = 0;
    // Generate all possible combinations of valid digits
    size_t numDigits = possibleDigits.size();
    vector<size_t> current(numDigits, 0);  // Start with the first valid digit

    while (true) {
        // Calculate the number formed by the current combination of valid digits
        long long currentNumber = 0;
        for (size_t i = 0; i < numDigits; ++i) {
            currentNumber = currentNumber * 10 + possibleDigits[i][current[i]];  // Form the number
        }
        totalSum += currentNumber;  // Add the number to the total sum

        // Move to the next combination of digits
        int pos = numDigits - 1;
        while (pos >= 0) {
            if (current[pos] + 1 < possibleDigits[pos].size()) {
                current[pos]++;  // Move to the next valid digit for this position
                break;
            } else {
                current[pos] = 0;  // Reset the current position
                pos--;  // Move to the previous digit
            }
        }

        if (pos < 0) break;  // If we've processed all combinations, exit loop
    }

    // Output the sum of all valid numbers formed
    cout << totalSum << endl;
    return 0;
}


// Toggle Challenge
// Problem Description
// Deepika has a challenge for you involving a seven-segment display! Let us see what it is.

// Deepika will provide you with the 7-segment display of digits from 0 to 9, each represented in a 3x3 matrix format, all arranged in 3 lines. (Refer input format)

// Now, she will present you with a 7-segment display of a number that may be having some faults in it. You are allowed to toggle (LED light either on or off where 0 is off and 1 is on, which again will be turned back to original state) at most one light for each digit at a time, to form new numbers. Print the sum of all the numbers that can be formed.

// Constraints
// 1 <= number of digits in the input number <= 50

// Given input number will not start with 0.

// All the numbers from 0-9 will be unique in 7-segment display.

// Input
// The first three lines will contain the 3x3 matrix representations (7-segment display) of the digits from 0 to 9. In other words, first three lines consists of a 3*9 matrix consisting of only 1 and 0, where 1 indicates that the LED light is on and 0 means it is off.

// The next three lines will show the 7-segment display of the number provided by Deepika.

// Output
// Print the sum of all the numbers that can be formed by toggling the LED lights. If there is any digit in the input number that is invalid and cannot become a valid digit by toggling one light on or off, print "Invalid"

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 111001111111101111111111111111

// 101001001011111010100001111111

// 111001111111001111111001111001

// 001111111111

// 000001111010

// 001011111111

// Output

// 17888

// Explanation

// The first 3 lines, each having 30 columns represent numbers from 0 to 9. Each 3x3 matrix denoted in either red or green, represents individual numbers. The only purpose of colouring is readability.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7d373bcf:image1.png

// Next 3 lines of the input denote the actual LEDs which are to be toggled to solve the actual problem mentioned in description section above.


// Let us number the 9 lights present in each matrix from 1-9. Below are the few possibilities -

// 1. Toggle 6th light in first 3*3 matrix, 7th light in second 3*3 matrix. Keep the rest same. Number formed will be 1285. Reset the lights to original.

// 2. Toggle 6th light in first 3*3 matrix, 7th light in second 3*3 matrix, 5th light in the third 3*3 matrix and keep the rest same. Number formed will be 1205. Reset the lights to original.

// 3. Toggle 6th light in first 3*3 matrix, 7th light in second 3*3 matrix, 4th light in the third 3*3 matrix and keep the rest same. Number formed will be 1235. Reset the lights to original.

// 4. Toggle 6th light in first 3*3 matrix, 7th light in second 3*3 matrix, 4th light in the third 3*3 matrix and 6th light in the fourth 3*3 matrix. Keep the rest same. Number formed will be 1233. Reset the lights to original.

// ...

// ..

// All the numbers we can form is {1203, 1205, 1233, 1235, 1283, 1285, 1703, 1705, 1733, 1735, 1783, 1785} and their sum is 17888. Hence print the same.

// Example 2

// Input

// 111001111111101010111111111111

// 101001100011111111001001111111

// 111001111111001010111001111001

// 010111111100

// 111101011100

// 010111110100

// Output

// Invalid

// Explanation

// The first 3 lines, each having 30 columns represent numbers from 0 to 9. Each 3x3 matrix denoted in either red or green, represents individual numbers. The only purpose of colouring is readability.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7d373bcf:image2.png

// Next 3 lines of the input denote the actual LEDs which are to be toggled to solve the actual problem mentioned in description section above.

// Consider the last 3*3 matrix on lines 4 - 6, which is

// 100

// 100

// 100

// Based on the provided seven-segment display for the digits 0 to 9, this digit (matrix) is faulty and cannot be corrected by toggling a single light. Therefore, print "Invalid"