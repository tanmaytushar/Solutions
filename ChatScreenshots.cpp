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






class SegmentTree {
    vector<int> tree;
    int n;
public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
    void build(const vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * node + 1, l, mid);
        build(arr, 2 * node + 2, mid + 1, r);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    void pointUpdate(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node + 1, l, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, r, idx, val);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    int rangeSum(int ql, int qr) {
        return query(0, 0, n - 1, ql, qr);
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return 0; 
        if (ql <= l && r <= qr)
            return tree[node]; 
        int mid = (l + r) / 2;
        int left = query(2 * node + 1, l, mid, ql, qr);
        int right = query(2 * node + 2, mid + 1, r, ql, qr);
        return left + right;
    }
};









void solve(){
  int n,q,globaltime = 0;cin >> n >> q;
  vector<int> values(n);
  for(auto &it : values) cin >> it;
  vector<vector<int>> adj(n);
  for(int i = 0;i<n-1;i++){
    int u,v;cin >> u >> v;
    u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> intime(n),outtime(n);
  auto dfs = [&](int node,int parent,auto &&f) -> void{
    intime[node] = globaltime;
    globaltime++;
    for(auto &it : adj[node]){
      f(it,node,f);
    }
    outtime[node] = globaltime;
    globaltime++;
  };
  dfs(0,-1,dfs);
  vector<int> a(2*n,0);
  for(int i = 0;i<n;i++){
    a[intime[i]] = values[i];
  }
  SegmentTree st(a);
  while(q--){
    int type;cin >> type;
    if(type == 1){
      int s,x;cin >> s >> x; s--;
      st.pointUpdate(s,x);
    }else{
     int s;cin >> s;s--;
     int time1 = intime[s],time2 = outtime[s];
     int ans = st.rangeSum(time1,time2); 
     cout << ans << " ";
    }
  }
  cout << endl;
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
