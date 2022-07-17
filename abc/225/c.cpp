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
  vector<vector<int>> b(n, vector<int>(m));
  rep(i, n)rep(j, m) cin >> b[i][j];

  bool ans = true;

  // よこ
  rep(i, n)rep(j, m - 1) {

    // b[i][j] % 7 == 0は存在するならば、bの右端でなければならない
    if ((b[i][j] % 7 == 0) && b[i][j] > 0) ans = false;
    if (b[i][j] + 1 != b[i][j + 1]) ans = false;
  }

  // たて
  rep(j, m)rep(i, n - 1) {
    if (b[i][j] + 7 != b[i + 1][j]) ans = false;
  }

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}