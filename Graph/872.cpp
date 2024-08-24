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
const int SIZE_ALF = 28;
const int SIZE = 50;
vector<int> numbs{};
vector<int> e[28]{}, res;
int in_degree[28]{};
bool vis[28]{};
int n;


bool fnd = false;

void all_topo_sort() {
    bool flag = false;
    for (int i = 0; i < numbs.size(); i++) {
        int num = numbs[i];
        if (in_degree[num] == 0 and !vis[num]) {
            
            for (auto x: e[num]) in_degree[x]--;
            
            res.push_back(num);
            vis[num] = true;

            all_topo_sort();

            vis[num] = false;
            res.erase(res.end() - 1);

            for (auto x: e[num]) in_degree[x]++;
            flag = true;
        }
    }

    if (!flag) {
        fnd = true;
        for (int k = 0; k < res.size(); k++) {
            char c = 'A' + res[k];
            cout << c ;
            if (k != res.size()-1) cout << ' ';
        }
        if (res.size()) cout << endl;
        else cout << "NO\n";
    }
}

void solve() {
    string s;
    getline(cin, s);
    int i = 0;
    while (true) {
        numbs.push_back(s[i]-'A');
        if (!s[i+1]) break;
        i += 2;
    }
    fnd = false;

    getline(cin, s);
    i = 0;
    while (true) {
        int first = s[i] - 'A', second = s[i+2]-'A';
        e[first].push_back(second);
        in_degree[second]++;
        i += 4;
        if (!s[i-1]) break;
    }

    sort(numbs.begin(), numbs.end());

    all_topo_sort();

    if (!fnd) {
        cout << "NO\n";
    }

    for (auto x: numbs) {
        vis[x] = false;
        e[x].clear();
        in_degree[x] = 0;
    }
    res.clear();
    numbs.clear();
}



int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    string ss;
    getline(cin, ss);
    getline(cin, ss);

    while (t--) {
        solve();
        getline(cin, ss);
        if (t) cout << endl;
    }
    return 0;
}