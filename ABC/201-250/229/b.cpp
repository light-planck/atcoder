#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  ll a, b;
  cin >> a >> b;
  bool dif = false;
  while (a > 0 && b > 0) {
    if (a % 10 + b % 10 >= 10) {
      cout << "Hard" << endl;
      return 0;
    }
    a /= 10;
    b /= 10;
  }
  cout << "Easy" << endl;
  return 0;
}