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

const int SIZE = 24;
const vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
string mp[SIZE];
int island[SIZE][SIZE]{}, island_size[SIZE*SIZE]{};
int n, m, x, y;
int color, mx;

void get_size(string s) {
    n = 0;
    int i = 0;
    while (s[i] != ' ') {
        n *= 10;
        n += (s[i] - '0');
        i++;
    }
    i++;
    m = 0;
    while (i < s.size() and s[i] != '\n') {
        m *= 10;
        m += (s[i] - '0');
        i++;
    }
    
}

bool check(int i, int j) { return !(i < 0 or j < 0 or i == n or j == m); }

void dfs(int i, int j, char c) {
    island[i][j] = color;
    island_size[color]++;
    mx = max(mx, island_size[color]);

    for (auto &[x, y]: dirs) {
        int ii = i + x, jj = j + y;
        if (jj < 0) jj = m - 1;
        if (jj == m) jj = 0;
        if (check(ii, jj) and !island[ii][jj] and mp[ii][jj] == c) {
            dfs(ii, jj, c);
        }
    }
    
}

void remove_his_island_dfs(int i, int j, char c, char other) {
    mp[i][j] = other;

    for (auto &[x, y]: dirs) {
        int ii = i + x, jj = j + y;
        if (jj < 0) jj = m - 1;
        if (jj == m) jj = 0;
        if (check(ii, jj) and mp[ii][jj] == c) {
            remove_his_island_dfs(ii, jj, c, other);
        }
    }
}


void solve() {

    for (int i = 0; i < n; i++) {
        cin >> mp[i];
    }

    cin >> x >> y;
    char lnd_char = mp[x][y];
    char other = ' ';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] != lnd_char) {
                other = mp[i][j];
                break;
            }
        }
        if (other != ' ') break;
    }
    remove_his_island_dfs(x, y, lnd_char, other);

    color = 0;
    mx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!island[i][j] and mp[i][j] == lnd_char) {
                color++;
                dfs(i, j, lnd_char);
            } 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            island[i][j] = 0;
        }
        mp[i] = "";
    }

    for (int i = 0; i <= color; i++) island_size[i] = 0;

    cout << mx << endl;

}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    string s;

    // cin >> t;
    while (getline(cin, s) && s!="") {
        get_size(s);

        solve();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}