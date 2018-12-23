#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define SIZE 1000
#define DIST_SUM 10000

class Node {
public:
    vector<Node> nodes;
    vector<int> metadata;
    int v = 0;

    Node(ifstream &instrm) {
        int n, m;
        instrm >> n >> m;
        while (n--) {
            nodes.emplace_back(instrm);
        }
        while (m--) {
            int tmp;
            instrm >> tmp;
            metadata.emplace_back(tmp);
        }
    }

    int getMetadataSum() {
        if (v != 0)
            return v;
        int s = 0;
        if (nodes.empty()) {
            for (int m : metadata) s += m;
        } else {
            for (int m : metadata) {
                if (m <= nodes.size())
                    s += nodes[m - 1].getMetadataSum();
            }
        }

        v = s;
        return s;
    };
};

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    ifstream instrm("data/08.txt");
    Node root(instrm);
    cout << root.getMetadataSum();
}