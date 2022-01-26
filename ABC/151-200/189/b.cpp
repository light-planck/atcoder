#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n, x;
  cin >> n >> x;
  x *= 100;
  int all = 0;
  int cnt = 0;
  bool ans = false;

  rep(i, n){
    int v, p;
    cin >> v >> p;
    all += v * p;
    if (all > x){
      ans = true;
      cnt = i;
      break;
    }
  }

  if (ans) cout << cnt + 1 << endl;
  else cout << -1 << endl;
}