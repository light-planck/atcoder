#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using Graph = vector<vector<int>>;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  Graph taka(n, vector<int>(n));
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    taka[a][b] = 1;
    taka[b][a] = 1;
  }

  Graph aoki(n, vector<int>(n));
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    aoki[a][b] = 1;
    aoki[b][a] = 1;
  }

  vector<int> p(n);
  rep(i, n) p[i] = i;

  do {
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (taka[i][j] != aoki[p[i]][p[j]]) {
          ok = false;
        }
      }
    }

    if (ok) {
      cout << "Yes\n";
      return 0;
    }
  } while (next_permutation(all(p)));

  cout << "No\n";
  return 0;
}