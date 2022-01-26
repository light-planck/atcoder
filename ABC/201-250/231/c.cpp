#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));

  vector<int> x(q);
  rep(i, q) cin >> x[i];

  rep(i, q) {
    int cnt = n - (lower_bound(all(a), x[i]) - a.begin());
    cout << cnt << endl;
  }
  return 0;
}