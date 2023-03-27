#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


double avg(vector<ll>& a) {
  ll n = a.size();
  if (n%2 == 1) return a[n/2];
  else return (a[n/2]+a[n/2 - 1]) / 2.0;
}


int main() {
  ll n;
  cin >> n;

  vector a(n, 0ll), b(n, 0ll);
  rep(i, n) cin >> a[i] >> b[i];

  auto c = a;
  sort(c.begin(), c.end());
  double m = avg(c);

  auto d = b;
  sort(d.begin(), d.end());
  double M = avg(d);

  ll ans = 0;
  if (n%2 == 0) ans = ((M-m) / 0.5) + 1;
  else ans = M - m + 1;
  cout << ans << '\n';
  return 0;
}