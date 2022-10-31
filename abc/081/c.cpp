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


int main() {
  ll n, k;
  cin >> n >> k;

  map<ll, ll> memo;
  rep(i, n) {
    ll a;
    cin >> a;
    ++memo[a];
  }

  using P = pair<ll, ll>;
  vector<P> cnt;
  for (auto [a, c] : memo) {
    cnt.emplace_back(c, a);
  }
  sort(cnt.begin(), cnt.end());

  ll ans = 0;
  ll m = max<ll>(cnt.size()-k, 0);
  rep(i, m) {
    auto [c, a] = cnt[i];
    ans += c;
  }

  cout << ans << '\n';
  return 0;
}