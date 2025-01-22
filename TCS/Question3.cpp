#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct Cell {
    int row, col, steps;
    Cell(int r, int c, int s) : row(r), col(c), steps(s) {}
};

bool isValid(int row, int col, int N, int M) {
    return row >= 0 && row < N && col >= 0 && col < M;
}

bool isStable(int row, int col, const vector<vector<int>>& grid, int N) {
    return row == N - 1 || grid[row + 1][col] == 1;
}

int bfs(const vector<vector<int>>& grid, int startRow, int startCol, int destRow, int destCol) {
    int N = grid.size(), M = grid[0].size();
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<Cell> q;

    q.push(Cell(startRow, startCol, 0));
    visited[startRow][startCol] = true;

    while (!q.empty()) {
        Cell current = q.front();
        q.pop();

        int row = current.row, col = current.col, steps = current.steps;

        // Check if destination is reached and is stable
        if (row == destRow && col == destCol && isStable(row, col, grid, N)) {
            return steps;
        }

        // Apply gravity
        int newRow = row;
        while (isValid(newRow + 1, col, N, M) && grid[newRow + 1][col] == 0) {
            newRow++;
        }

        if (!visited[newRow][col]) {
            visited[newRow][col] = true;
            q.push(Cell(newRow, col, steps + 1));
        }

        // Try moving upwards via lifts
        for (int liftRow = row - 1; liftRow >= 0 && grid[liftRow][col] == 1; liftRow--) {
            if (!visited[liftRow][col]) {
                visited[liftRow][col] = true;
                q.push(Cell(liftRow, col, steps + 1));
            }
        }

        // Horizontal movement if stable
        if (isStable(newRow, col, grid, N)) {
            if (isValid(newRow, col + 1, N, M) && !visited[newRow][col + 1]) {
                visited[newRow][col + 1] = true;
                q.push(Cell(newRow, col + 1, steps + 1));
            }
            if (isValid(newRow, col - 1, N, M) && !visited[newRow][col - 1]) {
                visited[newRow][col - 1] = true;
                q.push(Cell(newRow, col - 1, steps + 1));
            }
        }
    }

    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int startRow, startCol, destRow, destCol;
    cin >> startRow >> startCol >> destRow >> destCol;

    if (grid[destRow][destCol] == 1 || !isStable(destRow, destCol, grid, N)) {
        cout << "Impossible" << endl;
        return 0;
    }

    int result = bfs(grid, startRow, startCol, destRow, destCol);
    cout << (result == -1 ? "Impossible" : to_string(result)) << endl;


    return 0;
}


// Gravity And Lifts
// Problem Description
// Nani wants to create a game like Snakes and Ladders, but without using numbers and dice. The game consists of a board of size N x M, where each cell can either contain a lift or be empty.

// Nani is currently in a specific cell and wants to move to another cell. If Nani lands in an empty cell that has a lift directly below it, it is called a stable cell, and Nani can remain there. However, if the cell does not have a lift below it, he will slide down due to gravity until he reaches a cell that has a lift below it. All cells in the last row are stable cells by default. Nani can move upward through cells using lifts. Nani cannot traverse horizontally, except when in the last row or when supported by cells with lift below his feet.

// For example, if the current cell has lifts extending to two cells directly above it and then an empty cell, he can use these lifts to move to the empty cell situated above the two lift-equipped cells. Without proper lifts, Nani cannot move upward through the cells.

// Given Nani's current location and the destination cell, find the minimum total number of empty cells and lifts Nani needs to use to reach the destination from his current location.

// Constraints
// 1 <= N, M <= 10

// Input
// First line consists of two space separated integers denoting the value of N and M.

// The following N lines contain M space-separated integers, each either 0 or 1. Here, 0 indicates an empty cell, and 1 indicates a cell with a lift.

// The N+2nd line consists of two space-separated integers indicating the row and column (zero-indexed) of Nani's current cell.

// The N+3rd line consists of two space-separated integers indicating the row and column (zero-indexed) of the destination cell where Nani wants to go.

// Output
// Output a single integer representing the minimum number of empty cells and lifts Nani needs to use to reach the destination cell. If reaching the destination is impossible because it is a lift or an unstable cell, print "Impossible".

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 4 6

// 0 1 0 0 1 0

// 0 0 0 0 0 0

// 0 1 0 1 1 0

// 0 0 0 0 0 0

// 1 0

// 1 3

// Output

// 6

// Explanation

// The given board looks like below where the green cell is Nani's current location, and the red cell is destination.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@293cde83:image1.png

// From the current cell, Nani will be moved down by two cells due to gravity. Cells visited = 2

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@293cde83:image2.png

// Next, move 3 cells towards the right. Cells visited = 2 + 3 = 5

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@293cde83:image3.png

// Use the lift and climb up to the above cell which is the destination itself. Hence lifts climbed = 1

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@293cde83:image4.png

// Hence, total cells + lifts used = 5+1 = 6

// There is no other minimum possibility. Hence print 6.

// Example 2

// Input

// 5 3

// 1 0 0

// 0 1 0

// 0 0 0

// 0 0 1

// 0 0 0

// 1 2

// 2 1

// Output

// Impossible

// Explanation

// The given board looks like below where the green cell is Nani's current location, and the red cell is destination.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@293cde83:image5.png

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@293cde83:image6.png

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@293cde83:image7.png

// Here the destination cell is not a stable cell. So even after reaching that cell, due to gravity, Nani will slide down. Hence, it's impossible to remain in the cell.

// Example 3

// Input

// 7 5

// 0 0 0 0 0

// 0 0 1 1 1

// 0 0 0 0 0

// 0 0 0 0 1

// 0 0 0 0 1

// 0 0 1 1 1

// 0 0 0 0 0

// 6 0

// 0 2

// Output

// 11

// Explanation

// The given board looks like below where the green cell is Nani's current cell, and the red cell is destination.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@293cde83:image8.png

// Move 4 cells towards the right. Total cells reached = 4.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@293cde83:image9.png

// With the help of the 3 lifts, climb up and reach the cell numbered 8. Total lifts used = 3, total cells = 4+1 = 5

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@293cde83:image10.png

// Then take the lift at cell numbered 9 and go to cell 10. Then move two cells left.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@293cde83:image11.png

// Total cells used = 5 + 2 = 7

// Total lifts used = 3 + 1 = 4

// Total lifts + cells used = 4 + 7 = 11