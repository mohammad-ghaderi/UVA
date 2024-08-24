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
const int SIZE = 51;

map<string, int> names{};
string dict[SIZE];

int tc = 1;

int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int p, r;
    while(true) {
        cin >> p >> r;
        if (!p and !r) break;
        int c = 0;

        int AM[p][p];
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) AM[i][j] = inf;
            AM[i][i] = 0;
        }

        string name1, name2;
        for (int i = 0; i < r; i++) {
            cin >> name1 >> name2;
            if (names.find(name1) == names.end()) names[name1] = c++;
            if (names.find(name2) == names.end()) names[name2] = c++;
            int c1 = names[name1], c2 = names[name2];
            dict[c1] = name1; dict[c2] = name2;
            
            AM[c1][c2] = 1;
            AM[c2][c1] = 1;
        }

        for (int k = 0; k < p; k++) {
            for (int i = 0; i < p; i++) {
                for (int j = 0; j < p; j++) {
                    AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
                }
            }
        }

        int mx = 0;

        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                mx = max(mx, AM[i][j]);
            }
        }

        cout << "Network " << tc++ << ": ";
        if (mx == inf) cout << "DISCONNECTED\n";
        else cout << mx << endl;

        cout << endl;
        names.clear();

    }

    return 0;
}