#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point on the rectangle to the circle's center
        // by clamping the center coordinates to the rectangle boundaries
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        // Calculate horizontal and vertical distances
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        // Check if Euclidean distance squared is within radius squared
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};

int main() {
    Solution solver;

    // Test Case 1: Circle and rectangle share point (1, 0)
    int radius1 = 1, xCenter1 = 0, yCenter1 = 0;
    int x1_1 = 1, y1_1 = -1, x2_1 = 3, y2_1 = 1;
    cout << "Test 1: " << (solver.checkOverlap(radius1, xCenter1, yCenter1, x1_1, y1_1, x2_1, y2_1) ? "true" : "false")
         << endl;

    // Test Case 2: Completely separated
    int radius2 = 1, xCenter2 = 1, yCenter2 = 1;
    int x1_2 = 1, y1_2 = -3, x2_2 = 2, y2_2 = -1;
    cout << "Test 2: " << (solver.checkOverlap(radius2, xCenter2, yCenter2, x1_2, y1_2, x2_2, y2_2) ? "true" : "false")
         << endl;

    // Test Case 3: Overlapping corner/edge
    int radius3 = 1, xCenter3 = 0, yCenter3 = 0;
    int x1_3 = -1, y1_3 = 0, x2_3 = 0, y2_3 = 1;
    cout << "Test 3: " << (solver.checkOverlap(radius3, xCenter3, yCenter3, x1_3, y1_3, x2_3, y2_3) ? "true" : "false")
         << endl;

    return 0;
}