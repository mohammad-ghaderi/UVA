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
const int inf = 1e7;
const int SIZE = 11;

vector<int> g[SIZE][SIZE]{};
int cn[SIZE][SIZE]{};
int mem[SIZE][1001];

int N, K, tc = 1;

int dp(int city, int k) {

    if (k == K and city == N) return 0;
    if (k == K) return inf;
    if (~mem[city][k]) return mem[city][k];

    int mn = inf;

    for (int next_city = 1; next_city <= N; next_city++) {
        if (next_city == city) continue;
        int cost = g[city][next_city][k%cn[city][next_city]];
        if (!cost) continue;
        int ans = dp(next_city, k+1);
        if (ans == inf) continue;
        mn = min(mn, ans + cost);
    }

    return mem[city][k] = mn;
}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    while(true) {
        cin >> N >> K;
        if (!N and !K) return 0;
        int c, x;
        // K--;

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= K; j++) {
                mem[i][j] = -1;
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;
                cin >> c;
                g[i][j].resize(c);
                cn[i][j] = c;
                for (int k = 0; k < c; k++) {
                    cin >> x;
                    g[i][j][k] = x;
                }
            }
        }

        // 
        
        cout << "Scenario #" << tc++ << endl;
        int answer = dp(1, 0);
        if (answer == inf) cout << "No flight possible.\n";
        else cout << "The best flight costs " << answer << ".\n";
        cout << endl;
    }

    return 0;
}