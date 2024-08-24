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
const int SIZE = 102;
const vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int,int>> dirs_with_dig = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
const vector<vector<pair<int,int>>> two_dirs = { {{-1, -1}, {-1, 0}, {0, -1}}, {{-1, 1}, {-1, 0}, {0, 1}}, {{1, 1}, {0, 1}, {1, 0}}, {{1, -1}, {1, 0}, {0, -1}}};

struct POS {
    int x, y, d;
    POS(int x, int y, int d) {
        this->x = x;
        this->y = y;
        this->d = d;
    }
};

string mp[SIZE]{};
int island[SIZE][SIZE]{}, island_size[SIZE*SIZE]{};
bool vis[SIZE][SIZE]{};
bool checked_size[SIZE*SIZE]{}, black[SIZE][SIZE]{},reachable[SIZE*SIZE];
queue<POS> q{};
int r = SIZE, c = SIZE, d;
int color = 0;

bool check(int i, int j) { return !(i < 0 or j < 0 or i == r or j == c); }

bool check_two_two() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mp[i][j] == '.') continue;;
            for (auto dir: two_dirs) {
                int dir_cnt = 0;
                for (auto &[x, y]: dir) {
                    int ii = i + x, jj = j + y;
                    if (check(ii, jj) and mp[ii][jj] == '#') dir_cnt++;
                }
                if (dir_cnt == 3) return false;
            }
        }
    }

    return true;
}

void black_dfs(int i, int j) {
    black[i][j] = true;

    for (auto &[x, y]: dirs) {
        int ii = i + x, jj = j + y;
        if (check(ii, jj) and mp[ii][jj] == '#' and !black[ii][jj]) {
            black_dfs(ii, jj);
        } 
    }
}


void flood_fill(int i, int j) {
    island[i][j] = color;
    island_size[color]++;

    for (auto &[dx, dy]: dirs) {
        int ii = i + dx, jj = j + dy;
        if (check(ii, jj) and mp[ii][jj] == '.' and !island[ii][jj]) {
            flood_fill(ii, jj);
        }
    }
}

void _dfs(int x, int y) {
    vis[x][y] = true;
    reachable[island[x][y]] = true;

    for (auto &[dx, dy]:dirs_with_dig) {
        int i = x + dx, j = y + dy;
        if (check(i, j) and !vis[i][j] and mp[i][j] == '.') {
            _dfs(i, j);
        }
    }
}

bool can_reach_grid_edge() {
    for (int i = 0; i < r; i++) {
        if (!vis[i][0] and mp[i][0] == '.') _dfs(i, 0);
        if (!vis[i][c-1] and mp[i][c-1] == '.') _dfs(i, c-1);
    }

    for (int j = 0; j < c; j++) {
        if (!vis[0][j] and mp[0][j] == '.') _dfs(0, j);
        if (!vis[r-1][j] and mp[r-1][j] == '.') _dfs(r-1, j);

    }

    for (int i = 1; i <= color; i++) {
        if (!reachable[i]) return false;
    }

    return true;
} 


bool solve() {

    while (!q.empty()) q.pop();

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            vis[i][j] = false;
            island_size[island[i][j]] = 0;
            checked_size[island[i][j]] = false;
            reachable[island[i][j]] = false;
            black[i][j] = false;
            island[i][j] = 0;
        }
    }

    cin >> r >> c >> d;
    color = 0;

    for (int i = 0, xx, yy, nn; i < d; i++) {
        cin >> xx >> yy >> nn;
        POS p(xx, yy, nn);
        q.push(p);
    }

    for (int i = 0; i < r; i++) {
        cin >> mp[i];
    }
    
    // check each grid 2x2 should have at least one blank space
    if (!check_two_two()) return false;
    
    bool done = false;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mp[i][j] == '.') continue;
            if (black[i][j]) continue;
            if (done) return false;
            done = true;
            black_dfs(i, j);  
        }
    }

    // flood fill for finding blank spaces and thier size
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mp[i][j] == '.' and !island[i][j]) {
                color++;
                flood_fill(i, j);
            }
        }
    }

    while (q.size()) {
        POS tp = q.front();
        q.pop();

        if (mp[tp.x][tp.y] == '#') return false;
        int color_now = island[tp.x][tp.y];
        if (checked_size[color_now]) return false;
        if (island_size[color_now] != tp.d) return false;
        checked_size[color_now] = true;
    }

    for (int i = 1; i <= color; i++) {
        if (!checked_size[i]) return false;
    }

    return can_reach_grid_edge();
}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (solve()) cout << "solved\n";
        else cout << "not solved\n";
    }

    return 0;
}