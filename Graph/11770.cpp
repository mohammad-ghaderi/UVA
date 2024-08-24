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
const int SIZE = 1e4 + 4;

int n, m;
int dfs_num[SIZE]{};
vector<int> e[SIZE]{};
stack<int> st{};
bool vis[SIZE]{};
int cnt = 0;
int tc = 1;

void topo_sort(int u) {
    dfs_num[u] = true;
    for (auto v : e[u]) {
        if (!dfs_num[v]) topo_sort(v);
    }
    st.push(u);
}

void dfs(int u) {
    vis[u] = true;
    cnt++;
    for (auto v: e[u]) {
        if (!vis[v]) dfs(v);
    }
}


void solve() {
    cin >> n >> m;

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
    }

    for (int u = 1; u <= n; u++) {
        if (!dfs_num[u]) topo_sort(u);
    }
    cnt = 0;
    int ans = 0;
    while(!st.empty()) {
        int tp = st.top();
        st.pop();
        if (!vis[tp]) {
            dfs(tp);
            ans++;
        }
        if (cnt == n) break;
    }

    for (int i = 1; i <= n; i++) {
        dfs_num[i] = 0;
        e[i].clear();
        vis[i] = false;
    }

    while (!st.empty()) st.pop();

    cout << "Case " << tc++ << ": " << ans << endl;

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