#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


ll g(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return g(a%b, b);
}


int main() {
  ll a, b;
  cin >> a >> b;

  cout << g(a, b) << '\n';
  return 0;
}