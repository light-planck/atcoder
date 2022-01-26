#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9 + 7;

int main() {
  int n, x;
  cin >> n >> x;
  int cnt = 1;
  int sum = 0;
  vector<int> l(n);
  rep(i, n) cin >> l[i];

  for (int i = 1; i <= n; i++) {
    sum += l[i-1];
    if (sum <= x) cnt++;
  }
  cout << cnt << endl;
  return 0;
}