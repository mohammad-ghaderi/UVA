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
const int SIZE = 10000;
vector<int> buttons{}, e[SIZE]{};
bool vis[SIZE]{};
queue<pair<int,int>> q{};

int bfs(int src, int end) {
    while (!q.empty())q.pop();
    q.push({src, 0});
    vis[src] = true;

    while (!q.empty()) {
        auto &[node, step] = q.front();
        q.pop();

        if (node == end) return step;

        for (auto x: e[node]) {
            if (!vis[x]) {
                q.push({x, step + 1});
                vis[x] = true;
            }
        }
    }

    return -1;
}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int tc = 1;
    
    string line;
    while (getline(cin, line), line != "0 0 0") {
        stringstream s;
        s << line;
        int L, U, R;
        s >> L >> U >> R;


        buttons.assign(R,0);
        for (int i = 0; i < R; i++) cin >> buttons[i];

        for (int i = 0; i < SIZE; i++) {
            for (auto x: buttons) {
                e[i].push_back((i + x) % SIZE);
            }
        }
        int ans = bfs(L, U);
        cout << "Case " << tc++ << ": ";
        if (~ans) cout << ans;
        else cout << "Permanently Locked";
        cout << endl;
        for (int i = 0; i < SIZE; i++) {
            e[i].clear();
            vis[i] = false;
        }
        buttons.clear();
        cin.ignore();
    }


    return 0;
}