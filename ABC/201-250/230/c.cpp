#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// (a, b)を中心としてXとなるようにマス目が黒く塗られる。
// 定数kに対し、(a + k, b + k)、(a + k, b - k)のマスは黒に塗られるが、
// 行と列に対して、加算または減算すると定数kが消せる。
// 前者は(a + k) - (b + k) = a - b、後者は(a + k) + (b - k) = a + b
// となり、そのどちらかを満たすマスが黒に塗られる。

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  a--; b--;
  ll p, q, r, s;
  cin >> p >> q >> r >> s;
  ll h = q - p + 1;
  ll w = s - r + 1;
  vector<string> grid(h, string(w, '.'));
  rep(i, h) rep(j, w) {
    ll x = p + i - 1;
    ll y = r + j - 1;
    if ((x + y == a + b) || (x - y == a - b)) grid[i][j] = '#';
  }
  for (auto g : grid) {
    cout << g << endl;
  }
  return 0;
}