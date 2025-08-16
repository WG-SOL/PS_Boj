#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int DP[101][101];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) DP[i][j] = 0;
            else DP[i][j] = 10000001;
        }
    }


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> DP[i][j];
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int s = 1; s <= N; s++) {
            for (int e = 1; e <= N; e++) {
                if (DP[s][k] == 1 && DP[k][e] == 1) {
                    DP[s][e] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (DP[i][j] == 10000001) cout << "0 ";
            else cout << DP[i][j] << " ";
        }
        cout << "\n";
    }

}   
