#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<pair<ll, ll>> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  sort(all(p));

  for (int i = 0; i < n; i++) {
    if (k < p[i].first) break;
    k += p[i].second;
  }

  cout << k << endl;
  return 0;
}