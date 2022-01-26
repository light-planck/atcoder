#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  int mn = inf;
  int ans = 0;

  rep(i, h)rep(j, w){
    cin >> a[i][j];
    mn = min(mn, a[i][j]);
  }

  rep(i, h)rep(j, w){
    if (a[i][j] > mn) ans += a[i][j] - mn;
  }

  cout << ans << endl;
}