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


bool notended = true;
queue<string> q;
int in_degree[28]{};
bool has_char[28]{}, vis[28];
vector<char> e[28]{};
queue<char> ans{};


void dfs(int i) {
    vis[i] = true;
    for (int x: e[i]) {
        if (!vis[x]) dfs(x);
    }
    ans.push(i);
}

void add_to_graph(string f, string s) {

    int size = min(f.size(), s.size());
    int i = 0;

    while (i < size) {
        if (f[i] == s[i]) {
            i++;
        } else {
            e[s[i]-'A'].push_back(f[i]-'A');
            in_degree[f[i]-'A']++;
            return;
        }
    }
}

void solve() {
    string s;

    for (int i = 0; i < 28; i++) {
        in_degree[i] = 0;
        e[i].clear();
        has_char[i] = false;
        vis[i] = false;
    }

    while (true) {
        cin >> s;
        if (s == "#") break;
        if (s == "\n" or s == "") {
            notended = false;
            return;
        }
        for (char c: s) has_char[c-'A'] = true;
        q.push(s);
    }

    string first = q.front();
    string second;
    q.pop();

    while (!q.empty()) {
        second = q.front();
        q.pop();
        
        add_to_graph(first, second);
        first = second;
    }

    for (int i = 0; i < 28; i++) {
        if (!in_degree[i]) {
            if (has_char[i] and !in_degree[i]) {
                dfs(i);
            }
        }
    }

    while (!ans.empty()) {
        int x = ans.front();
        ans.pop();
        char c = 'A' + x;
        cout << c;
    }
    cout << endl;
}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    while (notended) {
        solve();
    }

    return 0;
}