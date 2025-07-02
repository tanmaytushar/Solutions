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
we realise that r[j] = q[p[j]]; for product of p * q 
looking at what it does -> we realise we need to look for a permutation q where the numbers are permuated in according to the prefix of p 
Ex : p : 3 2 4 1 -> then we are looking for something like ->  4 2 1 3 -> inverse of p 
this lets us solve this question by putting every prefix in a set and for each i from 0 -> n check if we a prefix in set that is equal to prefix of current p 
*/







void solve(){
  int n,m;cin >> n >> m;
  vector<vector<int>> a(n,vector<int>(m));
  for(auto &it : a) for(auto &i : it) cin >> i,i--;
  vector<int> ans(n,0);
  set<vector<int>> s1;
  for(int i = 0;i<n;i++){
    vector<int> temp(m),temp2;
    for(int j = 0;j<m;j++){
      temp[a[i][j]] = j;
    }
    debug(temp);
    for(int j = 0;j<m;j++){
      temp2.push_back(temp[j]);
      s1.insert(temp2);
    }
  }
  for(int i = 0;i<n;i++){
    int count = 0;
    vector<int> temp;
    for(int j = 0;j<m;j++){
      temp.push_back(a[i][j]);
      if(s1.find(temp) != s1.end()) count++;
      else break;
    }
    ans[i] = count;
  }
  for(int x : ans) cout << x << " ";
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
