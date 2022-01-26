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
  bool ans = false;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        int x1 = p[i].first; int y1 = p[i].second;
        int x2 = p[j].first; int y2 = p[j].second;
        int x = p[k].first; int y = p[k].second;
        if (x1 == x2 && x2 == x) {
          ans = true;
        }
        else if (y1 == y2 && y2 == y) {
          ans = true;
        }
        else {
          if ((x2 - x1) * y == (y2 - y1) * (x - x1) + (x2 - x1) * y1) {
            ans = true;
          }
        }
      }
    }
  }

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}