#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  rep(i, n) cin >> x[i] >> y[i];
  set<pair<int, int>> st;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int a = x[i] - x[j];
      int b = y[i] - y[j];
      int g = __gcd(a, b);
      a /= g;
      b /= g;
      st.insert(make_pair(a, b));
    }
  }

  cout << st.size() * 2 << "\n";
  return 0;
}