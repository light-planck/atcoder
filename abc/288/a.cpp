#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    cout << a+b << '\n';
  }
  return 0;
}