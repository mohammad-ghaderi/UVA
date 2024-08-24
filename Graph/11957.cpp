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

const int _MOD{(int)1000007};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int SIZE = 101;
string mp[SIZE]{};
int mem[SIZE][SIZE];

int n;
int wx, wy;
int tc = 1, t;

bool check(int x, int y) {return !(x < 0 or y < 0 or x == n or y == n);}

int dfs(int x, int y) {
    if (x == 0 and mp[x][y] == '.') return 1;
    if (x == 0) return 0;
    if (~mem[x][y]) return mem[x][y];

    int ans = 0;

    int xx = x - 1, yy = y + 1;
    if (check(xx, yy)) {
        if (mp[xx][yy] != 'B') ans = mod(ans + dfs(xx, yy));
        else if (check(x-2, y+2) and mp[x-2][y+2]!='B') ans = mod(ans + dfs(x-2, y+2));
    }

    yy = y - 1;

    if (check(xx, yy)) {
        if (mp[xx][yy] != 'B') ans = mod(ans + dfs(xx, yy));
        else if (check(x-2, y-2) and mp[x-2][y-2]!='B') ans = mod(ans + dfs(x-2, y-2));
    }
    
    return mem[x][y] = mod(ans);
    
}

void solve() {
    cin >> n;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            mem[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> mp[i];
        for (int j = 0; j < n; j++) {
            if (mp[i][j] == 'W') {
                wx = i; wy = j;
            }
        }
    }

    cout << "Case " << tc++ << ": " << dfs(wx, wy) << endl;
    
}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> t;
    while (t--) solve();

    return 0;
}