#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> s(n);
  rep(i, n) cin >> s[i];

  ll sum = s[0];
  vector<ll> a(n);
  a[0] = s[0];
  rep(i, n-1) {
    a[i+1] = s[i+1] - sum;
    sum += a[i+1];
  }

  for (auto x : a) cout << x << '\n';
  return 0;
}