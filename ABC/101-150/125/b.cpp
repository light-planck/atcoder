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
  vector<int> v(n), c(n);
  rep(i, n) cin >> v[i];
  rep(i, n) cin >> c[i];
  int ans = 0;
  rep(i, n) {
    int x = v[i] - c[i];
    if (x > 0) ans += x;
  }
  cout << ans << endl;
  return 0;
}