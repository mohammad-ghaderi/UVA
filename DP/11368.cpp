#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

const int inf = 1e5;

void solve() {

    int m;
    cin >> m;
    pair<int,int> dolls[m]{};
    for (int i = 0; i < m; i++) {
        cin >> dolls[i].first >> dolls[i].second;
    }

    sort(dolls, dolls + m, [](pair<int,int>&a, pair<int,int>&b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });

    vector<int> c{};
    c.push_back(inf);
    int ans = 0;

    for (int i = 0; i < m; i++) {
        int idx = -1, value = inf;
        for (int j = 0; j < c.size(); j++) {
            if (c[j] < value and c[j] > dolls[i].second) value = c[j], idx = j;
        }
        if (idx == -1) {
            c.push_back(dolls[i].second);
            ans++;
        } else {
            c[idx] = dolls[i].second;
        }
    }

    cout << ans << endl;

}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}