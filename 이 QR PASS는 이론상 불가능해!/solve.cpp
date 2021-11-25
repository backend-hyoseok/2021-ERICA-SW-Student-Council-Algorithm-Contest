#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[100][100];

int dist[100][100];
bool visited[100][100];
int dist_building[100][100];
vector<pair<int, pair<int, int>>> v[10000];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int time_delta_calc(int a, int b) {
    int after = b % 100 + b / 100 * 60;
    int before = a % 100 + a / 100 * 60;

    return after - before;
}

int main() {
    cin >> n >> m;

    vector<pair<int, int>> building;

    for(int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        for(int j = 0 ; j < m ; j++) {
            a[i][j] = s[j] - '0';
            if(a[i][j] == 2) building.push_back({i, j});
        }
    }

    for(int i = 0 ; i < building.size() ; i++) {
        memset(visited, 0, sizeof(visited));
        visited[building[i].first][building[i].second] = true;

        queue<pair<pair<int, int>, int>> q;

        q.push({{building[i].first, building[i].second}, 0});

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();

            dist[x][y] = d;
            for(int i = 0 ; i < 4 ; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != 1 && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, d + 1});
                }
            }
        }
        
        for(int j = 0 ; j < building.size() ; j++) {
            dist_building[i][j] = dist[building[j].first][building[j].second];
        }
    }

    int k;
    cin >> k;

    for(int i = 0 ; i < k ; i++) {
        int number, time, building;
        cin >> number >> time >> building;

        v[number-20200000].push_back({time, {building, i}});
    }

    vector<pair<int, int>> ans;

    for(int i = 0 ; i < 10000 ; i++){
        for(int j = 1 ; j < v[i].size() ; j++){
            int time_before = v[i][j-1].first;
            int time = v[i][j].first;

            int building_before = v[i][j-1].second.first;
            int building = v[i][j].second.first;

            int id_before = v[i][j-1].second.second;
            int id = v[i][j].second.second;

            int time_delta = time_delta_calc(time_before, time);

            if(time_delta < dist_building[building_before][building]) {
                ans.push_back({id_before, id});
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i = 0 ; i < ans.size() ; i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}