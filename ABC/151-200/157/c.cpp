#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> p(m);
  rep(i, m) cin >> p[i].first >> p[i].second;

  for (int i = 0; i <= 999; i++) {
    string str = to_string(i);
    if (str.size() != n) continue;
    bool ok = true;
    rep(j, m) {
      int s = p[j].first;
      s--;
      char c = p[j].second + '0';
      if (str[s] != c) ok = false;
    }
    if (ok) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}