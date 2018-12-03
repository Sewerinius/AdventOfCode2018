#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int main () {
    ifstream instrm("data/03.txt");
    vector<vector<int> > map(1000, vector<int>(1000, 0));
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
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                map[sx + i][sy + j]++;
                if (map[sx + i][sy + j] == 2) sum++;
            }
        }
    }
    cout << sum;
}