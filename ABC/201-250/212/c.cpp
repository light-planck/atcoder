#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  sort(all(a));
  sort(all(b));
  int ans = inf;

  rep(i, n) {
    int j = lower_bound(all(b), a[i]) - b.begin();
    if (j < m) ans = min(ans, abs(a[i] - b[j]));
    else ans = min(ans, abs(a[i] - b[m-1]));
    if (j >= 1) ans = min(ans, abs(a[i] - b[j-1]));
  }

  cout << ans << endl;
  return 0;
}