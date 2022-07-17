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
  vector<int> s(n), t(n);
  rep(i, n) cin >> s[i];
  rep(i, n) cin >> t[i];
  vector<int> a(n);
  a[0] = t[0];

  for (int i = 0; i < 2 * n; i++) {
    a[i % n] = min(t[i % n], a[(i+n-1) % n] + s[(i+n-1) % n]);
  }
  rep(i, n) cout << a[i] << endl;
  return 0;
}