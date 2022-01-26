#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  while (c <= b) {
    if (c >= a && c <= b) {
      cout << c << endl;
      return 0;
    }
    c += c;
  }
  cout << -1 << endl;
  return 0;
}