#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll h, w;
  cin >> h >> w;

  vector<string> c(h);
  rep(i, h) cin >> c[i];

  rep(i, h) {
    cout << c[i] << '\n';
    cout << c[i] << '\n';
  }
  return 0;
}