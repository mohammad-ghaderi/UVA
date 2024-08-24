#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define endl "\n"


using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

const int END = -999999;

const int SIZE = 110;
int a[SIZE]{};

int dp(int i, bool sign) {
    
}



int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string line;
    
    while(getline(cin, line), line != "") {
        stringstream sin;
        sin << line;

        int x;
        n = 0;
        while (true) {
            sin >> x;
            if (x == END) break;
            a[n++] = x;
        }
        int ans = END;

        cout << ans << endl;        
    }

    return 0;
}