#include <iostream>
#include <vector>
#include <fstream>

#define GENERATIONS 50000000000

using namespace std;

class Rule {
public:
    vector<bool> pattern;
    bool result;

    bool match(vector<bool> &t, long long mid) {
        return equal(pattern.begin(), pattern.end(), t.begin() + mid - 2);
    }


    Rule(const string &p, char result) : result(result == '#') {
        for(const char & c : p)
            pattern.push_back(c == '#');
    }
};

long long getSum(vector<bool> &t, long long offset) {
    long long sum = 0;
    for (long long i = 0; i < t.size(); i++) {
        if (t[i]) sum += i - offset;
    }
    return sum;
}

int main() {
    ifstream instrm("data/12.txt");
    vector<bool> t;
    vector<Rule> rules;

    string s;
    instrm.ignore(15) >> s;
    t.reserve(s.size());
    for(char & c : s) {
        t.push_back(c == '#');
    }
    instrm.ignore();
    while (!instrm.eof()) {
        char c;
        instrm >> s;
        instrm.ignore(3) >> c;
        rules.emplace_back(s, c);
    }

    long long offset = 0;
    long long lastSum = getSum(t, offset);
    for (long long i = 0; i < GENERATIONS; i++) {
        for (int j = 0; j < 4; j++) {
            if (t[j] == true) {
                while (j++ < 4) {
                    t.insert(t.begin(), false);
                    offset++;
                }
            }
        }
        for (int j = 0; j < 4; j++) {
            if (t[t.size()-j-1] == true) {
                while (j++ < 4) {
                    t.push_back(false);
                }
            }
        }
        vector<bool> t2(t);
        for (long long j = 2; j < t.size()-2; j++) {
            for(Rule rule : rules) {
                if(rule.match(t, j)) {
                    t2[j] = rule.result;
                    break;
                }
            }
        }
        t = t2;
        long long sum = getSum(t, offset);
        cout << i << '\t' << sum << '\t' << sum - lastSum << endl;
        lastSum = sum;
    }

    cout << getSum(t, offset);
}