#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, d;
  cin >> a >> d;
  cout << max((a+1)*d, a*(d+1)) << '\n';
  return 0;
}