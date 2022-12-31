#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  ++n;
  if (n == 13) n = 1;
  cout << n << '\n';
  return 0;
}