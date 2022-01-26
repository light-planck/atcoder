#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  ll cnt = 0;
  sort(h.rbegin(), h.rend());
  for (int i = 0; i < n; i++) {
    if (k > 0) k--;
    else cnt += h[i];
  }
  cout << cnt << endl;
  return 0;
}