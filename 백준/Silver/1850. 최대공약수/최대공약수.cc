#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else {
        return GCD(b, a % b);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long a, b;
    cin >> a >> b;
    int temp = GCD(a, b);

    while (temp > 0) {
        cout << 1;
        temp--;
    }
    
}