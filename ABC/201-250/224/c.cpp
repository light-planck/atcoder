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
  vector<pair<ll, ll>> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        // a = pj - pi
        // b = pk - pi
        pair<ll, ll> a, b;
        a = make_pair(p[j].first - p[i].first, p[j].second - p[i].second);
        b = make_pair(p[k].first - p[i].first, p[k].second - p[i].second);
        ll dot = (a.first * b.first + a.second * b.second) * (a.first * b.first + a.second * b.second);
        ll lena = a.first * a.first + a.second * a.second;
        ll lenb = b.first * b.first + b.second * b.second;
        if (dot != lena * lenb) cnt++;
      }
    }
  }

  cout << cnt << endl;
  return 0;
}