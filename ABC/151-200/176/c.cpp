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
  ll ans = 0;
  int mx = a[0];
  rep(i, n) {
    if (i == 0) continue;
    if (mx > a[i]) {
      ans += (mx - a[i]);
    }
    else mx = a[i];
  }
  cout << ans << endl;
  return 0;
}