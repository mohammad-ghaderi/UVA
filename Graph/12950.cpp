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
const int SIZE = 1e4 + 1;
const int inf = 1e9;
int c, v;
vector<pair<int,int>> g[SIZE]{};
int dist[2][SIZE]{};

void dijkstra() {
    for (int u = 1; u <= c; u++) dist[0][u] = inf, dist[1][u] = inf;
    dist[0][1] = 0;

    set<tuple<int,int,bool>> pq{};
    for (int u = 1; u <= c; u++) pq.emplace(dist[0][u], u, false);
    for (int u = 1; u <= c; u++) pq.emplace(dist[1][u], u, true);

    while(!pq.empty()) {
        auto [d, u, odd] = *pq.begin();
        pq.erase(pq.begin());

        if (dist[odd][u] < d) continue;

        for (auto &[v, w]: g[u]) {
            bool target_odd = !odd;
            if (dist[odd][u] + w >= dist[target_odd][v]) continue;
            pq.erase(pq.find({dist[target_odd][v], v, target_odd}));
            dist[target_odd][v] = dist[odd][u] + w;
            pq.emplace(dist[target_odd][v], v, target_odd);
        }
    }
}

int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    while(scanf("%d%d", &c, &v) == 2) {
        for (int i = 0, a, b, w; i < v; i++) {
            scanf("%d%d%d", &a, &b, &w);
            g[a].emplace_back(b, w);
            g[b].emplace_back(a, w);
        }

        dijkstra();

        if (dist[0][c] != inf) cout << dist[0][c] << endl;
        else cout << "-1\n";

        for (int u = 1; u <= c; u++) {
            g[u].clear();
        }
    }


    return 0;
}