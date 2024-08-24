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
const int inf = 1e9;
const int SIZE = 1e4;
vector<pair<int,int>> dirs = {{0,1}, {1,0}};
bool mp[SIZE][SIZE]{};
int mem[SIZE][SIZE];

int t, tc = 1;
int n, m;

bool check(int x, int y) { return !(x < 1 or y < 1 or x > n or y > m);}

int dp(int x, int y) {

    if (x == n and y == m) return 1;
    if (~mem[x][y]) return mem[x][y];

    int ans = 0;
    for (auto &[dx, dy]: dirs) {
        int xx = x + dx, yy = y + dy;
        if (check(xx, yy) and mp[xx][yy]) {
            ans += dp(xx, yy);
        }
    }
    
    return mem[x][y] = ans;
}

void solve() {
    string line;
    stringstream s;
    getline(cin,line);

    getline(cin, line);
    s << line;
    s >> n >> m;
    int x, y;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mp[i][j] = true;
            mem[i][j] = -1;
        }
    }

    string lline;
    for (int i = 0; i < n; i++) {
        getline(cin, lline);
        stringstream ss;
        ss << lline;
        ss >> x;
        while(ss >> y) {
            mp[x][y] = false;
        }
    }

    auto answer = dp(1, 1);



    cout << answer << endl;
    if (t) cout << endl;
}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string line_tc;
    getline(cin, line_tc);
    stringstream tc;
    tc << line_tc;
    t = 1;
    tc >> t;

    while (t--) {
        solve();
    }

    return 0;
}