#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n+1);
  rep(i, n+1) cin >> a[i];
  vector<int> b(n);
  rep(i, n) cin >> b[i];
  ll cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i; j <= i + 1; j++) {
      if (b[i] >= a[j]) {
        b[i] -= a[j];
        cnt += a[j];
        a[j] = 0;
      }
      else {
        a[j] -= b[i];
        cnt += b[i];
        b[i] = 0;
      }
    }
  }

  cout << cnt << endl;
  return 0;
}