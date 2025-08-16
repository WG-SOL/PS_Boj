#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int DP[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M; //사람수, 관계수
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) DP[i][j] = 0;
            else DP[i][j] = 10000001;
        }
    }

    for (int i = 1; i <= M; i++) {
        int s, e;
        cin >> s >> e;
        DP[s][e] = 1;
        DP[e][s] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int s = 1; s <= N; s++) {
            for (int e = 1; e <= N; e++) {
                if (DP[s][e] > DP[s][k] + DP[k][e]) {
                    DP[s][e] = DP[s][k] + DP[k][e];
                }
            }
        }
    }

    int minimum = INT_MAX;
    int answer = 0;

    for (int i = 1; i <= N; i++) {
        int temp = 0;
        for (int j = 1; j <= N; j++) {
            temp += DP[i][j];
        }

        if (minimum > temp) {
            minimum = temp;
            answer = i;
        }

    }

    cout << answer;


}   
