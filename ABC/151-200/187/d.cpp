#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// delta = taka - aokiとする。
// 町iで演説すると、delta = 2 * a[i] + b[i]増える。
// xを青木派とし、x + delta > 0になるまで繰り返す。

int main() {
  int n;
  cin >> n;
  vector<ll> d(n);
  ll x = 0;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    x -= a;
    d[i] = 2 * a + b;
  }
  sort(d.rbegin(), d.rend());
  int cnt = 0;
  rep(i, n) {
    if (x > 0) break;
    cnt++;
    x += d[i];
  }
  cout << cnt << endl;
  return 0;
}