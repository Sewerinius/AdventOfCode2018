#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

#define SIZE 1000
#define DIST_SUM 10000

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

    int p = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int td = 0;
            for (int id = 0; id < points.size(); id++) {
                td += dist(i, j, points[id].x, points[id].y);
            }
            if (td < DIST_SUM) p++;
        }
    }

    cout << p;
}