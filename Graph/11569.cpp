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
const int SIZE = 26;
int repeates[SIZE]{};
vector<int> g[SIZE]{};
pair<int,int> mem[SIZE]{};

pair<int,int> dfs(int cur) { // cnt-len
    if (!g[cur].size()) return {1, 1};
    if (~mem[cur].ff) return mem[cur];

    int mx = 0;
    int answer = 0;
    for (int x: g[cur]) {
        auto an = dfs(x);
        if (an.ss > mx) {
            mx = an.ss;
            answer = an.ff;
        } else if (an.ss == mx) {
            answer += an.ff;
        }
    }

    return mem[cur] = {answer, mx + 1};
}

void solve() {
    string name;
    getline(cin, name);

    for (int i = 0; i < SIZE; i++) {
        g[i].clear();
        repeates[i] = 0;
        mem[i] = {-1, -1};
    }

    for (char x: name) {
        if (x >= 'A' and x <= 'Z')
            repeates[x-'A']++;
    }
    
    for (int i = 1; i <= SIZE; i++) {
        if (!repeates[i-1]) continue;
        int bs = ((5*i)%4?(5*i)/4+1:(5*i)/4);
        for (int j = bs-1; j < SIZE; j++) {
            if (repeates[j]) {
                // for (int k = 0; k < repeates[j]; k++)
                    g[i-1].push_back(j);
            }
        }
    }

    int mx = 0;
    int an = 0;
    for (int i = 0; i < SIZE; i++) {
        if (repeates[i]) {
            auto answer = dfs(i);
            if (answer.ss > mx) {
                an = answer.ff;
                mx = answer.ss;
            } else if (answer.ss == mx) {
                an += answer.ff;
            }
        }
    }

    cout << mx << ' ' << an << endl;



}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    string s;
    getline(cin, s);
    stringstream sin;
    sin << s;
    sin >> t;
    while (t--) solve();

    return 0;
}