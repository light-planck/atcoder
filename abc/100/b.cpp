#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll d, n;
  cin >> d >> n;

  ll cnt = 0;
  ll ans = 0;
  while (cnt < n) {
    auto count = [](ll x) {
      ll res = 0;
      while (x%100 == 0) {
        ++res;
        x /= 100;
      }

      if (x) return 0ll;
      else return res;
    };

    if (count(ans) == d) ++cnt;
    ++ans;
  }

  cout << ans << '\n';
  return 0;
}

accumulate