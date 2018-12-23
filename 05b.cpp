#include <fstream>
#include <list>
#include <iostream>

using namespace std;

bool match(char a, char b) {
    return abs(a - b) == 'a' - 'A';
}

int run(list<char> &t, char c = 0) {
    for(auto it = t.begin(); it != t.end();) {
        if (*it == c || *it == c - 'a' + 'A') it = t.erase(it);
        else if (it != t.begin() && match(*it, *prev(it))) it = t.erase(prev(it), next(it));
        else it++;
    }
    return t.size();
}

int main() {
    ifstream instrm("data/05.txt");
    list<char> t;
    char c;
    while (instrm >> c) {
        if (!t.empty() && match(c, t.back())) t.pop_back();
        else t.emplace_back(c);
    }
    int mins = t.size();
    for(c = 'a'; c <= 'z'; c++) {
        list<char> t2(t);
        int s = run(t2, c);
        if (s < mins) mins = s;
        cout << c << ' ' << s << ' ';
        for (char &x : t2) cout << x;
        cout << endl;
    }
    cout << mins;
}