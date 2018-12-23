#include <fstream>
#include <list>
#include <iostream>

using namespace std;

bool match(char a, char b) {
    return abs(a - b) == 'a' - 'A';
}

int main() {
    ifstream instrm("data/05.txt");
    list<char> t;
    char c;
    while (instrm >> c) {
        if (!t.empty() && match(c, t.back())) t.pop_back();
        else t.emplace_back(c);
    }
    cout << t.size() << endl;
    for(char &c : t) cout << c;
}