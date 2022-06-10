#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

vector<ll> calpfact(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i != 0) continue;
    res.push_back(i);
    if (n / i != i) res.push_back(n / i);
  }
  sort(all(res));
  return res;
}

int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  vector<ll> pfact = calpfact(n);
  ll len = pfact.size();
  if (len % 2 == 1) ans = 2 * (pfact[len / 2] - 1);
  else ans = (pfact[len / 2 - 1] - 1) + (pfact[len / 2] - 1);
  cout << ans << endl;
  return 0;
}