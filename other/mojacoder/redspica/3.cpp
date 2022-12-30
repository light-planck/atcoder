#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll k;
  cin >> k;
  ++k;

  bitset<64> bit(k);
  cout << bit << '\n';
  return 0;
}