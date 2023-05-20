#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;


int main() {
  ll n;
  cin >> n;

  map<ll, mint> memo;

  auto dfs = [&](auto self, ll i) -> void {
    if (memo.count(i)) return memo[i];

    mint res = 0;
    for (ll j = 2; j <= 6; ++j) {
      res += memo[j];
    }

    return memo[i] = res;
  }
  dfs();

  cout << memo[n].val() << '\n';
  return 0;
}