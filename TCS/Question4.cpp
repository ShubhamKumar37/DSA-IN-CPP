#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// Directions to check adjacent cells
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Function to check if a cell is within bounds and hasn't been visited
bool isValid(int x, int y, int N, int M, vector<vector<int>> &matrix, vector<vector<bool>> &visited) {
    return (x >= 0 && x < N && y >= 0 && y < M && !visited[x][y]);
}

// Function to simulate gravity
void applyGravity(int N, int M, vector<vector<int>> &matrix, set<pair<int, int>> &blocksToRemove) {
    for (int j = 0; j < M; ++j) {
        int emptyRow = N - 1;

        // Traverse the column from bottom to top
        for (int i = N - 1; i >= 0; --i) {
            if (blocksToRemove.count({i, j})) {
                continue; // Skip already removed blocks
            }
            if (i != emptyRow) {
                matrix[emptyRow][j] = matrix[i][j]; // Move block down
                matrix[i][j] = -1; // Mark the old position as empty
            }
            emptyRow--;
        }
    }
}

// BFS to find blocks to remove starting from the rightmost column
void bfsToFindBlocks(int N, int M, vector<vector<int>> &matrix, int targetColor, set<pair<int, int>> &blocksToRemove) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;

    // Start from the rightmost column
    for (int i = 0; i < N; ++i) {
        q.push({i, M - 1}); // Start with the rightmost column (M-1)
        visited[i][M - 1] = true; // Mark it visited
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        int currentColor = matrix[x][y];

        // If it's not the target block, add it to the set of blocks to remove
        if (currentColor != targetColor) {
            blocksToRemove.insert({x, y});
        }

        // Explore all four adjacent directions (up, down, left, right)
        for (auto dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (isValid(nx, ny, N, M, matrix, visited)) {
                visited[nx][ny] = true;
                // Only push neighboring blocks with the same color as the current block or target color
                if (matrix[nx][ny] == currentColor || matrix[nx][ny] == targetColor) {
                    q.push({nx, ny}); // Push valid adjacent block to the queue
                }
            }
        }
    }
}

int main() {
    int N, M, targetColor;
    cin >> N >> M;
    
    vector<vector<int>> matrix(N, vector<int>(M));

    // Read matrix
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
        }
    }

    cin >> targetColor;

    set<pair<int, int>> blocksToRemove;
    bfsToFindBlocks(N, M, matrix, targetColor, blocksToRemove);

    // Apply gravity after marking blocks to be removed
    applyGravity(N, M, matrix, blocksToRemove);

    // After applying gravity, re-run BFS to check if any additional blocks are affected
    bfsToFindBlocks(N, M, matrix, targetColor, blocksToRemove);

    // Output the total number of blocks to be removed
    cout << blocksToRemove.size(); // Output number of blocks to remove

    return 0;
}


// Block Extraction-2
// Problem Description
// Chintu is playing with Lego blocks arranged in a matrix. Each block is a different colour and can only be placed straight, either horizontally or vertically, in a matrix arrangement.

// The given matrix contains integers, where each colour of the blocks is represented by a number which is called as colour code of that block. If two or more adjacent cells have the same number, it means one block is occupying all those cells. There will be only one block of each colour.

// Given the front view of the matrix, Chintu can only remove blocks from the right side, taking out one whole block at a time. If there is a barrier in front of a block, he must remove the barrier first to access the block he wants.

// A block will remain in place even if it has support from just one adjacent cell. Otherwise, it will fall due to gravity.

// Can you help Chintu calculate the number of blocks he needs to remove to extract the desired block?

// Constraints
// 1 <= N, M <= 50

// 1 <= colour code <= 100

// Input
// First line consists of two space separated integers N, M denoting the number of rows and columns in the matrix.

// The next N lines contain M space-separated integers that represent the colour codes of the blocks and the cells each block occupies.

// Last line consists of an integer denoting the colour code of the block which Chintu wanted to extract.

// Output
// Print a single number indicating how many blocks Chintu needs to remove to access the specified block.

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 5 5

// 15 12 23 13 13

// 15 12 14 8 10

// 5 11 11 8 9

// 5 6 6 7 7

// 1 1 2 3 4

// 1

// Output

// 8

// Explanation

// The size of the matrix is 5 rows and 5 columns. It comprises of blocks numbered {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 and 23}. Chintu wishes to extract block 1.

// To extract the blocks with colour code 1, Chintu can do the following.

// First, he will remove the block with colour code 4, followed by the block with colour code 3 and 2 respectively. After that only blocks with colour code 1 can be removed. So, 3 blocks will need to be removed in row 5.
// In the process, block with colour code 7 in row 4 will fall due to gravity, so those must be removed too. So, 1 block will be removed in row 4.
// This chain reaction will cause blocks 8, 9, 10, and 13 to fall as well, requiring their removal too. So, 4 blocks will be removed in rows 1, 2 and 3.
// Thus, in total, Chintu will have to remove 8 blocks (3 + 1 + 4) before he can extract the block with colour code 1.
// Example 2

// Input

// 6 4

// 1 2 3 4

// 5 5 6 6

// 7 8 8 9

// 10 12 13 15

// 10 12 13 15

// 11 12 14 15

// 12

// Output

// 4

// Explanation

// The size of the matrix is 6 rows and 4 columns. It comprises of blocks numbered {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 and 15}. Chintu wishes to extract block 12.

// To extract the blocks with colour code 12, Chintu can do the following.

// First, he will remove the block with colour code 15 in rows 4, 5 and 6. So, this is 1 block.
// The block with colour code 9 in row 3 will fall due to gravity, so he must also remove that block.
// Next, he will remove the block with colour code 14 followed by 13 and 9 in rows 3, 4, 5 and 6. So, this is 3 blocks.
// Thus, in total, Chintu will have to remove 4 blocks (1 + 3) before he can extract the block with colour code 12.