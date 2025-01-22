// Folded Area
// Problem Description
// Konan is an origamist. Origami is the art of folding paper, and an origamist is a person who practices origami. She is currently working on an origami character-making tutorial, where she needs to draw figures to represent each folding step.

// The sheet will be in square shaped and will be placed on origin towards the first quadrant. Initially, she will draw a line on the origami sheet. This is called as "folding line" through which the paper is going to get folded. Imagine walking along the folding line from starting point to ending point. Split the regions into left and right side regions.The left side region of the folding line will always be folded onto the right side region. The folding line will always separate the sheet into two regions.

// The sheet will have four corners initially. A corner is basically a point where two adjacent sides of the given figure meet. After folding the paper along the folding line, one will get a new polygon. Given the area of the sheet and the cordinates of the folding line, your task is to print all the co-ordinates of the corners of the folded sheet,(resulting polygon).

// Constraints
// 3 < Area of the sheet < 37

// The starting and ending point of the folding line will always be on the edges / corners of the square

// Input
// The first line contains the area of the sheet.

// Second line consists of four space separated integers representing the folding line. First two values representing (x, y) of starting point, second two values representing (x ,y) of ending point.

// Output
// It contains M lines, where M is the number of corners of the polygon resulting after folding

// Each line contains two space separated values representing the (x ,y) of the current corner point

// Restrict the output of points up to two decimal places.

// Print the (x,y) co-ordinates of polygon points obtained after folding in sorted order of x co-ordinate,followed by sorted order of y co-ordinate

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 4

// 0 1 1 2

// Output

// 0.00 0.00

// 0.00 1.00

// 1.00 2.00

// 2.00 0.00

// 2.00 2.00

// Explanation

// The area will be four so the sheet will have sides of 2 units and it will be represented as (0,0), (0,2), (2,2), (2,0). And the folding line be (0,1),(1,2)

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7555b920:image1.pngcom.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7555b920:image2.png

// After folding,

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7555b920:image3.pngcom.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7555b920:image4.png

// since the folded region(left side) lies completely inside the right side, the edges of the new polygon are (0.0),(0,1),(1,2),(2,2),(2,0)

// Hence the output is

// 0.00 0.00

// 0.00 1.00

// 1.00 2.00

// 2.00 0.00

// 2.00 2.00

// Example 2

// Input

// 9

// 0 1 3 2

// Output

// 0.00 0.00

// 0.00 1.00

// 0.75 0.00

// 1.20 -0.60

// 2.00 0.00

// 3.00 0.00

// 3.00 0.75

// 3.00 2.00

// 3.60 1.20

// Explanation:

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7555b920:image5.pngcom.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7555b920:image6.png

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7555b920:image7.pngcom.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7555b920:image8.png

// The picture explains why the output is as depicated above.