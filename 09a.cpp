#include <iostream>
#include <list>
#include <vector>

#define PLAYERS 423
#define MARBLES 7194400

using namespace std;

long long getMaxVectorInt(vector<long long> &t) {
    long long m = 0;
    for (long long x : t) {
        m = max(m, x);
    }
    return m;
}

int main() {
    list<int> t = {0};
    vector<long long> players(PLAYERS, 0);

    auto it = t.begin();
    for (int i = 1; i <= MARBLES; i++) {
        if(i % 1000000 == 0) cout << i << ' ' << getMaxVectorInt(players) << endl;
        if(i % 23 == 0) {
            for (int j = 0; j < 7; j++) {
                if (it == t.begin()) it = t.end();
                it--;
            }
            players[i % PLAYERS] += i + *it;
            it = t.erase(it);
        }
        else {
            for (int j = 0; j < 2; j++) {
                if (it == t.end()) it = t.begin();
                it++;
            }
            it = t.insert(it, i);
        }
    }
    cout << getMaxVectorInt(players);
}