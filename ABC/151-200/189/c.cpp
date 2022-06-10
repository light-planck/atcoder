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
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int ans = 0;

  // l, rを全探索
  // 1つだけ選んでもいい(l <= r)
  // 選ぶ個数はmin(a[l], a[l+1], ..., a[r])
  for (int l = 0; l < n; l++) {
    int x = a[l];
    for (int r = l; r < n; r++) {
      x = min(x, a[r]);
      ans = max(ans, x * (r - l + 1));
    }
  }

  cout << ans << endl;
  return 0;
}