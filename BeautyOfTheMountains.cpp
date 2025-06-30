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
The idea is for every k * k matrix we can calualte the differnce between snowy and nonSnowy mountains sum a prefix sum
D is totalSumSnowy - totalSumNonSnowy, c1,c2,c3 ... are constants we add  
The equation then becomes -> (c1 * d1) + (c2 * d2) + (c3 * d3) + .... = D
This is similar to ax + by + cz .... = D 
This is called a Diophantine Equation it has an integer solution iff 
D % gcd(d1,d2,d3....) = 0
*/


 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m)), prefix(n, vector<int>(m, 0));
    vector<string> mo(n);
    for (auto &it : a)
        for (auto &x : it) cin >> x;
    for (auto &s : mo) cin >> s;
    long long snowy = 0, nonSnowy = 0;
    vector<vector<int>> binary(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (mo[i][j] == '0') snowy += a[i][j];
            else nonSnowy += a[i][j];
            binary[i][j] = (mo[i][j] == '1' ? 1 : 0);
        }
    vector<vector<int>> p(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            p[i][j] = binary[i][j];
            if (i > 0) p[i][j] += p[i - 1][j];
            if (j > 0) p[i][j] += p[i][j - 1];
            if (i > 0 && j > 0) p[i][j] -= p[i - 1][j - 1];
        }
    int g = 0; 
    for (int i = k - 1; i < n; ++i) {
        for (int j = k - 1; j < m; ++j) {
            int r1 = i - k + 1, c1 = j - k + 1;
            int total = k * k;
            int ones = p[i][j];
            if (r1 > 0) ones -= p[r1 - 1][j];
            if (c1 > 0) ones -= p[i][c1 - 1];
            if (r1 > 0 && c1 > 0) ones += p[r1 - 1][c1 - 1];
            int zeroes = total - ones;
            int delta = ones - zeroes;
            g = __gcd(g, abs(delta));
        }
    }
    int diff = snowy - nonSnowy;
    if (diff == 0 || (g != 0 && diff % g == 0))
        cout << "Yes\n";
    else
        cout << "No\n";
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
