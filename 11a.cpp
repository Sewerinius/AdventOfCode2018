#include <iostream>
#include <vector>

#define SERIAL 3214

using namespace std;

int main() {
    vector<vector<int> > t(300, vector<int>(300, 0));
    for (int i = 1; i <= 300; i++) {
        for (int j = 1; j <= 300; j++) {
            t[i - 1][j - 1] = ((i + 10) * j + SERIAL) * (i + 10) / 100 % 10 - 5;
        }
    }
    //cout << t[2][4] << endl;
    int maxP = 0;
    int maxX = 0;
    int maxY = 0;
    for (int i = 0; i < 297; i++) {
        for (int j = 0; j < 297; j++) {
            int p = t[i][j]     + t[i + 1][j]     + t[i + 2][j]     +
                    t[i][j + 1] + t[i + 1][j + 1] + t[i + 2][j + 1] +
                    t[i][j + 2] + t[i + 1][j + 2] + t[i + 2][j + 2];
            if (p > maxP) {
                maxP = p;
                maxX = i + 1;
                maxY = j + 1;
            }
        }
    }
    cout << maxP << ' ' << maxX << ',' << maxY;
}