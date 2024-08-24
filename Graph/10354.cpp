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
int p, r, bh, of, yh, m;

int AMB[SIZE][SIZE], AMY[SIZE][SIZE];
bool danger[SIZE]{};

int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    while(scanf("%d%d%d%d%d%d", &p, &r, &bh, &of, &yh, &m) == 6) {

        for (int i = 1; i <= p; i++) {
            for (int j = 1; j <= p; j++) AMY[i][j] = AMB[i][j]= inf;
            AMY[i][i] = AMB[i][i] = 0;
            danger[i] = false;
        }

        for (int i = 0, u, v, d; i < r; i++) {
            scanf("%d%d%d", &u, &v, &d);
            AMY[u][v] = AMY[v][u] = AMB[u][v] = AMB[v][u] = d;            
        }


        for (int k = 1; k <= p; k++) {
            for  (int i = 1; i <= p; i++) {
                for (int j = 1; j <= p; j++) {
                    AMB[i][j] = min(AMB[i][j], AMB[i][k] + AMB[k][j]);
                }
            }
        }

        for (int i = 1; i <= p; i++) {
            if (AMB[bh][of] == AMB[bh][i] + AMB[i][of]) danger[i] = true;
        }

        if (danger[yh] or danger[m]) {
            cout << "MISSION IMPOSSIBLE.\n";
            continue;
        }

        
        for (int k = 1; k <= p; k++) {
            if (danger[k]) continue;
            for  (int i = 1; i <= p; i++) {
                if (danger[i]) continue;
                for (int j = 1; j <= p; j++) {
                    if (danger[j]) continue;
                    AMY[i][j] = min(AMY[i][j], AMY[i][k] + AMY[k][j]);
                }
            }
        }


        if (AMY[yh][m] == inf) cout << "MISSION IMPOSSIBLE.\n";
        else cout << AMY[yh][m] << endl;
        
        
    }

    return 0;
}