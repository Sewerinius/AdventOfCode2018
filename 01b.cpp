#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    ifstream instrm("data/01.txt");
    int a, sum = 0;
    vector<int> t;
    unordered_set<int> set;
    while (instrm >> a) {
        t.push_back(a);
    }
    int i = 0;
    while (set.count(sum) == 0) {
        set.insert(sum);
        sum += t[i++];
        if (i >= t.size()) i = 0;
    }
    cout << sum << endl;
}