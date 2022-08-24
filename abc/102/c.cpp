#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#define rng(a) (a).begin(),(a).end()


int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> b(n);
  rep(i, n) b[i] = a[i] - (i+1);

  ll med = 0;
  sort(rng(b));
  med = b[n / 2];

  ll ans = 0;
  rep(i, n) ans += abs(b[i] - med);
  cout << ans << '\n';
  return 0;
}