#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;

  // <b, a>
  vector<pair<int, int>> p(n);
  rep(i, n) {
    cin >> p[i].second >> p[i].first;
  }
  sort(all(p));
  ll now = 0;
  bool can = true;
  rep(i, n) {
    int a = p[i].second;
    int b = p[i].first;
    now += (ll)a;
    if (now > b) can = false;
  }
  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}