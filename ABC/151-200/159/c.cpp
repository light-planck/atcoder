#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  double l;
  cin >> l;
  double ans = l * l * l / 27;
  printf("%.7f\n", ans);
  return 0;
}