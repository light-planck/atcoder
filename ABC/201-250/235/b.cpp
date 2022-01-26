#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];

  int max_h = h[0];
  
  for (int i = 1; i < n; ++i) {
    if (max_h < h[i]) max_h = h[i];
    else {
      cout << max_h << "\n";
      return 0;
    }
  }

  cout << h[n - 1] << "\n";
  return 0;
}