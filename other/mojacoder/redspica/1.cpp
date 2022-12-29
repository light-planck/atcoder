#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll b, h;
  cin >> b >> h;

  ll dmg = b*39 + h*140;
  if (dmg >= 150) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}