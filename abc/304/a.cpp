#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  vector<string> s(n);
  vector<ll> a(n);
  rep(i, n) cin >> s[i] >> a[i];

  ll min_age = 1ll << 60;
  ll start = 0;
  rep(i, n) {
    if (min_age > a[i]) {
      min_age = a[i];
      start = i;
    }
  }

  ll i = start;
  while (i != start + n) {
    cout << s[i % n] << '\n';
    ++i;
  }
  return 0;
}
