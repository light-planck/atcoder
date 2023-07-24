#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() { 
  ll a, b;
  cin >> a >> b;

  if (b-a == 1 and (a%3 != 0)) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}