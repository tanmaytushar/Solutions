#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
#define endl '\n'
#define ll long long
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}













int mod_add(int a, int b) {
    return (a + b) % MOD;
}

int mod_sub(int a, int b) {
    return (a - b + MOD) % MOD;
}

int mod_mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int mod_pow(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = mod_mul(res, a);
        a = mod_mul(a, a);
        b >>= 1;
    }
    return res;
}

/*
The idea is to treat every bit seperately and after lets say we fix R 
Then what is it contribution
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0;
    for (int b = 0; b <= 30; ++b) {
        int prefix = 0;
        int cnt[2] = {1, 0};
        long long sum_len[2] = {0, 0};   
        for (int i = 0; i < n; i++) {
            if ((a[i] >> b) & 1)
                prefix ^= 1;
            // Subarrays ending at i and starting from positions with opposite parity
            int valid_len = (i + 1) * cnt[prefix ^ 1] - sum_len[prefix ^ 1];
            valid_len %= MOD;
            if (valid_len < 0) valid_len += MOD;
            ans = mod_add(ans, mod_mul(1 << b, valid_len));
            cnt[prefix]++;
            sum_len[prefix] = (sum_len[prefix] + (i + 1)) % MOD;
        }
    }

    cout << ans << '\n';
}















signed main() {
   auto begin = std::chrono::high_resolution_clock::now();
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  freopen("Error.txt", "w", stderr);
#endif
   int t = 1;
   while (t--) {
     solve(); 
   }
   auto end = std::chrono::high_resolution_clock::now();
   auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
   cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
   return 0;
}
