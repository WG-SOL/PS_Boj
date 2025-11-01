#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, L;
    cin >> N >> L;
    deque<pair<int, int>> deq;

    for (int i = 0; i < N; i++) {
        int now;
        cin >> now;

        while (deq.size() && deq.back().second > now) {
            deq.pop_back();
        }
        deq.push_back(make_pair(i, now)); // index, value

        if (deq.front().first <= i - L) { // out of sliding range
            deq.pop_front();
        }
        cout << deq.front().second << ' ';
    }
    
}