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
Three observation 
1st -> The parity of all the elements that are achievable at a cell are same 
2nd -> we cannot have a sum = 0 if (n+m-1) is odd i.e the path len
3rd -> we can achieve any element from max to min of same parity 
Proof:
Let’s say you have two paths: p1 (min sum) and p2 (max sum).
Since they have the same number of steps, you can turn p1 into p2 by swapping adjacent directions (like turning a "DR" into "RD"), i.e., tweaking the path slightly.
Each such tweak replaces one grid cell with another adjacent one — the sum can change by ±2 or 0.
Hence, from min_sum to max_sum, every value with the same parity can be hit during such tweaks — especially 0, if it lies in between.
*/





void solve(){
  int n,m;cin >> n >> m;
  vector<vector<int>> a(n,vector<int>(m)),mn(n,vector<int>(m)),mx(n,vector<int>(m));
  for(auto &it : a) for(auto &i : it) cin >> i;
  if((n + m - 1) % 2){
    cout << "No" << endl;
    return;
  }
  mn[0][0] = mx[0][0] = a[0][0];

  for(int i = 1; i < n; ++i)
    mx[i][0] = mn[i][0] = mx[i - 1][0] + a[i][0];

  for(int j = 1; j < m; ++j)
    mx[0][j] = mn[0][j] = mx[0][j - 1] + a[0][j];

  for(int i = 1; i < n; ++i){
    for(int j = 1; j < m; ++j){
      mx[i][j] = max(mx[i - 1][j], mx[i][j - 1]) + a[i][j];
      mn[i][j] = min(mn[i - 1][j], mn[i][j - 1]) + a[i][j];
    }
  }
  if(mx[n-1][m-1] < 0 || mn[n-1][m-1] > 0){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
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
