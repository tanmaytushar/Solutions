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
















const int MAXN = 2e5 + 5;
struct SegmentTree {
    vector<int> tree, lazy;
    int size;

    SegmentTree(int n) {
        size = n + 2;
        tree.assign(4 * size, 0);
        lazy.assign(4 * size, 0);
    }

    void push(int node, int l, int r) {
        if (lazy[node]) {
            tree[node] += lazy[node];
            if (l != r) { 
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);
        if (r < ql || l > qr) return;
        if (ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int l, int r, int idx) {
        push(node, l, r);
        if (l == r) return tree[node];
        int mid = (l + r) / 2;
        if (idx <= mid) return query(node * 2, l, mid, idx);
        else return query(node * 2 + 1, mid + 1, r, idx);
    }

    void range_add(int l, int r, int val) {
        update(1, 0, size - 1, l, r, val);
    }

    int point_get(int idx) {
        return query(1, 0, size - 1, idx);
    }
};


/*
Approach is Rather then finding the total number of MEX values for each K 
Determine how many K does a MEX value effect 
MEX can never be greater then the intial MEX of the array 
Go From 0 -> MEX(a)
for a MEX value of M -> it is possible iff we can remove all the M from the array and also keep all the values from 0 -> M-1
This given us a range of M will contribute to
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a) cin >> it;
    map<int, int> f;
    for (int x : a)
        f[x]++;
    vector<int> possible(n + 1, false);
    possible[0] = 1;
    for (int i = 1; i <= n; i++) {
        possible[i] = possible[i - 1] && (f[i - 1] > 0);
    }
    SegmentTree st(n);
    for (int i = 0; i <= n; i++) {
        if (!possible[i]) break;
        int l = f[i],r = n-i;
        if (l <= r)
            st.range_add(l,r,1);
    }
    for (int k = 0; k <= n; k++) {
        cout << st.point_get(k) << " ";
    }
    cout << '\n';
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
