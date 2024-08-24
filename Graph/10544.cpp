#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int inf = 1e9;
const int SIZE = 27;
vector<int> g[SIZE]{};
bool am[SIZE][SIZE]{};
int mem[SIZE]{};
int n, m;

int dfs(int cur) {
    if (g[cur].size() == 0) return mem[cur] = 1;
    if (~mem[cur]) return mem[cur];

    int cnt = 0;
    for (int x: g[cur]) cnt += dfs(x);
    
    return mem[cur] = cnt;
}



void solve() {
    cin >> n >> m;
    char x, y;

    for (int i = 0; i < SIZE; i++) g[i].clear(), mem[i] = -1;
    for (int i = 0; i < SIZE; i++) for (int j = 0; j < SIZE; j++) am[i][j] = false;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        int xx = x - 'A', yy = y - 'A';
        if(am[xx][yy]) continue;
        g[xx].push_back(yy);
        am[xx][yy] = true;

    }

    for (int i = 0; i < SIZE; i++) sort(g[i].begin(), g[i].end());

    for (int i = 0; i < SIZE; i++) {
        if (mem[i] == -1) dfs(i);
    }

    int q;
    string s;
    cin >> q;

    while(q--) {
        cin >> s;
        int ans = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            int x = s[i] - 'A', y = s[i+1] - 'A';
            for (auto c: g[x]) {
                if (c == y) break;
                ans += mem[c];
            }
        }


        cout << s << ": " << ans+1 << endl;
    }
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