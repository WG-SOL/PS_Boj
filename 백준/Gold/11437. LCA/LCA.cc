#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> tree;
vector<int> depth;
vector<int> parent;
vector<bool> seen;

void bfs(int node) {
    queue<int> q;
    q.push(node);
    seen[node] = true;
    int level = 1; //root : 0-level
    int now_size = 1; //현재 level node 수
    int count = 0; // 현재 level에서 처리된 node수 count


    while (!q.empty()) {
        int now = q.front();
        q.pop();
  
        for (int next : tree[now]) {
            if (!seen[next]) {
                seen[next] = true;
                q.push(next);
                parent[next] = now;
                depth[next] = level;
            }
        }
        count++; // 현재 level 처리 완료

        //현재 level이 끝나면 다음 level이 모두 queue에 들어와있음(BFS)
        //다음 level의 node수를 setting하며 level을 증가시키고, count를 다시 0으로 초기화해줌
        if (count == now_size) {
            count = 0;
            now_size = q.size();
            level++;
        }
    }

}

int findLCA(int a, int b) {
    //swap을 통해 어떤 상황에서도 a가 더 큰 깊이가 되도록 변경
    if (depth[a] < depth[b]) {
        swap(a, b);
    }

    while (depth[a] != depth[b]) {
    // depth맞추기
        a = parent[a];
    }

    //1칸씩 올리기
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }

    //올라가서 같아짐
    return a;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    tree.resize(N + 1);
    depth.resize(N + 1);
    parent.resize(N + 1);
    seen.resize(N + 1);

    //tree -> N-1 edge / undirected
    for (int i = 0; i < N - 1; i++) {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    bfs(1); // root
    cin >> M; // query 수

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        int LCA = findLCA(a, b);
        cout << LCA << "\n";
    }

}