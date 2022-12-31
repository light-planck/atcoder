#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  auto round = [](ll a, ll b) { return (a + b - 1) / b; };
  cout << round(n, 2) << '\n';
  return 0;
}