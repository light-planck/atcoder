#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll X, Y;
  cin >> X >> Y;

  ll d = Y - X;
  if (d <= 2 and d >= -3)
    cout << "Yes" << '\n';
  else
    cout << "No" << '\n';
}
