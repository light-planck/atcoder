#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  int cnt = 0;

  for (int i = 0; i < n - 1; i++){
    for (int j = i + 1; j < n; j++){
      if (abs(y[j] - y[i]) <= abs(x[j] - x[i])) cnt++;
    }
  }

  cout << cnt << endl;
}