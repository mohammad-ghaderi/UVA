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
int n, m;

vector<int> e[SIZE]{}, e_t[SIZE];
map<string,int> name{};
string str_name[SIZE]{};
bool vis[SIZE]{};
vector<int> S{};
stack<int> ans{};
int numSCC = 0;
int f = 0;

void kosaraju(int u, int pass) {
    vis[u] = true;
    auto &neighbor = (pass == 1) ? e[u] : e_t[u];
    for (int v: neighbor) {
        if (!vis[v]) kosaraju(v, pass);
    }
    S.push_back(u);
    if (pass == 2) {
        if (!f) cout << str_name[u];
        else cout << ", " << str_name[u];
        f++;
    }
}



int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    

    string line;
    while (getline(cin, line), line != "0 0") {
        stringstream temp;
        temp << line;
        temp >> n >> m;
        string u, v;
        int k = 0;
        

        for (int i = 0, ui, vi; i < m; i++) {
            cin >> u >> v;
            if (name.find(u) == name.end()) name[u] = k, str_name[k++] = u;
            if (name.find(v) == name.end()) name[v] = k, str_name[k++] = v;
            ui = name[u];
            vi = name[v];
            
            e[ui].push_back(vi);
            e_t[vi].push_back(ui);
        }

        S.clear();
        for (int i = 0; i < n; i++) {
            if (!vis[i]) kosaraju(i, 1);
        }

        numSCC = 0;

        for (int i = 0; i < n; i++) vis[i] = false;

        if (t != 1) cout << endl; 
        
        cout << "Calling circles for data set " << t++ << ":\n";
        if (m == 0) continue;

        for (int i = n - 1; i >= 0; i--) {
            if (!vis[S[i]]) {
                ++numSCC;
                kosaraju(S[i], 2);
                f = 0;
                cout << endl;
            }
        }


        for (int i = 0; i < n; i++) {
            e[i].clear();
            e_t[i].clear();
            vis[i] = false;
            
        }
        name.clear();
        S.clear();
        cin.ignore();
    }
    return 0;
}