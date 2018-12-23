#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

#define SIZE 1000

class Point {
public:
    int id, x, y, p;

    Point(int x, int y, int p) : id(id), x(x), y(y), p(p) {}
};

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    ifstream instrm("data/06.txt");
    vector<Point> points;
    set<int> infPoints;
    int x, y;
    while (instrm >> x) {
        instrm.ignore();
        instrm >> y;
        points.emplace_back(x, y, 0);
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int minD = 3 * SIZE;
            int minID = -1;
            bool eq;
            for (int id = 0; id < points.size(); id++) {
                int d = dist(i, j, points[id].x, points[id].y);

                if (d == minD) eq = true;
                else if (d < minD) {
                    minD = d;
                    minID = id;
                    eq = false;
                }
            }
            if (i == 0 || j == 0 || i == SIZE - 1 || j == SIZE - 1) infPoints.insert(minID);
            if (!eq) {
                points[minID].p++;
            }
        }
    }

    int maxP = 0;
    for (int i = 0; i < points.size(); i++) {
        if (infPoints.count(i) == 0) {
            maxP = max(maxP, points[i].p);
        }
    }
    cout << maxP;
}