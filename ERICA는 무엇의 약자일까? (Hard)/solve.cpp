#include<bits/stdc++.h>

using namespace std;

// 26^K
int k;
int go[26][26];

bool solve(int depth, int now, int start) {
    bool result = false;

    if(depth == k - 1) {
        return go[now][start] > 0;
    }

    for(int i = 0 ; i < 26 ; i++) {
        if(go[now][i] == 0) continue;

        go[now][i]--;
        result |= solve(depth + 1, i, start);
        go[now][i]++;
    }
    
    return result;
}

int main() {
    int n;
    cin >> n >> k;

    string s[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> s[i];
    }

    for(int i = 0 ; i < n ; i++) {
        go[s[i][0]-'a'][s[i][s[i].length() - 1]-'a']++;
    }

    bool ans = false;

    for(int i = 0 ; i < 26 ; i++) {
        ans |= solve(0, i, i);
    }

    if(ans) cout << "YES";
    else cout << "NO";
}