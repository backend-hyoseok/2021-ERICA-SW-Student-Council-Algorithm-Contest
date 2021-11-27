#include<bits/stdc++.h>

using namespace std;

int main() {
    string s[3] = {"SANG", "HAN", "JUNG"};
    pair<int, int> a[3];
    for(int i = 0 ; i < 3 ; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + 3);

    cout << "GO " << s[a[0].second];
}