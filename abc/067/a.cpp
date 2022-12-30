#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b;
  cin >> a >> b;
  if ((a+b) % 3 == 0) cout << "Possible" << '\n';
  else if (a%3 == 0) cout << "Possible" << '\n';
  else if (b%3 == 0) cout << "Possible" << '\n';
  else cout << "Impossible" << '\n';
  return 0;
}