#include <bits/stdc++.h>
#include <ostream>
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














class SparseTable {
    vector<vector<int>> st;
    vector<int> log;
    int n;

public:
    SparseTable(const vector<int>& a) {
        n = a.size();
        log.resize(n + 1);
        log[1] = 0;
        for (int i = 2; i <= n; i++)
            log[i] = log[i / 2] + 1;

        int K = log[n] + 1;
        st.assign(n, vector<int>(K));
        for (int i = 0; i < n; i++)
            st[i][0] = a[i];

        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int l, int r) {
        int j = log[r - l + 1];
        return max(st[l][j], st[r - (1 << j) + 1][j]);
    }
};


/*
First check is (xs % k != xf % k) || (ys % k != yf % k) then the answer is no, 
Second check if the largest blocked col from start to end is smaller then the possible max row robot can get to using k steps as time 
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto &it : a) cin >> it;
    SparseTable st(a);
    int q;cin >> q;
    while (q--) {
        int xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;
        ys--, yf--;
        if ((xs % k != xf % k) || (ys % k != yf % k)) {
            cout << "No\n";
            continue;
        }
        // Get the highest row robot can reach aligned with k
        int rem = xs % k,maxRow = n - (n - rem) % k;
        int tallestBlock = st.query(min(ys,yf),max(ys,yf));
        if (tallestBlock < maxRow)
            cout << "Yes\n";
        else
            cout << "No\n";
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
   int t = 1;
   while (t--) {
     solve(); 
   }
   auto end = std::chrono::high_resolution_clock::now();
   auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
   cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
   return 0;
}
