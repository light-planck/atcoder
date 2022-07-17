#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int a, b, w;
  cin >> a >> b >> w;
  w *= 1000;
  int n = 1e6;
  int mn = inf;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    if (a * i <= w && w <= b * i) {
      mn = min(mn, i);
      mx = max(mx, i);
    }
  }
  if (mn == inf && mx == 0) cout << "UNSATISFIABLE" << endl;
  else {
    cout << mn << endl;
    cout << mx << endl;
  }
  return 0;
}