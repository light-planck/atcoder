#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a * c <= b) cout << c << endl;
  else cout << b / a << endl;
  return 0;
}