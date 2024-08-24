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
const int SIZE = 201;
string words[SIZE]{};
vector<int> g[SIZE]{};
map<string,int> names{};
queue<pair<int,int>> q{};
bool vis[SIZE]{};
int c, tc = 1;

int bfs(int a, int b) {
    while (!q.empty()) q.pop();
    for (int i = 0; i < SIZE; i++) vis[i] = false;

    q.push({a, 0});
    vis[a] = true;
    
    while (!q.empty()) {
        auto &[w, op] = q.front();
        q.pop();
        if (w == b) return op;

        for (auto x: g[w]) {
            if (!vis[x]) {
                q.push({x, op + 1});
                vis[x] = true;
            }
        }
    }
    return 0;
}

void solve() {
    string word;
    c = 0;
    names.clear();
    while(true) {
        cin >> word;
        if (word == "*") break;
        names[word] = c;
        words[c++] = word;
    }

    for (int i = 0; i < c; i++) {
        for (int j = i + 1; j < c; j++) {
            if (words[i].size() != words[j].size()) continue;
            int diff_cnt = 0;
            for (int k = 0; k < words[i].size(); k++) diff_cnt +=(words[i][k] != words[j][k]);
            if (diff_cnt == 1) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    string line, a, b;
    cin.ignore();
    if (tc++ != 1) cout << endl;
    while (getline(cin, line), line != "") {
        stringstream s; s << line;
        s >> a >> b;
        int a_num = names[a], b_num = names[b];

        cout << a << ' ' << b << ' ' << bfs(a_num, b_num) << endl;
    }

    for (int i = 0; i < c; i++) g[i].clear();
}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}