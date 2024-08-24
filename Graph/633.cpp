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
const int SIZE = 61;

int n, r1, c1, r2, c2, xp, yp;
bool mp[SIZE][SIZE]{}, vis[SIZE][SIZE]{};
int val[SIZE][SIZE]{};

const vector<pair<int,int>> dirs[2] = {{{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {-1,2}, {1,-2}, {-1,-2}}, {{2,2}, {2,-2}, {-2,2}, {-2,-2}}};

bool check(int x, int y) { return !(x < 1 or y < 1 or x > 2*n or y > 2*n);}

queue<pair<pair<int,int>,int>> q{}; // {x,y}, type:0->K, 1->B, 2->T, -1->none


int bfs() {
    while(!q.empty())q.pop();
    for (int i = 1; i <= 2*n; i++) for (int j = 1; j <= 2*n; j++) vis[i][j] = false;

    q.push({{r1,c1}, -1});
    vis[r1][c1] = true;
    val[r1][c1] = 0;
    
    while(!q.empty()) {
        auto ft = q.front();
        q.pop();
        int x = ft.ff.ff, y = ft.ff.ss, type = ft.ss;
        if (x == r2 and y == c2) return val[x][y];

        if (type != 0) {
            for (auto &[dx, dy]: dirs[0]) {
                int xx = x + dx, yy = y + dy;
                if (check(xx, yy) and !mp[xx][yy] and (!vis[xx][yy] or val[xx][yy] >= val[x][y] + 1)) {
                    q.push({{xx,yy}, 0});
                    val[xx][yy] = val[x][y] + 1;
                    vis[xx][yy] = true;
                }
            }
        }
        if (type != 1) {
            for (auto &[dx, dy]: dirs[1]) {
                int xx = x + dx, yy = y + dy;
                if (check(xx, yy) and !mp[xx][yy] and (!vis[xx][yy] or val[xx][yy] >= val[x][y] + 1)) {
                    q.push({{xx,yy}, 1});
                    val[xx][yy] = val[x][y] + 1;
                    vis[xx][yy] = true;
                }
            }
        }
        if (type != 2) {
            int xx = (2 * n + 1) - x, yy = (2 * n + 1) - y;
            if (check(xx, yy) and !mp[xx][y] and (!vis[xx][y] or val[xx][y] >= val[x][y] + 1)) {
                q.push({{xx,y}, 2});
                val[xx][y] = val[x][y] + 1;
                vis[xx][y] = true;
            }
            if (check(x, yy) and !mp[x][yy] and (!vis[x][yy] or val[x][yy] >= val[x][y] + 1)) {
                q.push({{x,yy}, 2});
                val[x][yy] = val[x][y] + 1;
                vis[x][yy] = true;
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
    
    while(true) {
        cin >> n;
        if (!n) break;
        cin >> r1 >> c1;
        cin >> r2 >> c2;

        while(true) {
            cin >> xp >> yp;
            if (!xp and !yp) break;
            mp[xp][yp] = true;
        }

        int ans = bfs();
        if (~ans) cout << "Result : " << ans << endl;
        else cout << "Solution doesn't exist\n";

        for (int i = 1; i <= 2*n; i++) 
            for (int j = 1; j <= 2*n; j++)
                mp[i][j] = false;

    }

    return 0;
}