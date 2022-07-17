#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath> // abs, sqrt, cos, ...
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<string> s(n), t(n);
  map<string, ll> mp;
  rep(i, n) {
    cin >> s[i] >> t[i];

    if (s[i] == t[i]) ++mp[s[i]];
    else {
      ++mp[s[i]];
      ++mp[t[i]];
    }
  }

  for (int i = 0; i < n; ++i) {
    // bool exist_s = false;
    // bool exist_t = false;


    // for (int j = i + 1; j < n; ++j) {
    //   if (s[i] == s[j] || s[i] == t[j]) exist_s = true;
    //   if (t[i] == s[j] || t[i] == t[j]) exist_t = true;
    // }

    // if (exist_s && exist_t) {
    //   cout << "No" << "\n";
    //   return 0;
    // }

    if (mp[s[i]] > 1 && mp[t[i]] > 1) {
      cout << "No" << "\n";
      return 0;
    }
  }

  cout << "Yes" << "\n";
  return 0;
}