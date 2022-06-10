#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n, w;
  cin >> n >> w;
  vector<pair<ll, ll>> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  sort(p.rbegin(), p.rend());
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    if (p[i].second <= w) {
      sum += p[i].first * p[i].second;
      w -= p[i].second;
    }
    else {
      sum += p[i].first * w;
      w = 0;
      break;
    }
  }
  cout << sum << endl;
  return 0;
}