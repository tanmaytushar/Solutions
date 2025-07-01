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








/*
-> the idea is pretty first and foremost simply the given equation of Bl + Bm + Br - (r-l)
-> Bl+l + Bm + Br-r
based on this you can either iterate on the M and look for best Bl and Br using prefix suffix 
or design DP states 
*/
const int NEG_INF = -1e18;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &it : a) cin >> it;
    vector<vector<int>> dp(n + 1, vector<int>(3, -1));
    auto rec = [&](int index, int count, auto &&f) -> int {
        if (count == 3) return 0;
        if (index >= n) return NEG_INF;
        if (dp[index][count] != -1) return dp[index][count];
        int nottake = f(index + 1, count, f);
        int take = NEG_INF;
        if (count == 0) take = a[index] + index + f(index + 1, count + 1, f);
        else if (count == 1) take = a[index] + f(index + 1, count + 1, f);
        else if (count == 2) take = a[index] - index + f(index + 1, count + 1, f);
        return dp[index][count] = max(take, nottake);
    };
    cout << rec(0, 0, rec) << "\n";
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
