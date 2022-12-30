#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll x, a, b;
  cin >> x >> a >> b;
  
  if (b-a <= 0) cout << "delicious" << '\n';
  else if (b-a <= x) cout << "safe" << '\n';
  else cout << "dangerous" << '\n';
  return 0;
}