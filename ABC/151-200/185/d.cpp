#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(m);
  rep(i, m) {
    cin >> a[i];
    a[i]--;
  }
  sort(all(a));
  a.push_back(n);

  // 青マス間の長さ
  vector<int> l;
  int cur = 0;
  rep(i, m + 1) {
    int d = max(0, a[i] - cur);
    if (d > 0) l.push_back(d);
    cur = a[i] + 1;
  }

  // 最小区間
  int mn = 1e9;
  for (auto x : l) {
    mn = min(mn, x);
  }

  int ans = 0;
  for (auto x : l) {
    ans += (x + mn - 1) / mn;
  }

  cout << ans << endl;
  return 0;
}