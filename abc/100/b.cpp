#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll d, n;
  cin >> d >> n;

  ll cnt = 0;
  ll ans = 1;
  while (true) {
    auto count = [](ll x) {
      ll res = 0;
      while (x%100 == 0) {
        ++res;
        x /= 100;
      }
      return res;
    };

    if (count(ans) == d) ++cnt;
    if (cnt >= n) break;

    ++ans;
  }

  cout << ans << '\n';
  return 0;
}