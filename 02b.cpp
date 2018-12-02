#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool compare(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    bool diff = false;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            if (diff) return false;
            else diff = true;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    ifstream instrm("data/02.txt");
    string s;
    vector <string> strings;
    while (instrm >> s) {
        for(string &s1 : strings) {
            if (compare(s, s1)) {
                cout << s << '\n' << s1;
                return 0;
            }
        }
        strings.push_back(s);
    }
}