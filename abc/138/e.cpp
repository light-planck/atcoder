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

  map<char, vector<ll>> pos;
  ll n = s.size();
  rep(i, n) pos[s[i]].emplace_back(i);

  ll now = 0;
  ll ans = 0;
  for (char c : t) {
    if (pos[c].size() == 0) {
      cout << -1 << "\n";
      return 0;
    }

    auto itr = lower_bound(rng(pos[c]), now);
    if (itr == pos[c].end()) {
      ans += n;
      now = pos[c][0] + 1;
    }
    else {
      now = *itr + 1;
    }
  }

  cout << ans+now << "\n";
  return 0;
}