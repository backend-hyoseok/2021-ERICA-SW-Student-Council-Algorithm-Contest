#include<bits/stdc++.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    int n, m;
    cin >> n >> m;

    int a[n][m];
    int student = 0;
    for(int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        for(int j = 0 ; j < m ; j++) {
            a[i][j] = s[j] - '0';
            student += a[i][j];
        }
    }

    int ans = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(a[i][j] == 0) continue;
            int count = 0;
            for(int k = 0 ; k < 4 ; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                
                count += a[nx][ny];
            }
            
            if(count != 0) ans++;
        }
    }

    cout << ans << '\n';

    int max_count = (n * m + 1) / 2;

    if(student <= max_count) cout << "YES";
    else cout << "NO";
}