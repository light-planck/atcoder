#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n, m, t;
  cin >> n >> m >> t;
  bool can = true;
  int last = 0;
  int bat = n;

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    bat -= a-last;
    if (bat > 0) bat += b-a;
    else can = false;
    if (bat >= n) bat = n;
    last = b;
  }

  bat -= t-last;
  if (bat <= 0) can = false;

  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}