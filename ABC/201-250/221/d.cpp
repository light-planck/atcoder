#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<pair<int, int>> p;
  rep(i, n) {
    int a, b;
    cin >> a >> b;

    p.push_back(make_pair(a, 1));
    p.push_back(make_pair(a + b, -1));
  }
  sort(all(p));

  ll cnt = 0;
  vector<ll> ans(n + 1);
  rep(i, p.size() - 1) {
    cnt += p[i].second;
    ll period = p[i + 1].first - p[i].first;
    ans[cnt] += period;
  }

  for (int i = 1; i <= n; ++i) cout << ans[i] << endl;
  return 0;
}