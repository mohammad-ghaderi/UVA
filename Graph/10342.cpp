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
const int SIZE = 100;
int n, r, tc = 1;

int AM[SIZE][SIZE]; // mn1, mn2 


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    while(scanf("%d%d", &n, &r) == 2) {

        vector<tuple<int,int,int>> EL{};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) AM[i][j] = inf;
            AM[i][i] = 0;
        }

        for (int i = 0, u, v, d; i < r; i++) {
            scanf("%d%d%d", &u, &v, &d);
            AM[u][v] = AM[v][u] = d;
            EL.emplace_back(u, v, d);
        }


        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
                }
            }
        }

        int q;
        scanf("%d", &q);
        int x, y;

        cout << "Set #" << tc++ << endl; 

        while(q--) {
            scanf("%d%d", &x, &y);
            int answer = inf;
            int ans;
            for (auto [u, v, d]: EL) {
                ans = AM[x][u] + d + AM[v][y];
                if (ans != AM[x][y]) answer = min(ans, answer);
                ans = AM[x][v] + d + AM[u][y];
                if (ans != AM[x][y]) answer = min(ans, answer);
            }
            
            if (answer == inf) cout << "?\n";
            else cout << answer << endl;
        }

    }

    return 0;
}