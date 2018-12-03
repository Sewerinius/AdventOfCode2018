#include <vector>
#include <fstream>
#include <iostream>
#include <set>

using namespace std;

int main () {
    ifstream instrm("data/03.txt");
    vector<vector<int> > map(1000, vector<int>(1000, -1));
    set<int> s;
    int sum = 0;
    while (!instrm.eof()) {
        int id, sx, sy, w, h;
        instrm.ignore(1);
        instrm >> id;
        instrm.ignore(3);
        instrm >> sx;
        instrm.ignore(1);
        instrm >> sy;
        instrm.ignore(2);
        instrm >> w;
        instrm.ignore(1);
        instrm >> h;
        instrm.ignore(1);
        s.insert(id);
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (map[sx + i][sy + j] != -1) {
                    s.erase(map[sx + i][sy + j]);
                    s.erase(id);
                }
                map[sx + i][sy + j] = id;
            }
        }
    }
    for (auto it : s) {
        cout << it << ' ';
    }
}