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
const int SIZE = 1e4+1;
int r, c, q;

vector<int> e[SIZE]{};
int dfs_num[SIZE]{}, dfs_low[SIZE]{}, dfs_par[SIZE];
int timer = 0;


const int mxN = SIZE;

int parent[mxN];
int siz[mxN];
void make_set(int v) {
    parent[v]=v; siz[v]=1;
}
int find_set(int v) {
    return (v==parent[v])?v:parent[v]=find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if(siz[a]<siz[b]) swap(a,b);
    parent[b] = a;
    siz[a]+=siz[b]; 
    siz[b]=0;
}
int get_size(int v){
    return siz[find_set(v)];
}


void bridge_find(int u) {
    dfs_num[u] = ++timer;
    dfs_low[u] = dfs_num[u];
    for (auto v: e[u]) {
        if (dfs_num[v] == 0) {
            dfs_par[v] = u;

            bridge_find(v);

            if (dfs_low[v] > dfs_num[u]) {
                union_sets(u, v);
            }
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
    while (getline(cin, line), line != "0 0 0") {
        stringstream temp;
        temp << line;
        temp >> r >> c >> q;

        for (int i = 0, u, v; i < c; i++) {
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }

        for (int i = 0; i <= r; i++) make_set(i);

        for (int u = 1; u <= r; u++) {
            bridge_find(u);
        }

        int start, end;
        while (q--) {
            cin >> start >> end;
            if (find_set(start) == find_set(end)) cout << "Y\n";
            else cout << "N\n";
        }

        for (int i = 0; i <= r; i++) {
            e[i].clear();
            dfs_num[i] = 0;
            dfs_low[i] = 0;
            dfs_par[i] = 0;
        }
        cout << "-" << endl;
        cin.ignore();
    }
    return 0;
}