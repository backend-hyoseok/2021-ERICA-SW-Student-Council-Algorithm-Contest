#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    if(n * k <= m * 100) cout << "YES";
    else cout << "NO";
}