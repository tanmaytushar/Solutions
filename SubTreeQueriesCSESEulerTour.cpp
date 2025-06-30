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







struct SegmentTree {
    int n;
    vector<long long> tree;

    SegmentTree(const vector<int>& a) {
        n = a.size();
        tree.resize(2 * n);
        for (int i = 0; i < n; ++i) tree[i + n] = a[i];
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void pointUpdate(int pos, int val) {
        pos += n;
        tree[pos] = val;
        while (pos > 1) {
            pos >>= 1;
            tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
        }
    }

    long long rangeSum(int l, int r) { // [l, r)
        l += n, r += n;
        long long res = 0;
        while (l < r) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
            l >>= 1; r >>= 1;
        }
        return res;
    }
};


/*
The idea is perform a euler tour on the tree -> This allows you to flatten the Tree 
Euler tour tells every element that is in the range intime[i] < x < outtime[x] is in the subtree of node i
*/





void solve() {
    int n, q, globaltime = 0;
    cin >> n >> q;
    vector<int> values(n);
    for (auto &it : values) cin >> it;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> intime(n), outtime(n);
    auto dfs = [&](int node, int parent, auto &&f) -> void {
        intime[node] = globaltime++;
        for (auto &it : adj[node]) {
            if (it != parent)
                f(it, node, f);
        }
        outtime[node] = globaltime;
    };
    dfs(0, -1, dfs);

    vector<int> a(2 * n, 0);
    for (int i = 0; i < n; i++)
        a[intime[i]] = values[i];

    SegmentTree st(a);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int s, x; cin >> s >> x; s--;
            st.pointUpdate(intime[s], x);
        } else {
            int s; cin >> s; s--;
            cout << st.rangeSum(intime[s], outtime[s]) << " ";
        }
    }
    cout << "\n";
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
