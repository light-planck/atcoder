#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int k, a, b;
  cin >> k >> a >> b;
  bool can = false;
  for (int i = a; i <= b; i++) if (i % k == 0) can = true;
  if (can) cout << "OK" << endl;
  else cout << "NG" << endl;
}