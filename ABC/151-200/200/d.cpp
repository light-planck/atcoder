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

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll m = min(8, (int)a.size());
  map<ll, vector<vector<ll>>> mp;

  for (ll bit = 1; bit < (1 << m); ++bit) {
    vector<ll> idx;
    ll sum = 0;

    for (ll i = 0; i < m; ++i) {
      if ((bit >> i) & 1) {
        sum += a[i];
        idx.emplace_back(i + 1);
      }
    }

    sum %= 200;
    mp[sum].emplace_back(idx);
  }

  for (auto [r, idx] : mp) {
    if (idx.size() >= 2) {
      cout << "Yes" << "\n";

      rep(j, 2) {
        cout << idx[j].size() << " ";

        for (auto i : idx[j]) {
          cout << i << " ";
        }
        cout << "\n";
      }

      return 0;
    }
  }

  cout << "No" << "\n";
  return 0;
}