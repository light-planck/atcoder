#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  auto round = [](ll a, ll b) { return (a + b - 1) / b; };
  cout << round(n, m) << '\n';
  return 0;
}