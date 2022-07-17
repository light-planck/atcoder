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

  ll n, w;
  cin >> n >> w;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  set<ll> st;
  for (ll i = 0; i < n; ++i) {
    ll tmp;
    if (a[i] <= w) {
      tmp = a[i];
      st.insert(tmp);
    }

    for (ll j = i + 1; j < n; ++j) {
      if (a[j] <= w) {
        tmp = a[j];
        st.insert(tmp);
      }

      if (a[i] + a[j] <= w) {
        tmp = a[i] + a[j];
        st.insert(tmp);
      }

      for (ll k = j + 1; k < n; ++k) {
        if (a[k] <= w) {
          tmp = a[k];
          st.insert(tmp);
        }

        if (a[i] + a[k] <= w) {
          tmp = a[i] + a[k];
          st.insert(tmp);
        }
        if (a[j] + a[k] <= w) {
          tmp = a[j] + a[k];
          st.insert(tmp);
        }

        if (a[i] + a[j] + a[k] <= w) {
          tmp = a[i] + a[j] + a[k];
          st.insert(tmp);
        }
      }
    }
  }

  cout << st.size() << "\n";
  return 0;
}