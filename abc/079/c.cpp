#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll n = 4;
  for (ll bit = 0; bit < (1<<(n-1)); ++bit) {
    vector<ll> a(n);
    rep(i, n) a[i] = s[i] - '0';

    ll sum = a[0];
    rep(i, n-1) {
      if ((bit>>i) & 1) sum += a[i+1];
      else sum -= a[i+1];
    }

    vector<char> op(n-1);
    if (sum == 7) {
      rep(i, n-1) {
        if ((bit>>i) & 1) op[i] = '+';
        else op[i] = '-';
      }

      cout << a[0];
      rep(i, n-1) cout << op[i] << a[i+1];
      cout << "=7" << '\n';
      return 0;
    }
  }
  return 0;
}