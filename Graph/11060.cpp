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
const int SIZE = 101;

map<string, int> dic{};
vector<int> e[SIZE]{};
string names[SIZE]{};
int in_degree[SIZE]{};
bool vis[SIZE]{};
queue<int> ans{};

priority_queue<int , vector<int>, greater<int>> pq{};

int n, w = 0, t = 1;

void get_size(string s) {
    n = 0;
    int i = 0;
    while (s[i]) {
        n *= 10;
        n += (s[i] - '0');
        i++;
    }
}


void topo_sort() {
    for (int i = 0; i < n; i++) {
        if (!in_degree[i]) {
            pq.push(i);
            vis[i] = true;
        }
    }

    while(!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans.push(u);

        for (auto v: e[u]) {
            if (vis[v]) continue;
            in_degree[v]--;
            if (in_degree[v] > 0) continue;
            pq.push(v);
        }
    }
}

void solve() {
    string name;
    w = 0;
    dic.clear();
    for (int i = 0; i < n; i++) {
        cin >> name;
        names[w] = name;
        dic[name] = w++;
    }
    int m;
    cin >> m;
    string first, second;
    for (int i = 0; i < m; i++) {
        cin >> first >> second;
        e[dic[first]].push_back(dic[second]);
        in_degree[dic[second]]++;
    }

    topo_sort();

    cout << "Case #" << t << ": Dilbert should drink beverages in this order:";

    while (!ans.empty()) {
        int x = ans.front();
        ans.pop();
        cout << ' ' << names[x];
    } 
    cout << ".\n";

    for (int i = 0; i < n; i++) {
        vis[i] = false;
        in_degree[i] = 0;
        e[i].clear();
        dic[names[i]] = 0;
    }
}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    while (getline(cin, s) && s!="\n" and s!="") {
        get_size(s);
        solve();
        cout << endl;
        t++;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}