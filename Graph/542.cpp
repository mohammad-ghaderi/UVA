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
const int SIZE = 27;

int tim[SIZE], in[SIZE]{}, mem[SIZE]{};
bool hav[SIZE]{}, vis[SIZE]{};
string g[SIZE]{};
int tc = 1, t;

int dfs(int cur) {
    if (vis[cur]) return mem[cur];
    vis[cur] = true;

    int ans = 0;
    for (char c: g[cur]) {
        ans = max(ans, dfs(c-'A'));
    }

    return mem[cur] = ans + tim[cur];
}

void solve() {
    string line;
    for (int u = 0; u < SIZE; u++) g[u] = "", vis[u] = false, hav[u] = false;
    if (tc++ == 1) getline(cin,line);
    
    while(getline(cin, line), line != "" && line!="    ") {
        stringstream s;
        s << line;
        char u;
        int w;
        string vs;
        s >> u >> w >> vs;
        tim[u-'A'] = w;
        g[u-'A'] = vs;
        hav[u-'A'] = true;
    }


    int answer = 0;
    for (int u = 0; u < SIZE; u++) {
        if (!hav[u]) continue;
        if (!vis[u]) answer = max(answer, dfs(u));
    }

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