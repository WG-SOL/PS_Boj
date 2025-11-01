#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using tree = vector<vector<int>>;

tree T;
vector<bool> seen;
vector<int> parent;

void DFS(int node) {
    seen[node] = true;

    for (auto next : T[node]) {
        if (seen[next] == false) {
            parent[next] = node;
            DFS(next);
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    T.resize(N + 1);
    seen.resize(N + 1, false);
    parent.resize(N + 1);

    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        T[s].push_back(e);
        T[e].push_back(s);
    }

    DFS(1);

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }


}