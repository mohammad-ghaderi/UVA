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
const int SIZE = 1e3+3;
const vector<pair<int,int>> dirs = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
int r, c;
bool mp[SIZE][SIZE], vis[SIZE][SIZE]{};
queue<pair<int,pair<int,int>>> q{};

bool check(int i, int j) { return !(i < 0 or j < 0 or i == r or j == c );}

int bfs(int x, int y, int a, int b) {
    while(!q.empty()) q.pop();
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) 
            vis[i][j] = false;
    q.push({0, {x, y}});
    vis[x][y] = true;

    while(!q.empty()) {
        auto ft = q.front();
        int dest = ft.ff;
        int x_pos = ft.ss.ff, y_pos = ft.ss.ss;
        q.pop();

        if (x_pos == a && y_pos == b) return dest;
        
        for (auto &[dx, dy]: dirs) {
            int xx = x_pos + dx, yy = y_pos + dy;
            if (check(xx, yy) and mp[xx][yy] and !vis[xx][yy]) {
                q.push({dest + 1, {xx, yy}});
                vis[xx][yy] = true;
            }
        }
    }

    return 0;
}

int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    while (true) {
        cin >> r >> c;
        if (!r&&!c) break;;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                mp[i][j] = true;
                vis[i][j] = false;
            }
        }

        int bmb_row_cnt;
        cin >> bmb_row_cnt;

        for (int t = 0, cnt, row; t < bmb_row_cnt; t++) {
            cin >> row >> cnt;
            for (int tt = 0, column; tt < cnt; tt++) {
                cin >> column;
                mp[row][column] = false;
            }
        }

        int source_x, source_y, dest_x, dest_y;
        cin >> source_x >> source_y;
        cin >> dest_x >> dest_y;
        
        cout << bfs(source_x, source_y, dest_x, dest_y) << endl;

    }
    

    return 0;
}