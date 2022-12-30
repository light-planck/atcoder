#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b;
  cin >> a >> b;

  if (a <= 8 and b <= 8) cout << "Yay!" << '\n';
  else cout << ":(" << '\n';
  return 0;
}