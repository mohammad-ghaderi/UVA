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
const int SIZE = 1001;

const vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,1}, {-1,-1}, {1,-1}};

string mp[SIZE]{};
bool vis[SIZE][SIZE]{};
int val[SIZE][SIZE]{};
int n, m;

deque<pair<int,int>> q{};

bool check(int x, int y) { return !(x < 0 or y < 0 or x == n or y == m);}

int bfs(int x, int y, int a, int b) {
    while (!q.empty()) q.pop_front();
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) vis[i][j] = false;
    q.push_front({x,y});
    vis[x][y] = true;
    val[x][y] = 0;

    int ans = INT_MAX;

    while(!q.empty()) {
        auto tp = q.front();
        q.pop_front();
        int  i = tp.ff, j = tp.ss;

        if (i == a and j == b) return val[i][j];
        int initial_dx, initial_dy;

        switch (mp[i][j]) {
            case '0': initial_dx = -1, initial_dy = 0; break;
            case '1': initial_dx = -1, initial_dy = 1; break;
            case '2': initial_dx = 0, initial_dy = 1; break;
            case '3': initial_dx = 1, initial_dy = 1; break;
            case '4': initial_dx = 1, initial_dy = 0; break;
            case '5': initial_dx = 1, initial_dy = -1; break;
            case '6': initial_dx = 0, initial_dy = -1; break;
            case '7': initial_dx = -1, initial_dy = -1; break;
        }

        int ix = i + initial_dx, jy = j + initial_dy;
        if (check(ix, jy) and (!vis[ix][jy] or val[ix][jy] > val[i][j])) {
            q.push_front({ix,jy});
            vis[ix][jy] = true;
            val[ix][jy] = val[i][j];
        } 

        for (auto &[dx, dy]: dirs) {
            int xx = i + dx, yy = j + dy;
            if (check(xx, yy) and (!vis[xx][yy] or val[xx][yy] > val[i][j]+1)) {
                q.push_back({xx,yy});
                vis[xx][yy] = true;
                val[xx][yy] = val[i][j] + 1;
            }
            
        }
    }
    return ans;
}




int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> mp[i];
    }

    int q, sx,sy, tx, ty;
    cin >> q;

    while(q--) {
        cin >> sx >> sy >> tx >> ty;
        int ans = bfs(sx-1, sy-1, tx-1, ty-1);
        cout << ans << endl;
    }


    return 0;
}