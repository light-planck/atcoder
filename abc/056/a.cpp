#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  char a, b;
  cin >> a >> b;

  if (a == 'H' and b == 'H') cout << 'H' << '\n';
  else if (a == 'D' and b == 'D') cout << 'H' << '\n';
  else cout << 'D' << '\n';
  return 0;
}