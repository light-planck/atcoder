#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  rep(i, n) {
    ll c;
    cin >> c;
    if (c == a+b) {
      cout << i+1 << '\n';
    }
  }
  return 0;
}