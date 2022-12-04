#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/modint>
using namespace atcoder;


int main() {
  ll n, p;
  cin >> n >> p;

  using mint = modint998244353;
  mint ans = 0;

  mint inv = ((mint)100).inv();
  map<ll, mint> memo;

  auto dfs = [&](auto dfs, ll i, mint prob, ll hp) -> mint {
    if (hp >= n) {
      return memo[hp] = prob * i * inv;
    }

    if (memo.count(hp+1)) ans += memo[hp+1];
    else dfs(dfs, i+1, prob*p*inv, hp+1);
    
    if (memo.count(hp+2)) ans += memo[hp+2];
    else dfs(dfs, i+1, prob*(1-p)*inv, hp+2);
  };
  dfs(dfs, 1, (mint)1, 0);

  cout << ans.val() << '\n';
  return 0;
}