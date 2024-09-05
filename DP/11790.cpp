#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
int t = 1;

void solve() {
    int n;
    cin >> n;

    int h[n]{}, w[n]{};

    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> w[i];

    int inc[n]{}, dec[n]{};
    int ans_inc = 0, ans_dec = 0;

    for (int i = 0; i < n; i++) {
        int mx_inc = 0, mx_dec = 0;
        for (int j = 0; j < i; j++) {
            if (h[i] > h[j]) mx_inc = max(mx_inc, inc[j]);
            if (h[i] < h[j]) mx_dec = max(mx_dec, dec[j]);
        }

        inc[i] = mx_inc + w[i];
        dec[i] = mx_dec + w[i];
        ans_inc = max(ans_inc, inc[i]);
        ans_dec = max(ans_dec, dec[i]);
    }


    
    cout << "Case " << t++ << ". ";
    if (ans_inc >= ans_dec) cout << "Increasing (" << ans_inc << "). Decreasing (" << ans_dec << ").";
    else cout << "Decreasing (" << ans_dec << "). Increasing (" << ans_inc << ").";
    cout << endl;
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