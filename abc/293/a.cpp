#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll n = s.size();
  for (ll i = 1; i <= n/2; ++i) {
    ll l = 2*i - 1;
    ll r = 2*i;
    --l; --r;
    swap(s[l], s[r]);
  }

  cout << s << '\n';
  return 0;
}