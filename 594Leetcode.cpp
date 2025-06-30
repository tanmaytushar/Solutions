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









class SparseTable {
    vector<vector<int>> stMin, stMax;
    vector<int> log;
    int n;
public:
    SparseTable(const vector<int>& arr) {
        n = arr.size();
        int K = log2(n) + 1;

        stMin.assign(n, vector<int>(K));
        stMax.assign(n, vector<int>(K));
        log.assign(n + 1, 0);

        for (int i = 2; i <= n; ++i)
            log[i] = log[i / 2] + 1;

        for (int i = 0; i < n; ++i)
            stMin[i][0] = stMax[i][0] = arr[i];

        for (int j = 1; j < K; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
                stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int rangeMin(int l, int r) {
        int j = log[r - l + 1];
        return min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
    }

    int rangeMax(int l, int r) {
        int j = log[r - l + 1];
        return max(stMax[l][j], stMax[r - (1 << j) + 1][j]);
    }
};






void solve(){
  // jumping forwards to a smaller tree only makes sense if there is a bigger tree that he can jump to afterwards 
  // is it dp
  int n;cin >> n;
  vector<int> a(n);for(auto &it : a) cin >> it;
  SparseTable st(a);
  vector<int> dp(n);
  for(int i = n-1;i>=0;i--){
    int current = a[i];
    int left = st.rangeMax(0,i);
    int right = i+1 < n ? st.rangeMin(i+1,n-1) : INT_MAX;
    dp[i] = max(current,left);
    if(left > right) dp[i] = max(dp[i],dp[i+1]);
  }
  for(auto &it : dp) cout << it << " ";
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
