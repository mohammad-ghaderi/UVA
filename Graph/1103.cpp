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

// const int SIZE = 201;
// const int _SIZE = 51;

const int SIZE = 201;
const int _SIZE = 51;

const vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int numbs[6] = {1, 5, 3, 2, 4, 0};
string mp[SIZE]{};
bool R[SIZE][SIZE]{}, valid[SIZE*SIZE];
int island[SIZE][SIZE]{};
bitset<SIZE*SIZE> bb[SIZE*SIZE]{};
int n, m, color, tc = 1;


void get_size(string s) {
    n = 0;
    int i = 0;
    while (s[i] != ' ') {
        n *= 10;
        n += (s[i] - '0');
        i++;
    }
    i++;
    m = 0;
    while (i < s.size() and s[i] != '\n') {
        m *= 10;
        m += (s[i] - '0');
        i++;
    }
    
}

bool check(int i, int j) { return !(i < 0 or j < 0 or i == n or j == m*4); }

void dfs(int i, int j) {
    island[i][j] = color;

    for (auto &[x, y]: dirs) {
        int ii = i + x, jj = j + y;
        if (check(ii, jj)) {
            if (!island[ii][jj] and !R[ii][jj]) {
                dfs(ii, jj);
            }
        } else {
            valid[color] = false;
        }
    }
    
}

void dfs_black(int i, int j) {
    island[i][j] = color;

    for (auto &[x, y]: dirs) {
        int ii = i + x, jj = j + y;
        if (check(ii, jj)) {
            if (R[ii][jj]) {
                if (!island[ii][jj]) dfs_black(ii, jj);
            } else if (valid[island[ii][jj]]) {
                int target_color = island[ii][jj];
                bb[color][target_color] = true;
            }
        }
    }
}

string tobin(char c) {
    string ans;
    switch (c) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'a': return "1010";
        case 'b': return "1011";
        case 'c': return "1100";
        case 'd': return "1101";
        case 'e': return "1110";
        case 'f': return "1111";
        default: return "0000";
    }

}

void decode() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c = mp[i][j];
            string b = tobin(c);
            for (int k = 0; k < 4; k++) {
                R[i][j*4+k] = (b[k] == '1');
            }
        }
    }
}


void solve() {

    for (int i = 0; i < n; i++) cin >> mp[i];

    decode();

    color = 0;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m*4; j++) {
            if (!island[i][j] and !R[i][j]) {
                color++;
                dfs(i, j);
            }
        }
    }

    stack<int> stk{};
    int answer[7]{};

    for (int j = 0; j < m*4; j++) {
        for (int i = n-1; i >- 0; i--) {
            if (!island[i][j] and R[i][j]) {
                color++;
                dfs_black(i, j);
                stk.push(color);
                answer[bb[color].count()]++;
            }
        }
    }

    cout << "Case " << tc << ": ";

    for (auto nmb: numbs) {
        if (answer[nmb]) {
            for (int j = 0; j < answer[nmb]; j++) {
                switch (nmb) {  
                    case 0: 
                        cout << 'W';
                        break;
                    case 1: 
                        cout << 'A';
                        break;
                    case 2: 
                        cout << 'K';
                        break;
                    case 3: 
                        cout << 'J';
                        break;
                    case 4: 
                        cout << 'S';
                        break;
                    case 5: 
                        cout << 'D';
                        break;
                }
            }
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m*4; j++) {
            island[i][j] = 0;
            R[i][j] = false;
        }
        mp[i] = "";
    }

    for (int i = 0; i <= color; i++) bb[i].reset(), valid[i] = true;
}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    string s;
    memset(valid, true, sizeof valid);

    // cin >> t;
    while (getline(cin, s) && s!="0 0") {
        get_size(s);

        solve();
        tc++;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}