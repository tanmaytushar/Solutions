#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
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
-> the numbers are small then allows us to do as n * 2 ^ k dp 
-> dp[i][j] = take + not_take
-> not_take = dp[i+1][j]
-> take = dp[i+1][j & a[i]];
-> take could we are picking up an element for the first time i.e why 64 a sentinal value outside the range 
final subproblem (0,64);
*/


void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &it : a) cin >> it;
  vector<vector<int>> dp(n + 1, vector<int>(65, -1));
  auto rec = [&](int i, int j, auto &&f) -> int {
    if (i == n)
      return (j != 64 && set_bits(j) == k) ? 1 : 0;
    if (dp[i][j] != -1) return dp[i][j];
    int not_take = f(i + 1, j, f);
    int take = f(i + 1, j == 64 ? a[i] : (j & a[i]), f);
    return dp[i][j] = mod_add(take, not_take);
  };
  int ans = rec(0, 64, rec); 
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
   int t;
   cin >> t;
   while (t--) {
     solve(); 
   }
   auto end = std::chrono::high_resolution_clock::now();
   auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
   cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
   return 0;
}
