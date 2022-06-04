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

  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  if (k == 1) {
    cout << "Yes" << "\n";
    return 0;
  }

  auto b = a;
  sort(rng(b));

  rep(i, n) {
    if (a[i] == b[i]) continue;

    bool ok = false;
    for (ll j = i + k; j < n; j += k) {
      if (a[j] == b[i]) {
        swap(a[i], a[j]);
        ok = true;
        break;
      }
    }

    // for (auto x : a) cout << x << " ";
    // cout << endl;

    if (ok) continue;

    cout << "No" << "\n";
    return 0;
  }

  cout << "Yes" << "\n";
  return 0;
}