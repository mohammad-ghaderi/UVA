#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

const int inf = 1e18;

struct segmenttree {
    int n;
    vector<pair<int,int>> st; // value, index

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, {0, 0});
    }

    pair<int,int> query(int start, int ending, int l, int r, int node) {
        // non overlapping case
        if (start > r || ending < l) {
            return {0, 0};
        }

        // complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        pair<int,int> q1 = query(start, mid, l, r, 2 * node + 1);
        pair<int,int> q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return ((q1.first >= q2.first)?q1:q2);
    }

    void update(int start, int ending, int node, int index, int value, int idx) {
        // base case
        if (start == ending) {
            st[node] = {value, idx};
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid) {
            // left subtree
            update(start, mid, 2 * node + 1, index, value, idx);
        }
        else {
            // right
            update(mid + 1, ending, 2 * node + 2, index, value, idx);
        }

        st[node] = ((st[node * 2 + 1].first>=st[node * 2 + 2].first) ? st[node * 2 + 1] : st[node * 2 + 2]);

        return;
    }

    pair<int,int> query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }

    void update(int x, int y, int idx) {
        update(0, n - 1, 0, x, y, idx);
    }
};



int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int x;
    queue<int> q{};
    while(cin >> x) q.push(x);
    
    int n = q.size();
    pair<int,int> a[n]{};
    int b[n]{};
    int c = 0;
    while(!q.empty()) a[c++] = {q.front(), c}, q.pop();

    sort(a, a + n);

    int refer[n];

    c = 0;
    b[a[0].second] = c;

    int mx = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].first != a[i-1].first) c++;
        b[a[i].second] = c;
        mx = max(mx, c);
    }

    for (int i = 0; i < n; i++) {
        a[i] = {a[i].second, a[i].first};
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        a[i] = {a[i].second, a[i].first};
    }

    mx++;

    segmenttree tree{};
    tree.init(mx+1);
    int par[n + 1]{};

    int ans = 0, idx = 0;
    for (int i = n - 1; i >= 0; i--) {
        pair<int,int> nxt = tree.query(b[i] + 1, mx);
        tree.update(b[i], nxt.first + 1, i);
        par[i] = nxt.second;
        if (nxt.first + 1 > ans) {
            ans = nxt.first + 1;
            idx = i;
        }
    }

    cout << ans << endl;
    cout << "-\n";

    while(true) {
        cout << a[idx].first  << endl;
        idx = par[idx];
        if (idx == 0) break;
    }

    return 0;
} 