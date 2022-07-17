#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int x, n;
  cin >> x >> n;
  set<int> p;
  rep(i, n) {
    int q;
    cin >> q;
    p.insert(q);
  }

  int dif = inf;
  int ans = inf;

  // 1 <= p <= 100より、答えは0 ~ 101
  for (int i = 0; i <= 101; i++) {
    if (p.count(i)) continue;
    if (dif > abs(x - i)) {
      dif = abs(x - i);
      ans = i;
    }
  }

  cout << ans << endl;
  return 0;
}