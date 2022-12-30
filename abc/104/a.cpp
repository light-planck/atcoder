#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll r;
  cin >> r;

  if (r < 1200) cout << "ABC" << '\n';
  else if (r < 2800) cout << "ARC" << '\n';
  else cout << "AGC" << '\n';
  return 0;
}