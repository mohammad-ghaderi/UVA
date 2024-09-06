#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

const int SIZE = 1e4+4;
int c[100];
const int inf = 1e9;

void solve() {
    int m;
    cin >> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];

    int dp[SIZE]{};
    for (int i = 0; i < SIZE; i++) dp[i] = inf;
    dp[0] = 0;
    
    for (int j = 0; j < n; j++) {
        for (int i = SIZE - 1; i > 0; i--) {
            if (i - c[j] >= 0 and dp[i] > dp[i - c[j]] + 1) dp[i] = dp[i - c[j]] + 1;
        }
    }
    
    int ans = 0, value = 0;
    for (int i = m; i < SIZE; i++) {
        if (dp[i] != inf) {
            ans = dp[i];
            value = i;
            break;
        }
    }
    cout << value << ' ' << ans << endl;    
}


int32_t main() {
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