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
const int SIZE = 101;
string mp[SIZE]{};
string instructions;
bool vis[SIZE][SIZE]{};
int n, m, s;
int i_now, j_now, ori, ans;

bool check(int i, int j) { return !(i < 0 or j < 0 or i == n or j == m or mp[i][j] == '#' );}


void find_pos() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '.' or mp[i][j] == '#' or mp[i][j] == '*') continue;
            i_now = i;
            j_now = j;
            switch (mp[i][j]) {
                case  'N':
                    ori = 0;
                    break;
                case  'S':
                    ori = 1;
                    break;
                case  'L':
                    ori = 2;
                    break;
                case  'O':
                    ori = 3;
                    break;
            }
        }
    }
}

void move(char c){
    if ( c == 'E') {
        if (ori == 0) ori = 3;
        else if (ori == 1) ori = 2;
        else if (ori == 2) ori = 0;
        else ori = 1;
    } else if (c == 'D') {
        if (ori == 0) ori = 2;
        else if (ori == 1) ori = 3;
        else if (ori == 2) ori = 1;
        else ori = 0;
    } else { // Forward
        int i_target = i_now;
        int j_target = j_now;
        if (ori == 0) i_target = i_now - 1;
        else if (ori == 1) i_target = i_now + 1;
        else if (ori == 2) j_target = j_now + 1;
        else j_target = j_now - 1;
        if (check(i_target, j_target)) {
            i_now = i_target;
            j_now = j_target;
        }
        if (!vis[i_now][j_now] and mp[i_now][j_now] == '*') ans++;
        vis[i_now][j_now] = true;
    }
}

void walk(int k) {
    if (k == s) return;
    move(instructions[k]);
    walk(++k);
}

int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  

    string line;
    while (getline(cin, line), line != "0 0 0") {
        stringstream temp;
        temp << line;
        temp >> n >> m >> s;

        for (int i = 0; i < n; i++) cin >> mp[i];
        
        cin >> instructions;

        find_pos();

        ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = false;
            }
        }

        walk(0);

        cout << ans << endl;

        cin.ignore();
    }
    return 0;
}