#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b;
  cin >> a >> b;

  ll ans = 0;
  for (ll i = a; i <= b; ++i) {
    string s = to_string(i);
    ll n = s.size();
    ll left = 0; ll right = n-1;
    while (s[left] == s[right]) {
      ++left, --right;
    }

    if (left >= right) ++ans;
  }

  cout << ans << '\n';
  return 0;
}