#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;




int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    long long Min, Max;
    cin >> Min >> Max;

    long long v[10000001] = {0};

    for (int i = 2; i < 10000001; i++) {
        v[i] = i;
    }

    for (int i = 2; i <= sqrt(10000001); i++) {
        if (v[i] == 0) continue;

        for (int j = i + i; j < 10000001; j = j + i) {
            v[j] = 0;
        }
    }

    int count = 0;

    for (int i = 2; i < 10000001; i++) {
        if (v[i] != 0) {
            long long temp = v[i];

            while ((double)v[i] <= (double)Max / (double)temp) {
                if ((double)v[i] >= (double)Min / (double)temp) {
                    count++;
                }
                temp = temp * v[i];
            }
        }
    }


    cout << count;

}