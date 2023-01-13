#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/modint>
using namespace atcoder;


int main() {
  ll n;
  cin >> n;

  using mint = modint1000000007;
  mint ans = 1;
  rep(i, n) ans *= i + 1;

  cout << ans.val() << '\n';
  return 0;
}