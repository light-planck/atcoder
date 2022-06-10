#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> y(n), x(n);
  rep(i, n) cin >> y[i] >> x[i];
  vector<int> xx = x, yy = y;
  sort(all(xx));
  sort(all(yy));
  xx.erase(unique(all(xx)), xx.end());
  yy.erase(unique(all(yy)), yy.end());
  rep(i, n) {
    x[i] = lower_bound(all(xx), x[i]) - xx.begin();
    y[i] = lower_bound(all(yy), y[i]) - yy.begin();
  }
  rep(i, n) {
    cout << y[i] + 1 << " " << x[i] + 1 << endl;
  }
  return 0;
}