#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n = 3;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());

  ll ans = 1e9;
  auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
  do {
    chmin(ans, abs(a[0]-a[1]) + abs(a[1]-a[2]));
  } while (next_permutation(a.begin(), a.end()));

  cout << ans << '\n';
  return 0;
}