#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


bool isPal(int number) {
    string temp = to_string(number);
    char const* c_temp = temp.c_str();
    int s = 0;
    int e = temp.size() - 1;

    while (s < e) {
        if (c_temp[s] != c_temp[e]) {
            return false;
        }
        s++;
        e--;
    }

    return true;

}


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int N;
    cin >> N;

    int v[10000001];

    for (int i = 2; i < 10000001; i++) {
        v[i] = i;
    }

    for (int i = 2; i <= sqrt(10000001); i++) {
        if (v[i] == 0) continue;

        for (int j = i + i; j < 10000001; j = j + i) {
            v[j] = 0;
        }
    }

    int i = N;

    while (true) {
        if (v[i] != 0) {
            int result = v[i];
            if (isPal(result)) {
                cout << result << "\n";
                break;
            }
        }
        i++;
    }

}

