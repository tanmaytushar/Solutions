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






class LazySegmentTree {
    int n;
    vector<long long> tree, lazy;
public:
    LazySegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }
    void build(const vector<int>& a, int node = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * node, l, mid);
        build(a, 2 * node + 1, mid + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node] * (r - l + 1);
            if (l != r) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void update(int ql, int qr, int val, int node = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        push(node, l, r);
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(ql, qr, val, 2 * node, l, mid);
        update(ql, qr, val, 2 * node + 1, mid + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    long long query(int ql, int qr, int node = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        push(node, l, r);
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(ql, qr, 2 * node, l, mid) +
               query(ql, qr, 2 * node + 1, mid + 1, r);
    }
};



/*
The idea is to construct the answer one at a time from the end by swapping adjacent elements and count the number of operations taken 
based on number of opearations you determine your final answer
*/



void solve() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (auto &it : a) cin >> it;
  for (auto &it : b) cin >> it;
 
  map<int, int> m1, m2;
  map<int, set<int>> indices;
  for (int i = 0; i < n; i++) {
    m1[a[i]]++, m2[b[i]]++;
    indices[a[i]].insert(i);
  }

  for (auto [key, freq] : m1) {
    if (m2[key] != freq) {
      cout << "No" << endl;
      return;
    }
  }
 
  if (n == 1) {
    cout << (a[0] == b[0] ? "Yes" : "No") << endl;
    return;
  }
 
  LazySegmentTree seg(n);
  seg.build(vector<int>(n, 0));
 
  int totalops = 0;
  for (int i = n - 1; i >= 2; i--) {
    int index = *indices[b[i]].begin();
    indices[b[i]].erase(indices[b[i]].begin());
    int actualindex = index + seg.query(index,index);
    int opsrequired = i - actualindex;
    totalops += opsrequired;
    seg.update(index, n - 1, -1);
  }
  int index = *indices[b[0]].begin();
  int actualindex = index + seg.query(index,index);
  if (actualindex == 0) {
    cout << (totalops % 2 == 0 ? "Yes" : "No") << endl;
  } else {
    cout << (totalops % 2 == 1 ? "Yes" : "No") << endl;
  }
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
