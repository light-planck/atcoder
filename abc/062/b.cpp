#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll h, w;
  cin >> h >> w;

  vector<string> a(h);
  rep(i, h) cin >> a[i];

  cout << string(w+2, '#') << '\n';
  rep(i, h) {
    cout << '#' << a[i] << '#' << '\n';
  }
  cout << string(w+2, '#') << '\n';
  return 0;
}