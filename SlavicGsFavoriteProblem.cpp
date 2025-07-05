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
I almost had the approach we would run a dfs both a and b and so that a -> c ^ d -> b = 0 
=> a -> c = d -> d,
Only catch here when we are on the dfs call for a we cannot go through b to the elements in the subtree to b 
since we can only enter b if we have a xor value of 0
*/






const int N = 1e5 + 10;
vector<pair<int, int>> adj[N];
set<int> s;
int n, a, b;

void dfs1(int u, int par, int x) {
    if (u == b) return; 
    s.insert(x);
    for (auto [v, w] : adj[u]) {
        if (v == par) continue;
        dfs1(v, u, x ^ w);
    }
}

bool dfs2(int u, int par, int x) {
    if (u != b && s.count(x)) return true;
    for (auto [v, w] : adj[u]) {
        if (v == par) continue;
        if (dfs2(v, u, x ^ w)) return true;
    }
    return false;
}

void solve() {
    s.clear();
    cin >> n >> a >> b;
    --a, --b;

    for (int i = 0; i < n; ++i)
        adj[i].clear();

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dfs1(a, -1, 0);
    if (dfs2(b, -1, 0))
        cout << "YES\n";
    else
        cout << "NO\n";
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
