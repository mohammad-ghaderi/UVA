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
const int SIZE = 27;
bool AM1[SIZE][SIZE]{}, AM2[SIZE][SIZE]{};
int t;

void solve() {
    int n1;
    cin >> n1;
    char u, v;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) AM1[i][j] = AM2[i][j] = false;
        AM1[i][i] = AM2[i][i] =  true;
    }
    
    for (int i = 0; i < n1; i++) {
        cin >> u >> v;
        AM1[u-'A'][v-'A'] = AM1[v-'A'][u-'A'] = true;
    }

    for (int k = 0; k < SIZE; k++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                AM1[i][j] |= (AM1[i][k] and AM1[k][j]);
            }
        }
    }

    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cin >> u >> v;
        AM2[u-'A'][v-'A'] = AM2[v-'A'][u-'A'] = true;
    }

    for (int k = 0; k < SIZE; k++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                AM2[i][j] |= (AM2[i][k] and AM2[k][j]);
            }
        }
    }

    bool ans = true;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (AM1[i][j] != AM2[i][j]) {
                ans = false;
                break;
            }
        }
        if (!ans) break;
    }

    cout << (ans?"YES\n":"NO\n");
    if (t) cout << endl;
}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}