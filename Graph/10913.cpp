#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define ld long double
#define vll vector<ll>
#define vv vector<vll>
#define pb push_back
#define lb lower_bound2
#define ub upper_bound
#define pll pair<ll,ll>
#define vpll vector<pll>
#define ff first
#define ss second
#define tll tuple<ll,ll,ll>
#define vtll vector<tll> 
#define mt make_tuple
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define each(e, a) for (auto& e : a)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define vect(a,n) vll a(n); rep(i,0,n) cin>>a[i];
#define all(a) a.begin(),a.end()
#define sortall(a) sort(a.begin(),a.end());
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"


//Debug
#define printv(a) rep(i,0,a.size()) cout<<a[i]<<" "; cout<<endl;
#define pout(p) cout<<"("<<p.ff<<","<<p.ss<<")"<<" ";
#define printvp(a) rep(i,0,a.size()) cout<<"("<<a[i].ff<<","<<a[i].ss<<")"<<" "; cout<<endl;
#define tout(t) cout<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")"<<endl;
#define trace(x) cout<< '>' << #x << ':' << (x) << "\n";
#define trace2(x,y) cout<< '>' << #x << ':' << (x) << " | " << #y << ':' << (y) << "\n";
#define trace3(a,b,c) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n";
#define trace4(a,b,c,d) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n";


using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int SIZE = 75;
const int inf = 1e7;

int mp[SIZE][SIZE]{};
int mem[SIZE][SIZE][3][6]{};
int N, K, tc = 1;

bool check(int x, int y) { return !(x < 0 or y < 0 or x == N or y == N);}

int dp(int x, int y, int dir, int k) { //dir:0 = down, dir:1 = right, dir:2 = left;

    if (k < 0) return -inf;
    int new_k = k - (mp[x][y] < 0);
    if (new_k < 0) return -inf;
    if (x == N-1 and y == N-1) return mp[x][y];
    if (~mem[x][y][dir][k]) return mem[x][y][dir][k];



    int ans = -inf;

    if (dir != 2 and check(x, y + 1)) {
        ans = max(ans, dp(x, y + 1, 1, new_k));
    }
    if (dir != 1 and check(x, y - 1)) {
        ans = max(ans, dp(x, y - 1, 2, new_k));

    }

    if (check(x+1, y)) {
        ans = max(ans, dp(x + 1, y, 0, new_k));
    }
    if (ans != (-inf)) ans += mp[x][y];
    return mem[x][y][dir][k] = ans;
}



int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    while(true) {
        cin >> N >> K;
        if (!N and !K) break;

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                for (int c = 0; c < 3; c++) {
                    for (int k = 0; k <= K; k++) {
                        mem[i][j][c][k] = -1;
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cin >> mp[i][j];
        }

        int answer = dp(0, 0, 1, K); // i, j, dir, k_left;
        cout << "Case " << tc++ << ": ";
        if (answer == -inf) cout << "impossible\n";
        else cout << answer << endl;
    }

    return 0;
}