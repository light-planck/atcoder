#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  double d, t, s;
  cin >> d >> t >> s;
  bool can = false;
  if (d / s <= t) can = true;
  puts(can ? "Yes" : "No");
}