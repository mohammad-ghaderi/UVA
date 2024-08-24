#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define endl "\n"


using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int inf = 1e7;
const int S_SIZE = 51;
const int C_SIZE = 101;

int cm[C_SIZE][S_SIZE]{};
int cost[C_SIZE][C_SIZE]{};
int mem[C_SIZE][S_SIZE];

int C, S;

int dp(int city, int mounth) {

    if (mounth == S) return 0;
    if (~mem[city][mounth]) return mem[city][mounth];

    int answer = 0;

    for (int target_city = 0; target_city < C; target_city++) {
        answer = max(answer, dp(target_city, mounth + 1) - cost[city][target_city]);
    }

    answer += cm[city][mounth];

    return mem[city][mounth] = answer;
}


int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    memset(mem, -1, sizeof mem);
    cin >> t;
    while(t--) {
        cin >> C >> S;

        for (int i = 0; i < C; i++) {
            for (int j = 0; j < S; j++) {
                cin >> cm[i][j];
            }
        }

        for (int i = 0; i < C; i++) {
            for (int j = 0; j < C; j++) {
                cin >> cost[i][j];
            }
        }

        int answer = -inf;

        for (int city = 0; city < C; city++) {
            answer = max(answer, dp(city, 0)); // city_to_go, mounthh
        }

        cout << answer << endl;

        for (int i = 0; i <= C; i++) for (int j = 0; j <= S; j++) mem[i][j] = -1;

    }


    return 0;
}