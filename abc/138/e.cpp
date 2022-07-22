#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define rng(a) (a).begin(),(a).end()
#define rrng(a) (a).rbegin(),(a).rend()
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  string t;
  cin >> t;

  ll n = s.size();
  map<char, set<ll>> pos;
  rep(i, n) {
    pos[s[i]].insert(i);
    pos[s[i]].insert(i + n);
  }

  ll ans = 0;
  ll now = 0;

  for (auto c : t) {
    if (pos[c].size() == 0) {
      cout << -1 << "\n";
      return 0;
    }

    now = *pos[c].lower_bound(now) + 1;
    if (now >= n) {
      ans += n;
      now -= n;
    }
  }

  cout << ans+now << "\n";
  return 0;
}