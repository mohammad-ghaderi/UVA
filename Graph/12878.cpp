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
const int SIZE = 10000;
int ans = 0;
int p, t;

vector<pair<int,int>> g[SIZE]{};
int dist[SIZE]{};

void dijkstra() {
    for (int u = 0; u < p; u++) dist[u] = inf;
    dist[0] = 0;

    set<pair<int,int>> pq{};

    for (int u = 0; u < p; u++) pq.emplace(dist[u],u);

    while(!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());
        if (dist[u] < d) continue;

        for (auto &[v, w]: g[u]) {
            if (dist[u] + w >= dist[v]) continue;
            pq.erase(pq.find({dist[v], v}));
            dist[v] = dist[u] + w;
            pq.emplace(dist[v], v);            
        }
    }
}

bool answer[SIZE]{}, vis[SIZE]{};
bool dfs(int u, int par) {

    if (u == 0) {
        vis[u] = true;
        return answer[u] = true;
    }
    vis[u] = true;

    bool an = false;
    for (auto &[v, d]: g[u]) {
        if (v == par) continue;
        if (dist[u] - d == dist[v]){
            if ((vis[v] and answer[v]) or (!vis[v] and dfs(v,u))) {
                an = true;
                ans += d;
            }
        }
    }
    return answer[u] = an;
}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string line;
    while(getline(cin, line), line !="") {
        stringstream s;
        s << line;

        s >> p >> t;

        for (int i = 0, u, v, w; i < t; i++) {
            cin >> u >> v >> w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }

        dijkstra();
        
        ans = 0;

        dfs(p-1, -1);

        cout << ans*2 << endl;
        cin.ignore();
        for (int u = 0; u < p; u++) vis[u] = false, answer[u] = false, g[u].clear();
    
    }

    return 0;
}