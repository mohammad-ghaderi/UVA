#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int OBJECT_SIZE = 1000;
const int W_SIZE = 100;



void solve() {
    int n, g;
    cin >> n;
    int dp[31]{};

    for (int i = 0, p, w; i < n; i++) {
        cin >> p >> w;
        for (int j = 30; j >= w; j--) dp[j] = max(dp[j], dp[j - w] + p);
    }
    cin >> g;
    int ans = 0;
    for (int i = 0, w; i < g; i++) {
        cin >> w;
        ans += dp[w];
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