#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int v, t, s, d;
  cin >> v >> t >> s >> d;

  if (v * t <= d && d <= v * s) cout << "No" << endl;
  else cout << "Yes" << endl;
}