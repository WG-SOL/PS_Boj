#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int GCD(int a, int b) {
    if (b == 0) return a;
    else {
        return GCD(b, a % b);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
    int res = a * b / GCD(a, b);
    cout << res << "\n";
    }
    
}