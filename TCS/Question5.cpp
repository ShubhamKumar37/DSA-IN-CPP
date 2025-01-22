#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to calculate the area of the polygon using the shoelace formula
double polygonArea(const vector<pair<int, int>>& vertices) {
    int n = vertices.size();
    double area = 0;
    
    // Apply shoelace formula
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;  // next vertex (wrap around to the first)
        area += vertices[i].first * vertices[j].second;
        area -= vertices[j].first * vertices[i].second;
    }
    area = abs(area) / 2.0;  // absolute value and divide by 2
    return area;
}

int main() {
    int N;  // number of vertices of the polygon (wall)
    cin >> N;

    vector<pair<int, int>> vertices(N);
    for (int i = 0; i < N; i++) {
        cin >> vertices[i].first >> vertices[i].second;
    }

    int M;  // dimension of the square brush
    cin >> M;

    // Step 1: Calculate the area of the wall
    double wallArea = polygonArea(vertices);
    
    // Step 2: Calculate the area of the brush
    int brushArea = M * M;
    
    // Step 3: Calculate minimum number of presses
    int presses = ceil(wallArea / brushArea);
    
    cout << presses << endl;
    
    return 0;
}


// Count Press
// Problem Description
// James is a painter who uses the latest block-shaped brush. This brush can simply be dipped into paint and pressed onto the wall to get that area of the wall painted.

// The brush is an M×M block. Each press covers MxM block of the wall (if present).

// Consider a wall of 4x4 and a brush of size 2x2 as shown below.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@3113a37:image1.png

// A press would cover a 2x2 square of the wall. Four presses are required to cover the above entire wall.

// A wall of 4x1 is shown below.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@3113a37:image2.png

// Using a 2x2 brush, 2 presses will be required to cover the entire wall.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@3113a37:image3.png

// One day, James received an order to paint this rectilinear shaped wall.

// Find the minimum number of presses James needs to do to cover the wall, given that he is having the MxM brush.

// Here "rectilinear shaped" term used to convey that the edges of the wall be either vertical or horizontal. There will be no cross-over or circular/ cylindrical walls.

// Constraints
// 0 < N < 20

// 0 < M < 5

// 0 < Area of the given wall / M < 7

// Input
// First line consists of an integer N, denoting the number of vertices of the wall.

// Next N lines consist of two space separated integers denoting the x and y coordinate of each vertex in anticlockwise order.

// Last line consists of an integer denoting the dimension M of the painting brush or painting block.

// Output
// Output a single integer representing the minimum number of times James needs to press the brush to paint the whole wall uniformly.

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 10
// 0 2
// 0 1
// 1 1
// 1 0
// 2 0
// 2 2
// 3 2
// 3 3
// 1 3
// 1 2
// 2

// Output

// 2

// Explanation

// The given wall is shown below.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@3113a37:image4.png

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@3113a37:image5.pngcom.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@3113a37:image6.png

// We can see that 2 presses are sufficient to paint the given wall. Hence, print 2.

// Example 2

// Input

// 4

// 0 0

// 8 0

// 8 1

// 0 1

// 2

// Output

// 4

// Explanation

// The below image will represent the given input.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@3113a37:image7.pngcom.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@3113a37:image8.png

// With a 2x2 shape it requires minimum 4 press to paint the entire wall. The upper half of the Brush is not depicted in the image above.