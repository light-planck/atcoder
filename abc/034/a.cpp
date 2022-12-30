#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll x, y;
  cin >> x >> y;
  if (x < y) cout << "Better" << '\n';
  else cout << "Worse" << '\n';
  return 0;
}