#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
vector<vector<int>> tree;
vector<int> depth;
int kmax; // 추가
int parent[21][100001]; //2^k번째 노드저장
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
                parent[0][next] = now;
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
    //이번엔 더 깊은 깊이가 b가 되도록 변경
    if (depth[a] > depth[b]) {
        swap(a, b);
    }

    //Depth 맞추기
    for (int k = kmax; k >= 0; k--) {
        if (pow(2, k) <= depth[b] - depth[a]) { // 차이보다 작은 max k
            if (depth[a] <= depth[parent[k][b]]) {
                b = parent[k][b]; // 2^k씩 이동
            }
        }
    }

    //LCA find
    for (int k = kmax; k >= 0 && a != b; k--) {
        if (parent[k][a] != parent[k][b]) {
            a = parent[k][a];
            b = parent[k][b]; // a!=b면, a와 b를 그 k의 2^k 부모로 이동
        }
    }


    int LCA = a; // a==b인 경우

    if (a != b) { // a!=b인 경우에는
        LCA = parent[0][LCA]; //바로 위
    }
    return LCA;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    tree.resize(N + 1);
    depth.resize(N + 1);
    seen.resize(N + 1);

    //tree -> N-1 edge / undirected
    for (int i = 0; i < N - 1; i++) {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    int temp = 1;
    kmax = 0;
    while (temp <= N) { //최대 가능 depth 구하기
        temp <<= 1;
        kmax++;
    }

    bfs(1); // root부터 bfs -> DP Init

    //점화식
    for (int k = 1; k <= kmax; k++) {
        for (int n = 1; n <= N; n++) {
            parent[k][n] = parent[k - 1][parent[k - 1][n]];
        }
    }

    cin >> M; //query

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        int LCA = findLCA(a, b);
        cout << LCA << "\n";
    }

}