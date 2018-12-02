#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    ifstream instrm("data/02.txt");
    string s;
    int c2 = 0, c3 = 0;
    while (instrm >> s) {
        vector<int> letters('z'-'a' + 1, 0);
        for (char &c : s) letters[c - 'a']++;
        for (int &l : letters) if (l == 2) {
                c2++;
                break;
            }
        for (int &l : letters) if (l == 3) {
                c3++;
                break;
            }
    }
    cout << c2 << ' ' << c3 << ' ' << c2 * c3 << endl;
}