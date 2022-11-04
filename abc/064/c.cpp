#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  ll m = 8;
  vector<bool> color(m, false);
  ll god = 0;

  auto check = [&](ll rate) {
    if (rate < 3200) {
      rep(i, m) {
        if (400*i <= rate and rate < 400*(i+1)) {
          color[i] = true;
          break;
        }
      }
    }
    else ++god;
  };

  rep(i, n) {
    ll a;
    cin >> a;
    check(a);
  }

  ll cnt = 0;
  for (auto c : color) if (c) ++cnt;

  if (cnt == 0) cout << 1 << '\n';
  else cout << cnt << '\n';

  cout << cnt+god << '\n';
  return 0;
}