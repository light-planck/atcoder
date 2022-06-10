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
  vector<pair<int, int>> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  sort(all(p));
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int x1 = p[i].first; int y1 = p[i].second;
      int x2 = p[j].first; int y2 = p[j].second;
      if (x1 >= x2 || y1 >= y2) continue;
      bool ok = binary_search(all(p), make_pair(x1, y2))
      && binary_search(all(p), make_pair(x2, y1));
      if (ok) cnt++;
    }
  }

  cout << cnt << endl;
  return 0;
}

/*
長方形の一つの対角線上の2頂点を決定すれば、他の頂点の座標が定まる。
ここで、その2頂点を左下と右上の頂点としそれらを
(x1, y1), (x2, y2)とすると、x1 < x2 && y1 < y2が条件となる。
これを満たす2点を全探索する。
そして長方形をなすその他の2頂点の座標は
(x1, y2), (x2, y1)であり、これを二分探索する。
*/