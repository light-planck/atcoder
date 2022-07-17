#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  string ans = "Yes";
  int mx = 0;
  rep(i, n) {
    if (h[i] >= mx) mx = max(h[i] - 1, mx);
    else ans = "No";
  }
  cout << ans << endl;
  return 0;
}