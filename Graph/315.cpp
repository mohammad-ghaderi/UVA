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
const int SIZE = 100;
int n;

vector<int> e[SIZE]{};
int dfs_num[SIZE]{}, dfs_low[SIZE]{}, dfs_par[SIZE];
bool art_point[SIZE]{};
int timer = 0, dfs_root, root_children;

void articulation_point(int u) {
    dfs_num[u] = ++timer;
    dfs_low[u] = dfs_num[u];
    for (auto v: e[u]) {
        if (dfs_num[v] == 0) {
            dfs_par[v] = u;
            if (u == dfs_root) root_children++;

            articulation_point(v);

            if (dfs_low[v] >= dfs_num[u]) art_point[u] = 1;
            // if (dfs_low[v] > dfs_num[u]) // bridge
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_par[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    string line;
    while (getline(cin, line), line != "0") {
        stringstream temp;
        temp << line;
        temp >> n;

        while (getline(cin, line), line != "0") {
            stringstream s;
            s << line;
            int u, v;
            s >> u;
            u--;

            while(not s.eof()) {
                s >> v;
                v--;
                e[u].push_back(v);
                e[v].push_back(u);
            }
        }

        for (int u = 0; u < n; u++) {
            if (!dfs_num[u]) {
                dfs_root = u;
                root_children = 0;
                articulation_point(u);
                art_point[u] = (root_children > 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) ans += (art_point[i]);

        for (int i = 0; i < n; i++) {
            e[i].clear();
            dfs_num[i] = 0;
            dfs_low[i] = 0;
            art_point[i] = 0;
        }

        cout << ans << endl;
    }

    return 0;
}