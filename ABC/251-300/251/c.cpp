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
#include <string>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
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

  ll n;
  cin >> n;

  // <t, idx>
  vector<pair<ll, ll>> t_idx;
  map<string, ll> cnt;
  rep(i, n) {
    string s;
    ll t;
    cin >> s >> t;

    if (!cnt.count(s)) {
      t_idx.emplace_back(t, -1 * i);
      ++cnt[s];
    }
  }

  sort(t_idx.rbegin(), t_idx.rend());
  // for (auto [x, y] : t_idx) {
  //   cout << x << " " << y << "\n";
  // }
  cout << -1 * t_idx[0].second + 1 << "\n";
  return 0;
}