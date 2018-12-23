#include <iostream>
#include <fstream>
#include <queue>
#include <set>

using namespace std;

class Vertex {
public:
    set<char> from;
    set<char> to;
};

int main() {
    ifstream instrm("data/07.txt");

    vector<Vertex> t('Z'-'A' + 1);
    priority_queue<char, vector<char>, greater<> > queue;
    while (!instrm.eof()) {
        char fr, to;
        instrm.ignore(5) >> fr;
        instrm.ignore(29) >> to;
        instrm.ignore(11);
        t[fr-'A'].to.insert(to);
        t[to-'A'].from.insert(fr);
    }
    for (char c = 'A'; c <= 'Z'; c++)
        if (t[c-'A'].from.empty())
            queue.push(c);
    while (!queue.empty()) {
        char c = queue.top(); queue.pop();
        if(t[c-'A'].from.empty()) {
            cout << c;
            for (char c1 : t[c-'A'].to) {
                t[c1-'A'].from.erase(c);
                if (t[c1-'A'].from.empty()) queue.push(c1);
            }
        }
    }
}