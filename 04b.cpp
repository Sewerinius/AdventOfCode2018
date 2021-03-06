#include <fstream>
#include <utility>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

class Guard {
public:
    vector<pair<int, int> > sleeps;
    int sum = 0;

    int mostMinute(int &a) {
        vector<int> t(60, 0);
        for (auto x : sleeps) {
            t[x.first]++;
            t[x.second]--;
        }
        int maxSleeep = t[0];
        int maxMinute = 0;
        for (int i = 1; i < 60; i++) {
            t[i] += t[i-1];
            if (t[i] > maxSleeep) {
                maxSleeep = t[i];
                maxMinute = i;
            }
        }
        a = t[maxMinute];
        return maxMinute;
    };
};

int main() {
    map<int, Guard> m;
    ifstream instrm("data/04.txt");
    string s;
    int currentGuard;
    while (getline(instrm, s)) {
        int month, day, hour, minute;
        stringstream sstrm(s);
        (((sstrm.ignore(6) >> month).ignore(1) >> day >> hour).ignore(1) >> minute).ignore(8);
        char c;
        sstrm >> c;
        if (c == '#') {
            int id;
            sstrm >> id;
            m[id];
            currentGuard = id;
        } else {
            int endMinute;
            getline(instrm, s);
            sstrm.str(s);
            (((sstrm.ignore(6) >> month).ignore(1) >> day >> hour).ignore(1) >> endMinute).ignore(8);
            m[currentGuard].sum += endMinute - minute;
            m[currentGuard].sleeps.emplace_back(minute, endMinute);
        }
    }
    int maxSleepT = 0;
    int v;
    for (auto &x : m) {
        int id = x.first;
        int times;
        int minute = x.second.mostMinute(times);
        if (times > maxSleepT) {
            maxSleepT = times;
            v = id * minute;
        }
    }
    cout << v;
}