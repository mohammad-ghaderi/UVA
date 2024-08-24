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
const int SIZE = 10000;
const int inf = 1e9;
vector<pair<int,int>> g[SIZE]{}, g_r[SIZE];
int n, m, s, t, p;

void dijkstra(int &src, vector<int> &dist) {
    dist[src] = 0;

    set<pair<int,int>> pq{};

    for (int u = 1; u <= n; u++) pq.emplace(dist[u], u);

    while(!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());

        if (dist[u] < d) continue;
        auto neighbors = (src == s) ? g[u] : g_r[u];

        for (auto &[v, w]: neighbors) {
            if (dist[u] + w >= dist[v]) continue;
            pq.erase(pq.find({dist[v], v}));
            dist[v] = dist[u] + w;
            pq.emplace(dist[v], v);
        }
    }
}

void solve() {
    cin >> n >> m >> s >> t >> p;
    queue<tuple<int,int,int>> edge_list{};
    for (int i = 0, u, v, c; i < m; i++) {
        cin >> u >> v >> c;
        g[u].emplace_back(v, c);
        g_r[v].emplace_back(u, c);
        edge_list.emplace(u, v, c);
    }

    vector<int> dist_s(n+1, inf), dist_t(n+1, inf);

    dijkstra(s, dist_s);

    dijkstra(t, dist_t);

    int ans = -1;

    while(!edge_list.empty()) {
        auto [u, v, c] = edge_list.front();
        edge_list.pop();
        int dis = dist_s[u] + c + dist_t[v];
        if (dis <= p) {
            ans = max(ans, c);
        }
    }

    cout << ans << endl;

    for (int u = 1; u <= n; u++) {
        g[u].clear();
        g_r[u].clear();
    }
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