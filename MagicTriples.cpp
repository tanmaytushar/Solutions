#include <bits/stdc++.h>
using namespace std;
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












const int MAX = 1e6 + 1;
vector<vector<int>> divisors(MAX);

void precomputeDivisors() {
    for (int i = 1; i < MAX; ++i) {
        for (int j = i * 2; j < MAX; j += i) {
            divisors[j].push_back(i);
        }
    }
}


/*
The idea is simple only but you need to optimise you code a little in terms of time and space 
Remove the #define int long long -> all of them now take 32 bits instead of 64 
Precompute all the divisors 
a = x , b = x*y , c = x*y*y 
For b now look for all its divisors then we can get c as -> (b*b)/a 
One of thing to take care of is -> for 777777, somethings like this add to ans nC3 * 6
*/

void solve() {
    int n;
    cin >> n;
    map<int, int> f;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f[x]++;
    }
    long long ans = 0;
    for (auto &[val, freq] : f) {
        if (freq >= 3) {
            long double comb = (long double)(freq) * (freq - 1) * (freq - 2) / 6.0;
            ans += (long long)(comb * 6.0);
        }
    }
    for (auto &[b, freq_b] : f) {
        for (int a : divisors[b]) {
            long long c = 1LL * b * b / a;
            if (c >= MAX) continue;
            if (f.count(a) && f.count(c)) {
                ans += 1LL * f[a] * f[c] * freq_b;
            }
        }
    }
    cout << ans << endl;
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
   precomputeDivisors();
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
