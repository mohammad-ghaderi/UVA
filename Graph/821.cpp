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
const int SIZE = 101;
int tc = 0;

int AM[SIZE][SIZE]{};


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    for (int u = 1; u < SIZE; u++) {
        for (int v = 1; v < SIZE; v++) AM[u][v] = inf;
        AM[u][u] = 0;
    }

    int u, v;
    int mx = 0;

    while(true) {
        cin >> u >> v;
        if (!u and !v) break;
        AM[u][v] = 1;
        mx = max(u, v);
        
        while(true) {
            cin >> u >> v;
            if (!u and !v) break;
            AM[u][v] = 1; 
            mx = max(mx, max(u, v));
        }

        for (int k = 1; k <= mx; k++) {
            for (int i = 1; i <= mx; i++) {
                for (int j = 1; j <= mx; j++) {
                    AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
                }
            }
        }

        int cnt = 0;
        double sum = 0;

        for (int i = 1; i <= mx; i++) {
            for (int j = 1; j <= mx; j++) {
                if (i == j) continue;
                if (AM[i][j] == inf) continue;
                sum += AM[i][j];
                cnt++;
            }
        }
        
        tc++;

        double ans = sum / cnt;

        printf("Case %d: average length between pages = %.3f clicks\n",tc, ans);
        
        for (int u = 1; u <= mx; u++) {
            for (int v = 1; v <= mx; v++) AM[u][v] = inf;
                AM[u][u] = 0;
    }

    }
    

    return 0;
}