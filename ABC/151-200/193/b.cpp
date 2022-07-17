#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  int ans = inf;
  rep(i, n){
    int a, p, x;
    cin >> a >> p >> x;
    if (x - a >= 1) ans = min(ans, p);
  }
  if (ans == inf) ans = -1;
  cout << ans << endl;
}