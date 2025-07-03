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










int compute(int n, vector<vector<int>> &adj, vector<int> &values) {
  int total = 0;
  for (int start = 0; start < n; ++start) {
    vector<int> freq(n + 2, 0);
    set<int> missing;
    for (int i = 0; i <= n + 1; ++i) missing.insert(i);
    function<void(int, int)> dfs = [&](int u, int p) {
      int val = values[u];
      if (++freq[val] == 1) missing.erase(val);
      if(u >= start){
        total += *missing.begin(); 
      }
      for (int v : adj[u]) {
        if (v != p) dfs(v, u);
      }
      if (--freq[val] == 0) missing.insert(val); 
    };
    dfs(start, -1);
  }
  return total;
}

/*
The idea is to minimise the mex for every path i.e its better to put smaller values at the leaves 
Once we have figured out the value for every node we need to calculuate the mex from every node to every other node using dfs 
You also learnt how you calculuate mex on an list that is dynamic 
*/



void solve(){
  int n; cin >> n;
  vector<vector<int>> adj(n);
  for(int i = 0; i < n - 1; i++){
    int u, v; cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> values(n), indegree(n);
  for(int i = 0; i < n; i++){
    indegree[i] = adj[i].size();
  }
  int current = 0;
  queue<int> q;
  for(int i = 0; i < n; i++){
    if(indegree[i] == 1) q.push(i);
  }
  while(!q.empty()){
    int node = q.front(); q.pop();
    values[node] = current++;
    for(auto &it : adj[node]){
      indegree[it]--;
      if(indegree[it] == 1) q.push(it);
    }
  }
  debug(values);
  int ans = compute(n,adj,values);
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
