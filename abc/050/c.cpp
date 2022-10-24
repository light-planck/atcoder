#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/modint>
using namespace atcoder;


int main() {
  ll n;
  cin >> n;

  map<ll, ll> cnt;
  rep(i, n) {
    ll a;
    cin >> a;
    ++cnt[a];
  }

  for (ll i = n-1; i >= 0; i -= 2) {
    if (i == 0) {
      if (cnt[i] != 1) {
        cout << 0 << '\n';
        return 0;
      }
    }
    else if (cnt[i] != 2) {
      cout << 0 << '\n';
      return 0;
    }
  }

  using mint = modint1000000007;
  mint ans = 2;
  ans = ans.pow(n/2);
  cout << ans.val() << '\n';
  return 0;
}