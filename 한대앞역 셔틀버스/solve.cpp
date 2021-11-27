#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    pair<int, int> a[n];
    for(int i = 0 ; i < n ; i++) {
        int h, m, s;
        cin >> h >> m >> s >> a[i].second;
        a[i].first = h * 3600 + m * 60 + s;
    }

    int m;
    cin >> m;

    pair<int, int> b[m];
    for(int i = 0 ; i < m ; i++) {
        int hh, mm, ss;
        cin >> hh >> mm >> ss >> b[i].second;
        b[i].first = hh * 3600 + mm * 60 + ss;
    }

    long long int remain = 0;
    long long int ans = 0;
    int cursor = 0;
    for(int i = 0 ; i < m ; i++) {
        while(cursor < n && b[i].first >= a[cursor].first) {
            remain += a[cursor].second;
            cursor++;
        }
        remain -= b[i].second;
        remain = max(0LL, remain);
        ans += remain;
    }
    cout << ans << '\n';
}