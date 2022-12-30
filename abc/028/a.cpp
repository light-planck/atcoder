#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  if (n <= 59) cout << "Bad" << '\n';
  else if (60 <= n and n <= 89) cout << "Good" << '\n';
  else if (90 <= n and n <= 99) cout << "Great" << '\n';
  else cout << "Perfect" << '\n';
  return 0;
}