#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int SIZE = 110;
int n, m;
string mp[SIZE]{};
bool vis[SIZE][SIZE]{};
queue<pair<pair<int,int>,int>> q{};

const vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
const vector<pair<int,int>> knight_dir = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {-1,2}, {1,-2}, {-1,-2}};

bool check(int x, int y) {return !(x < 0 or y < 0 or x == n or y == m);}

int bfs(int si, int sj) {
    while(!q.empty()) q.pop();
    q.push({{si, sj},0});
    vis[si][sj] = true;

    while (!q.empty()) {
        auto ft = q.front();
        q.pop();
        int x = ft.first.first, y = ft.first.second, step = ft.second;

        if (mp[x][y] == 'B') return step;

        for (auto &[dx, dy]:dirs) {
            int xx = x + dx, yy = y + dy;
            if (check(xx, yy) and mp[xx][yy] != '#' and !vis[xx][yy]) {
                q.push({{xx,yy},step+1});
                vis[xx][yy] = true;
            }
        }
    }
    
    return -1;
}


void solve() {
    cin >> n >> m;

    int si, sj;

    for (int i = 0; i < n; i++) {
        cin >> mp[i];
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 'A') {
                si = i;
                sj = j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if  (mp[i][j] != 'Z') continue;
            for (auto &[dx, dy]: knight_dir) {
                int x = i + dx, y = j + dy;
                if (check(x,y) and mp[x][y] == '.') mp[x][y] = '#';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if  (mp[i][j] == 'Z') mp[i][j] = '#';
        }
    }

    int ans = bfs(si,sj);
        
    if (~ans) cout << "Minimal possible length of a trip is " << ans << endl;
    else cout << "King Peter, you can't go now!\n";


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = false;
        }
    }

}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}