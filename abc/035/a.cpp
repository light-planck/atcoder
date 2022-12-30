#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll w, h;
  cin >> w >> h;

  ll g = gcd(w, h);
  w /= g; h /= g;
  if (w == 4) cout << "4:3" << '\n';
  else cout << "16:9" << '\n';
  return 0;
}