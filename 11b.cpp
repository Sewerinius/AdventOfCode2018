#include <iostream>
#include <vector>

#define SERIAL 3214

using namespace std;

int main() {
    vector<vector<int> > t(301, vector<int>(301, 0));
    t[0][0] = (11 + SERIAL) * 11 / 100 % 10 - 5;
    for (int i = 1; i <= 300; i++) {
        for (int j = 1; j <= 300; j++) {
            t[i][j] = t[i][j - 1] + t[i - 1][j] - t[i - 1][j - 1] +
                      ((i + 10) * j + SERIAL) * (i + 10) / 100 % 10 - 5;
        }
    }
    int maxP = 0;
    int maxX = 0;
    int maxY = 0;
    int maxN = 0;
    for (int n = 0; n < 300; n++) {
        for (int i = 1; i <= 300-n; i++) {
            for (int j = 1; j <= 300-n; j++) {
                int p = t[i + n][j + n] - t[i-1][j+n] - t[i+n][j-1] + t[i-1][j-1];
                if (p > maxP) {
                    maxP = p;
                    maxX = i;
                    maxY = j;
                    maxN = n+1;
                }
            }
        }
    }
    cout << maxP << ' ' << maxX << ',' << maxY << ',' << maxN;
}