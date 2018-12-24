#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Star {
public:
    int x, y;
    int vx, vy;

    Star(int x, int y, int vx, int vy) : x(x), y(y), vx(vx), vy(vy) {}

    bool eqPos(int x, int y) {
        return this->x == x && this->y == y;
    }
};

void printMap(vector<Star> & stars) {
    int minX = stars[0].x, minY = stars[0].y, maxX = stars[0].x, maxY = stars[0].y;
    for (int i = 1; i < stars.size(); i++) {
        minX = min(minX, stars[i].x);
        minY = min(minY, stars[i].y);
        maxX = max(maxX, stars[i].x);
        maxY = max(maxY, stars[i].y);
    }
    for (int i = minY; i <= maxY; i++) {
        for (int j = minX; j <= maxX; j++) {
            bool f = true;
            for (Star star : stars) {
                if (star.eqPos(j, i)) {
                    cout << '#';
                    f = false;
                    break;
                }
            }
            if (f) cout << '.';
        }
        cout << endl;
    }
    cout << minX << ' ' << maxX << ' ' << minY << ' ' << maxY << endl;
}

int main() {
    ifstream instrm("data/10.txt");
    int time = 0;

    vector<Star> stars;

    while (!instrm.eof()) {
        int x, y, vx, vy;
        instrm.ignore(10) >> x;
        instrm.ignore( 2) >> y;
        instrm.ignore(12) >> vx;
        instrm.ignore( 2) >> vy;
        instrm.ignore(2);
        stars.emplace_back(x, y, vx, vy);
    }
    string command;
    while (cin >> command) {
        if (command == "q") break;
        else if (command == "ps")
            for (Star s : stars)
                cout << s.x << ' ' << s.y << ' ' << s.vx << ' ' << s.vy << endl;
        else if (command == "pm")
            printMap(stars);
        else if (command == "m") {
            int t;
            cin >> t;
            for (Star& star : stars) {
                star.x += star.vx * t;
                star.y += star.vy * t;
            }
            time += t;
            cout << "Time " << time << endl;
        }
    }
}