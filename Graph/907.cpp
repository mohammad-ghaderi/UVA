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
const int SIZE = 605;
int miles[SIZE]{}, all_sum[SIZE]{};
int mem[SIZE][303];

int N, K;

int dp(int camp, int k) {
    if (k == 0 and camp == N+1) return 0;
    if (k == 0) return inf;
    if (camp > N) return inf;
    if (~mem[camp][k]) return mem[camp][k];

    int ans = inf;

    for (int c = camp + 1; c <= N+1; c++) {
        int an = dp(c, k - 1);
        if (an == inf) continue;
        int val = all_sum[c] - all_sum[camp];
        ans = min(ans, max(an, val));
    }

    return mem[camp][k] = ans;
}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    while(scanf("%d%d", &N, &K) == 2) {
        int sm = 0;

        for (int i = 0; i <= N+1; i++) {
            for (int j = 0; j <= K+1; j++) {
                mem[i][j] = -1;
            }
        }

        for (int i = 1; i <= N+1; i++) {
            scanf("%d", &miles[i]);
            sm += miles[i];
            all_sum[i] = sm;
        }

        printf("%d\n", dp(0, K + 1));
    }

    

    return 0;
}