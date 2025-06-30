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
The author of the screenshot is always in the first position, so based on his screenshot, 
nothing can be said about his first position. The rest of the chat participants are ordered based on the real order.
Build a graph of n vertices from Aj to Aj+1 for all j except the first one 
if there is an order to them -> topologicalSort there would exist a topologicalSort
*/





bool topologicalSort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; ++u)
        for (int v : adj[u])
            indegree[v]++;
    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (indegree[i] == 0)
            q.push(i);
    int count = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        count++;
        for (int v : adj[u]) {
            if (--indegree[v] == 0)
                q.push(v);
        }
    }
    return count == n; 
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < k; i++) {
        vector<int> temp(n);
        for (int j = 0; j < n; j++) {
            cin >> temp[j];
            temp[j]--;
        }
        for (int j = 1; j < n - 1; j++) {
            int u = temp[j], v = temp[j + 1];
            adj[u].push_back(v);
        }
    }
    cout << (topologicalSort(n, adj) ? "Yes" : "No") << endl;
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
