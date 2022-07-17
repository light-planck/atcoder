#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

ll n, x;
ll ans = 0;
vector<vector<ll>> a;

void dfs(int i, ll prod) {
  if (i == n) {
    if (prod == x) ans++;
    return;
  }

  for (auto y : a[i]) {
    if (prod * y > x) continue;
    dfs(i + 1, prod * y);
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> x;
  a.resize(n);
  rep(i, n) {
    int l;
    cin >> l;
    rep(j, l) {
      ll b;
      cin >> b;
      a[i].push_back(b);
    }
  }

  dfs(0, 1);
  cout << ans << "\n";
  return 0;
}