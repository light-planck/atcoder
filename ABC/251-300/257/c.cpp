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
#include <unordered_map>
#include <unordered_set>
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

  ll n;
  cin >> n;

  string s;
  cin >> s;

  vector<ll> w(n);
  rep(i, n) cin >> w[i];

  map<ll, vector<ll>> mp;
  rep(i, n) mp[w[i]].emplace_back(i);

  ll now = 0;
  rep(i, n) if (s[i] == '1') ++now;

  ll ans = now;
  for (auto [_, idx] : mp) {
    for (auto i : idx) {
      if (s[i] == '0') ++now;
      else --now;
    }

    chmax(ans, now);
  }

  cout << ans << "\n";
  return 0;
}