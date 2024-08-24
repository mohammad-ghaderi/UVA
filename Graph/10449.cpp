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
const int SIZE = 201;
int busyness[SIZE]{};
vector<pair<int,int>> g[SIZE]{};
bool no_ans[SIZE]{};
int n, m, q, tc = 1;


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    while(cin >> n) {

        for (int i = 1, x; i <= n; i++) cin >> busyness[i];
        
        cin >> m;

        for (int i = 0, x, y; i < m; i++) {
            cin >> x >> y;
            g[x].emplace_back(y, pow(busyness[y]-busyness[x], 3));
        }

        vector<int> dist(n+1, inf);
        dist[1] = 0;

        for (int i = 0; i < n - 1; i++) {
            bool modified = false;
            for (int u = 1; u <= n; u++) {
                if (dist[u] == inf) continue;
                for (auto &[v, w]: g[u]) {
                    if (dist[u] + w >= dist[v]) continue;
                    dist[v] = dist[u] + w;
                    modified = true;
                }
            }
            if (!modified) break;
        }

        vector<int> dist2(n+2);
        for (int u = 1; u <= n; u++) dist2[u] = dist[u];

        for (int i = 0; i < n - 1; i++) {
            bool modified = false;
            for (int u = 1; u <= n; u++) {
                if (dist2[u] == inf) continue;
                for (auto &[v, w]: g[u]) {
                    if (dist2[u] + w >= dist2[v]) continue;
                    dist2[v] = dist2[u] + w;
                    modified = true;
                }
            }
            if (!modified) break;
        }

        cout << "Set #" << tc++ << endl;

        cin >> q;
        for (int i = 0, x; i < q; i++) {
            cin >> x;
            if (dist[x] != dist2[x] or  dist[x] < 3 or dist[x] == inf) cout << "?\n";
            else cout << dist[x] << endl;
        }

        for (int i = 1; i <= n; i++) {
            g[i].clear();
            no_ans[i] = false;
        }
        
    }


    return 0;
}