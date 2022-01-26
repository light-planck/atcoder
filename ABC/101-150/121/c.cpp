#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  sort(all(p));

  ll sum = 0;
  rep(i, n) {
    ll a = p[i].first;
    ll b = p[i].second;
    if (m >= b) {
      m -= b;
      sum += a * b;
    }
    else {
      sum += a * m;
      break;
    }
  }

  cout << sum << endl;
  return 0;
}