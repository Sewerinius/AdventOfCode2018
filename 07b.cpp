#include <iostream>
#include <fstream>
#include <queue>
#include <set>

#define WORKERS 5

using namespace std;

class Vertex {
public:
    set<char> from;
    set<char> to;
};

class Job {
public:
    char c;
    int t;

    Job(char c, int t) : c(c), t(t) {}

    bool operator<(const Job &rhs) const {
        return t < rhs.t;
    }

    bool operator>(const Job &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Job &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Job &rhs) const {
        return !(*this < rhs);
    }
};

int main() {
    ifstream instrm("data/07.txt");

    vector<Vertex> t('Z'-'A' + 1);
    priority_queue<char, vector<char>, greater<> > queue;
    priority_queue<Job, vector<Job>, greater<> > jobs;
    int time = 0;
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
    while (!queue.empty() || !jobs.empty()) {
        if(!queue.empty() && jobs.size() < WORKERS) {
            char c = queue.top(); queue.pop();
            jobs.emplace(c, time + 61 + (c - 'A'));
        } else {
            Job j = jobs.top(); jobs.pop();
            char c = j.c;
            time = j.t;
            for (char c1 : t[c - 'A'].to) {
                t[c1 - 'A'].from.erase(c);
                if (t[c1 - 'A'].from.empty()) queue.push(c1);
            }
        }
    }
    cout << time;
}