#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int fac(int x) {
  int ans = 1;
  while (x > 0) {
    ans *= x;
    x--;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> xy(n);
  rep(i, n) cin >> xy[i].first >> xy[i].second;
  sort(all(xy));
  double sum = 0;

  //町1, 2, ... nの距離を求める
  //(1, 2), (2, 3), ... , (n-1, n)
  do {
    for (int i = 0; i < n - 1; i++) {
      double l = (xy[i].first - xy[i+1].first) * (xy[i].first - xy[i+1].first)
      + (xy[i].second - xy[i+1].second) * (xy[i].second - xy[i+1].second);
      l = sqrt(l);
      sum += l;
    }
  } while(next_permutation(all(xy)));

  double ans = sum / fac(n);
  printf("%.7f\n", ans);
  return 0;
}