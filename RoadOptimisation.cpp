#include <bits/stdc++.h>
using namespace std;
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
















void solve() {
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> pos(n), limit(n);
    for (auto &it : pos) cin >> it;
    for (auto &it : limit) cin >> it;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    function<int(int, int)> rec = [&](int index, int left) -> int {
        if (left < 0) return 1e9;
        if (index == n) return 0;
        if (dp[index][left] != -1) return dp[index][left];

        int ans = 1e9;
        // Try every possible next sign to jump to (removing all the signs in between)
        for (int next = index + 1; next <= n;next++) {
            int removed = next - index - 1;
            if (left - removed < 0) continue;
            int dist = (next < n ? pos[next] : l) - pos[index];
            int time = dist * limit[index];
            ans = min(ans, time + rec(next, left - removed));
        }
        return dp[index][left] = ans;
    };

    cout << rec(0, k) << endl;
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
