#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  int rmin = 1e9;
  int lmax = 0;

  rep(i, m) {
    int l, r;
    cin >> l >> r;
    if (lmax < l) lmax = l;
    if (rmin > r) rmin = r;
  }

  if (rmin - lmax >= 0) cout << rmin - lmax + 1 << endl;
  else cout << 0 << endl;
  return 0;
}