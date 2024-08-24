#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int SIZE = 1000;
const int inf = 1e9;
int n, m, b, p;

vector<pair<int,int>> g[SIZE]{};
int dist[SIZE]{};
bool isBank[SIZE]{};


void dijkstra() {
    set<pair<int,int>> pq{};
    for (int u = 0; u < n; u++) pq.emplace(dist[u], u);
    
    while(!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());
        if (dist[u] < d) continue;

        for (auto &[v, w]: g[u]) {
            if (dist[u] + w < dist[v]) {
                pq.erase(pq.find({dist[v],v}));
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    string line;
    while(scanf("%d%d%d%d",&n,&m,&b,&p) == 4) {

        for (int i = 0, u, v, w; i < m; i++) {
            scanf("%d%d%d", &u,&v,&w);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }

        for (int u = 0; u < n; u++) dist[u] = inf;

        for (int i = 0, x; i < b; i++) {
            scanf("%d",&x);
            isBank[x] = true;
        }

        for (int i = 0, x; i < p; i++) {
            scanf("%d",&x);
            dist[x] = 0;
        }

        dijkstra();

        int ans = 0;
        queue<int> banks{};
        
        for (int u = 0; u < n; u++) {
            if (!isBank[u]) continue;
            if (dist[u] < ans) continue;
            if (dist[u] == ans) banks.push(u);
            else {
                ans = dist[u];
                while(!banks.empty()) banks.pop();
                banks.push(u);
            }
        }

        cout << banks.size() << ' ';
        if (ans == inf) cout << "*\n";
        else cout << ans << endl;

        while(!banks.empty()) {
            cout << banks.front();
            banks.pop();
            if (!banks.empty()) cout << ' ';
        }

        cout << endl;

        for (int u = 0; u < n; u++) {
            g[u].clear();
            isBank[u] = false;
        }
    }

    return 0;
}