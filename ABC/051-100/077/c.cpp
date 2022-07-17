#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];
  sort(all(a));
  sort(all(c));
  ll ans = 0;

  rep(i, n) {
    ll numa = lower_bound(all(a), b[i]) - a.begin();
    ll numc = n - (upper_bound(all(c), b[i]) - c.begin());
    ans += numa * numc;
  }

  cout << ans << endl;
  return 0;
}