#include<bits/stdc++.h>

using namespace std;

// N^2log(N)

int main() {
    int n, k;
    cin >> n >> k;

    bool ans = false;

    string a[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }

    vector<pair<char, char>> start_end;
    for(int i = 0 ; i < n ; i++) {
        start_end.push_back({a[i][0], a[i][a[i].length() - 1]});
    }

    // N log(N)
    sort(start_end.begin(), start_end.end());

    // N
    int same_count = 0, pair_count = 0;
    for(int i = 0 ; i < n ; i++) {
        pair<char, char> a = start_end[i];
        if(a.first == a.second) {
            same_count++;
        }else if(find(start_end.begin(), start_end.end(), make_pair(a.second, a.first)) != start_end.end()) {
            pair_count++;
        }
    }

    // N^2 log(N)
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            pair<char, char> a = start_end[i];
            pair<char, char> b = start_end[j];

            ans |= find(start_end.begin(), start_end.end(), make_pair(a.second, b.first)) != start_end.end();
        }
    }

    if(k == 1) {
        if(same_count >= 1) cout << "YES";
        else cout << "NO";
    }else if(k == 2) {
        if(same_count >= 2 || pair_count >= 1) cout << "YES";
        else cout << "NO";
    }else {
        if(ans || (same_count >= 1 && pair_count >= 1)) cout << "YES";
        else cout << "NO";
    }
}