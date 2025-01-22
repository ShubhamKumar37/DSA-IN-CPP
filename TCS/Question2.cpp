#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Predefined patterns for letters A-Z
unordered_map<int, vector<char>> alp = {
    {92229, {'A', 'D'}}, {93339, {'B'}}, {92222, {'C', 'F'}}, {93333, {'E'}}, {92336, {'G'}}, {91119, {'H', 'N', 'U'}}, {22322, {'I'}}, {62229, {'J'}}, {92226, {'K'}}, {91111, {'L'}}, {91519, {'M', 'W'}}, {72227, {'O'}}, {92225, {'P'}}, {92339, {'Q'}}, {93336, {'R'}}, {63336, {'S'}}, {11911, {'T'}}, {71117, {'V'}}, {22122, {'X'}}, {62226, {'Y'}}, {23332, {'Z'}}};

// Function to check and return the corresponding letter based on the column segment
char checkChr(int s, const vector<string> &led)
{
    string valStr = "";
    for (int i = 0; i < 5; i++)
    {
        int t = 0;
        for (int j = 0; j < 9; j++)
        {
            t += led[j][s + i] - '0'; // Convert char to int
        }
        valStr += to_string(t);
    }
    int val = stoi(valStr);

    // Special cases for certain letters with specific rules
    if (val == 91519)
    {
        return (led[0].substr(s, 5) == "11111") ? 'M' : 'W';
    }
    else if (val == 91119)
    {
        if (led[8].substr(s, 5) == "11111")
            return 'U';
        if (led[4].substr(s, 5) == "11111")
            return 'H';
        return 'N';
    }
    else if (val == 92222)
    {
        return (led[4].substr(s, 5) == "11111") ? 'F' : 'C';
    }
    else if (val == 92229)
    {
        return (led[8].substr(s, 5) == "11111") ? 'D' : 'A';
    }
    else
    {
        return alp[val][0]; // Default case
    }
}

// Function to solve the grid and extract the characters
string solve(const vector<string> &led)
{
    int tb = led[0].size();

    // Merge the rows using OR operation
    string merged = led[0];
    for (int i = 1; i < 9; i++)
    {
        for (int j = 0; j < tb; j++)
        {
            merged[j] = (merged[j] - '0' | led[i][j] - '0') + '0'; // Perform OR operation and convert back to char
        }
    }

    string result = "";
    int s = 0;
    while (s < tb)
    {
        if (merged[s] == '1')
        {
            result += checkChr(s, led); // Extract and check the character
            s += 5;                     // Skip 5 positions after identifying the letter
        }
        else
        {
            s++; // Skip padding (zeros)
        }
    }
    return result;
}

int main()
{
    int t = 9;
    vector<string> led(t);

    // Read input grid (9 rows of LED display)
    for (int i = 0; i < t; i++)
    {
        cin >> led[i];
    }

    // Solve and output the result
    cout << solve(led) << endl;

    return 0;
}


// 14 Segment Display
// Problem Description
// A 14-segment display is a creative innovation in the field of electronics. A 14-segment display circuit can display all alphabets from A to Z (all in caps). Each alphabet is represented as a grid of 9 X 5. 0 (Zero) on the grid denotes that the LED at that place in the grid is turned OFF, whereas 1 denotes that the LED at that place in the grid is turned ON. The alphabets given as input may be padded with spaces between them i.e., the input grid is always of size 9 X Z where 9 is the number of rows and Z is the number of columns. Here Z is the total number of columns used to represent alphabets and the padding between the alphabets.

// Padding between alphabets is done using zeros (0). The padding between two alphabets on the grid can have random width.

// All the alphabets on 14-segment display are represented as follows:

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@33617539:image1.png

// Given the grid, determine what alphabets are displayed by the grid.

// Constraints
// Each alphabet is displayed by a 9 X 5 grid

// 1 <= Number of alphabets <= 10000

// Input
// Input consists of 9 lines where each line contains a binary string (consisting of 0 and 1) of equal breadth.

// Output
// Print alphabets displayed on the 14-segment display.

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 111110000011111011111

// 001000000010000010000

// 001000000010000010000

// 001000000010000010000

// 001000000010000011111

// 001000000010000000001

// 001000000010000000001

// 001000000010000000001

// 001000000011111011111

// Output

// TCS

// Explanation

// Here, the first 9 X 5 grid represents the alphabet 'T' and then we have a padding of width 5 (00000). Then the next 9 X 5 grid represents the alphabet 'C' and then we have padding of width 1 (0) and the next 9 X 5 grid represents the alphabet 'S'.

// Example 2

// Input

// 1111100000111110001111100111110000010001

// 1000000000100010001000100000000000000000

// 1000000000100010001000100000100000001010

// 1000000000100010001000100000000000000000

// 1111100000111110001111100001000000000100

// 0000100000100010001100000000000000000000

// 0000100000100010001010000010000000001010

// 0000100000100010001001000000000000000000

// 1111100000100010001000100111110000010001

// Output

// SARZX

// Explanation

// Here, the first 9 X 5 grid represents the alphabet S and there is a padding of width 5 (00000) and the next 9 X 5 grid represents the alphabet 'A' and then we have a padding of width 3 (000) and so on.

// There are 5 alphabets in this grid which are SARZX.