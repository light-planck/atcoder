#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll x;
  cin >> x;

  ll ans = x / 11;
  ll sum = 11 * ans;
  ans *= 2;

  if (sum < x) {
    sum += 6;
    ++ans;
  }
  if (sum < x) ++ans;

  cout << ans << '\n';
  return 0;
}