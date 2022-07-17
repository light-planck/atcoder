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

  auto compress = [](string str) -> vector<pair<char, ll>> {
    vector<pair<char, ll>> res;

    for (auto c : str) {
      if (res.size() > 0) {
        auto& [prev, cnt] = res.back();
        if (c == prev) ++cnt;
        else res.emplace_back(c, 1);
      }
      else res.emplace_back(c, 1);
    }

    return res;
  };

  auto s1 = compress(s);
  auto t1 = compress(t);

  ll n = s1.size();
  ll m = t1.size();

  if (n != m) {
    cout << "No" << "\n";
    return 0;
  }

  rep(i, n) {
    auto [c1, cnt1] = s1[i];
    auto [c2, cnt2] = t1[i];

    bool ng = false;
    if (c1 != c2) ng = true;
    if (cnt1 > cnt2) ng = true;
    if (cnt1 == 1 and cnt2 >= 2) ng = true;

    if (ng) {
      cout << "No" << "\n";
      return 0;
    }
  }

  cout << "Yes" << "\n";
  return 0;
}