#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  int k;
  cin >> k;
  ll sum = 0;
  for (int a = 1; a <= k; a++) {
    for (int b = 1; b <= k; b++) {
      for (int c = 1; c <= k; c++) {
        int x = gcd(a, b);
        int y = gcd(x, c);
        sum += y;
      }
    }
  }

  cout << sum << endl;
  return 0;
}