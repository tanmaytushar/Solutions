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
















void solve(){
  int n,a,b;cin >> n >> a >> b;
  vector<vector<pair<int,int>>> adj(n);
  for(int i = 0;i<n-1;i++){
    int u,v,w;cin >> u >> v >> w;
    u--,v--;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  // start a dfs from a and then b;
  auto dfs = [&](int node,int parent,int pathxor,vector<int> &current,auto &&dfs) -> void {
    current[node] = pathxor;
    for(auto &[v,w] : adj[node]){
      if(v == parent) continue;
      dfs(v,node,pathxor ^ w,current,dfs); 
    }
  };
  vector<int> froma(n),fromb(n);
  dfs(a,-1,0,froma,dfs);
  dfs(b,-1,0,fromb,dfs);
  set<int> lookup;
  for(int i = 0;i<n;i++){
    if(i == b) continue;
    lookup.insert(fromb[i]);
  }
  for(int i = 0;i<n;i++){
    int current = froma[i];
    if(lookup.count(current)){
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;
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
