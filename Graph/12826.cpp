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
const int SIZE = 8;
int r1, c1, r2, c2, r3, c3, tc = 1;

const vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
queue<pair<int,int>> q{};
int val[SIZE][SIZE];
bool vis[SIZE][SIZE]{};

bool check(int x, int y) { return !(x < 0 or y < 0 or x == SIZE or y == SIZE);}

int bfs() {
    while (!q.empty()) q.pop();
    for (int i = 0; i < SIZE; i++) for (int j = 0; j < SIZE; j++) vis[i][j] = false;

    q.push({r1,c1});
    vis[r1][c1] = true;
    val[r1][c1] = 0;

    int ans = 16;

    while (!q.empty()) {
        auto &[x,y] = q.front();
        q.pop();
        if (x == r2 and y == c2) ans = min(ans, val[x][y]);
        if (x == r3 and y == c3) continue;

        for (auto &[dx, dy]: dirs) {
            int xx = x + dx, yy = y + dy;
            if (check(xx,yy) and (!vis[xx][yy] or val[xx][yy] > val[x][y] + 1)) {
                q.push({xx,yy});
                vis[xx][yy] = true;
                val[xx][yy] = val[x][y] + 1;
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

    string line;    
    while(getline(cin, line), line != "") {
        stringstream s;
        s << line;
        s >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
        r1 = SIZE - r1;
        r2 = SIZE - r2;
        r3 = SIZE - r3;
        c1--; c2--; c3--;


        cout << "Case " << tc++ << ": " << bfs() << endl;
    }
    

    return 0;
}