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
  ll n;
  cin >> n;

  string ans = to_base_n(n, -2);

  if (ans.empty()) ans = "0";
  cout << ans << '\n';
  return 0;
}