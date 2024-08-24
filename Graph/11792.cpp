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
const int SIZE = 10001;
int n, s;
vector<int> g[SIZE]{};
bool vis[SIZE]{};
int val[SIZE]{}, sz[SIZE]{};

queue<int> q{};

int bfs(int src) {
    while(!q.empty()) q.pop();
    for (int i = 1; i <= n; i++) vis[i] = false;
    int tim = 0;
    
    q.push(src);
    vis[src] = true;
    val[src] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if (sz[u] > 1) tim += val[u];

        for (auto x: g[u]) {
            if (!vis[x]) {
                q.push(x);
                vis[x] = true;
                val[x] = val[u] + 1;
            }
        }
    }

    return tim;
}

void solve() {
    cin >> n >> s;
    int x;
    int prev = 0;
    
    for (int i = 0; i < s; i++) {
        int j = 0;
        while(true) {
            cin >> x;
            if (!x) break;
            if (j++) {
                g[x].push_back(prev);
                g[prev].push_back(x);
            }
            prev = x;
            sz[x]++;
        }
    }

    int answer = INT_MAX, ans_node = 1;
    for (int x = 1; x <= n; x++) {
        if (sz[x] <= 1) continue;
        int an = bfs(x);
        if (an < answer) {
            ans_node = x;
            answer = an;
        }
    }

    for (int i = 1; i <= n; i++) g[i].clear(), sz[i] = 0;

    cout << "Krochanska is in: " << ans_node << endl;

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