#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  int sum = 0;
  int cnt = 0;
  bool can = false;
  rep(i, n){
    cin >> a[i];
    sum += a[i];
  }

  rep(i, n) if (4 * m * a[i] >= sum) cnt++;
  if (cnt >= m) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}