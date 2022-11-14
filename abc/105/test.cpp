#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


string to_base_n(ll x, ll n) {
  string res = "";
  while (x != 0) {
    ll r = x % n;
    if (r < 0) r += abs(n);
    res += r + '0';
    x -= r;
    x /= n;
  }
  reverse(res.begin(), res.end());
  return res;
}


int main() {
  ll x;
  cin >> x;

  string ans = to_base_n(x, 2);
  ll padding = 10 - ans.size();
  ans = string(padding, '0') + ans;
  cout << ans << '\n';
  return 0;
}