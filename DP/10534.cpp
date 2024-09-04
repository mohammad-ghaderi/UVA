#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

int n;


struct segmenttree {
    int n;
    vector<int> st;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, 0);
    }

    void build(int start, int ending, int node, vector<int> &v) {
        // leaf node base case
        if (start == ending) {
            st[node] = v[start];
            return;
        }

        int mid = (start + ending) / 2;

        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);

        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }

    int query(int start, int ending, int l, int r, int node) {
        // non overlapping case
        if (start > r || ending < l) {
            return 0;
        }

        // complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return max(q1, q2);
    }

    void update(int start, int ending, int node, int index, int value) {
        // base case
        if (start == ending) {
            st[node] = value;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid) {
            // left subtree
            update(start, mid, 2 * node + 1, index, value);
        }
        else {
            // right
            update(mid + 1, ending, 2 * node + 2, index, value);
        }

        st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);

        return;
    }

    void build(vector<int> &v) {
        build(0, n - 1, 0, v);
    }

    int query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }

    void update(int x, int y) {
        update(0, n - 1, 0, x, y);
    }
};

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    while(cin >> n) {
        int a[n];

        int mx = 0;
        for (int i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]);

        segmenttree mn_left{}, mn_right{};
        mn_left.init(mx+1);
        mn_right.init(mx+1);

        int left[n]{}, right[n]{};
        

        mn_left.update(a[0], 1);
        for (int i = 1; i < n; i++) {
            left[i] = mn_left.query(0, a[i] - 1);
            mn_left.update(a[i], left[i] + 1);
        }

        mn_right.update(a[n-1], 1);
        for (int i = n - 2; i >= 0; i--) {
            right[i] = mn_right.query(0, a[i] - 1);
            mn_right.update(a[i], right[i] + 1);
        }

        int ans = 1;
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, 2 * min(left[i], right[i]) + 1);
        }

        cout << ans << endl;

    }

    return 0;
}