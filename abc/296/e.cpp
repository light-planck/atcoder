#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/scc>
using namespace atcoder;


int main() {
  ll n;
  cin >> n;

  scc_graph graph(n);
  ll ans = 0;

  rep(i, n) {
    ll a;
    cin >> a;
    --a;
    graph.add_edge(i, a);
    if (i == a) ++ans;
  }

  auto scc = graph.scc();
  for (auto v : scc) {
    if (v.size() >= 2) ans += v.size();
  }

  cout << ans << '\n';
  return 0;
}