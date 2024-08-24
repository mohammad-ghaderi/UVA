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
const int inf = 1e9;
const int SIZE = 29;

tuple<int,int,int> AM[SIZE][SIZE]{}; // SP, cnt, last

int s, p;
queue<int> ans{};

void get_path(int x, int y) {

    auto [val, cnt, last] = AM[x][y];
    if (cnt == 1) {
        ans.push(x);
        ans.push(y);
        return;
    }
    get_path(x, last);
    get_path(last, y);
}

int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> s >> p;
    char u, v;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) AM[i][j] = {inf, 0, -1};
        AM[i][i] = {0, 0, -1};
    }

    for (int i = 0, w; i < p; i++) {
        cin >> u >> v >> w;
        AM[u-'A'][v-'A'] = {w, 1, -1};
        AM[v-'A'][u-'A'] = {w, 1, -1};
    }

    for (int k = 0; k < SIZE; k++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                auto [val, cnt, last] = AM[i][j];
                auto [val1, cnt1, last1] = AM[i][k];
                auto [val2, cnt2, last2] = AM[k][j];
                if (val1 + val2 < val or (val1 + val2 == val and cnt1 + cnt2 < cnt)) {
                    AM[i][j] = {val1 + val2, cnt1 + cnt2, k};
                }
            }
        }
    }
    
    int q, x, y;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        x = u - 'A';
        y = v - 'A';

        get_path(x, y);

        char last = '$';
        while(!ans.empty()) {
            char x = 'A' + ans.front();
            ans.pop();
            if (x == last) continue;
            last = x;
            cout << x;
            if (!ans.empty()) cout << ' ';
        }
        cout << endl;
    }

    return 0;
}