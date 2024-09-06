#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

int n, f;
const int SIZE = 41;
const int DIFF = 16000;
int a[SIZE]{};
bool typ[SIZE][2]{};
map<pair<int,int>,bool> mem{};

bool dp(int f, int i) {
    // Base case
    if (i == 0) return (f == 0);
    if (mem.find({f,i}) != mem.end()) return mem[{f,i}];

    // Recursive case
    bool inc = dp(f - a[i], i - 1);
    bool ex = dp(f + a[i], i - 1);

    typ[i][0] |= inc;
    typ[i][1] |= ex;

    return mem[{f,i}] = (inc|ex);
}

int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    while (true) {
        cin >> n >> f;
        if (!n&&!f) break;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) typ[i][0] = typ[i][1] = 0;
        mem.clear();
        if (!dp(f, n)) {
            cout << "*";
        } else {
            for (int i = 1; i <= n; i++) {
                if (typ[i][0] and typ[i][1]) cout << "?";
                else if (typ[i][0]) cout << "+";
                else if (typ[i][1]) cout << "-";
                else cout << "#";
            }
        }
        cout << endl;
    }

    return 0;
}