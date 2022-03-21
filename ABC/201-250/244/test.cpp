#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using namespace atcoder;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  dsu d(n);
  while (q--) {
    int t, u, v;
    cin >> t >> u >> v;

    if (t == 0) {
      d.merge(u, v);
    }
    else {
      if (d.same(u, v)) cout << 1 << "\n";
      else cout << 0 << "\n";
    }
  }
  return 0;
}