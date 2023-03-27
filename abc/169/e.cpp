#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


double avg(vector<ll>& a) {
  sort(a.begin(), a.end());
  ll n = a.size();
  if (n%2 == 1) return a[n/2];
  else return (a[n/2]+a[n/2 - 1]) / 2.0;
}


int main() {
  ll n;
  cin >> n;

  vector a(n, 0ll), b(n, 0ll);
  rep(i, n) cin >> a[i] >> b[i];

  double m = avg(a);
  double M = avg(b);

  ll ans = 0;
  if (n%2 == 0) ans = ((M-m) / 0.5) + 1;
  else ans = M - m + 1;
  
  cout << ans << '\n';
  return 0;
}