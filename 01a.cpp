#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    ifstream instrm("data/01.txt");
    int a, sum = 0;
    while (instrm >> a) {
        sum += a;
    }
    cout << sum << endl;
}