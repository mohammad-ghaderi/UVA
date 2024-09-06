#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int SIZE = 7490;
vector<int> coins = {1, 5, 10, 25, 50};
int mem[SIZE][5]{};


int dp(int n, int i) {
    // Base case
    if (n == 0) return 1;
    if (i == 5 or n < 0) return 0;
    if (~mem[n][i]) return mem[n][i];

    // Recursive case
    return mem[n][i] = dp(n - coins[i], i) + dp(n, i + 1);
}

int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;

    memset(mem, -1, sizeof mem);
    dp(SIZE - 1, 0);
    
    while(cin >> n) {
        cout << dp(n, 0) << endl;
    }

    return 0;
}