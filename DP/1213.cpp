#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int SIZE = 187;
int LIM = SIZE;
const int primes[SIZE] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117};
int mem[1121][SIZE][15]{};


int dp(int number, int idx, int k) {
    // Base case
    if (number == 0 and k == 0) return 1;
    if (number <= 0 or k == 0 or idx == LIM) return 0;
    if (~mem[number][idx][k]) return mem[number][idx][k];
    
    // Recursive case
    int answer = dp(number, idx + 1, k);
    if (primes[idx] <= number) answer += dp(number - primes[idx], idx + 1, k - 1);
    
    return mem[number][idx][k] = answer;
}


void solve() {


}


int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n, k;
    while(true) {
        cin >> n >> k;
        if (!n&&!k) break;
        LIM = SIZE;
        for (int i = 0; i < SIZE; i++) {
            if (primes[i] > n) LIM = i;
        }
        for (int nmb = 0; nmb <= n; nmb++) for (int i = 0; i <= LIM; i++) for (int j = 0; j <= k; j++) mem[nmb][i][j] = -1;
        cout << dp(n, 0, k) << endl;
    }

    return 0;
}