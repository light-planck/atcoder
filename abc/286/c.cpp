#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  string s;
  cin >> s;

  ll ans = 1ll << 60;
  rep(i, n) {
    ll cost = i*a;
    ll left = 0; ll right = n-1;
    while (left < right) {
      if (s[left] != s[right]) cost += b;
      ++left; --right;
    }

    ans = min(ans, cost);
    s = s.substr(1) + s[0];
  }

  cout << ans << '\n';
  return 0;
}