#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b, c;
  cin >> a >> b >> c;

  if (b-a == c-b) cout << "YES" << '\n';
  else cout << "NO" << '\n';
  return 0;
}