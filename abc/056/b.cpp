#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll w, a, b;
  cin >> w >> a >> b;

  if (b > a+w) cout << b-a-w << '\n';
  else if (b+w < a) cout << a-b-w << '\n'; 
  else cout << 0 << '\n';
  return 0;
}