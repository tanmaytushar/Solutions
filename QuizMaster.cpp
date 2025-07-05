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








const int MAXM = 1e5;
vector<int> factors[MAXM + 5];
void init() {
  for (int i = 1; i <= MAXM; i++) {
    for (int j = i; j <= MAXM; j += i) {
      factors[j].push_back(i);
    }
  }
}





/*
We sort the smartness values and use two pointers to find the smallest team that is collectively proficient in all m topics. 
A team is proficient if, for every topic T from 1 to m, at least one student has smartness divisible by T. 
We maintain a frequency array f to count how many students cover each topic and a counter count to track 
how many topics are currently covered. As we expand the window with the right pointer, we add students 
and update f and count using their factors ≤ m. When count == m, we try to shrink the window from 
the left to minimize the smartness difference a[r] - a[l]. We keep track of the minimum such difference across all valid windows.
*/






void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &it : a) cin >> it;
  sort(a.begin(), a.end());
  vector<int> f(m + 1, 0);
  int left = 0, count = 0;
  int ans = INT_MAX;
  for (int right = 0; right < n; ++right) {
    for (int fac : factors[a[right]]) {
      if (fac > m) break;
      if (f[fac] == 0) count++;
      f[fac]++;
    }
    while (count == m) {
      ans = min(ans, a[right] - a[left]);
      for (int fac : factors[a[left]]) {
        if (fac > m) break;
        f[fac]--;
        if (f[fac] == 0) count--;
      }
      left++;
    }
  }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
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
    init();
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
