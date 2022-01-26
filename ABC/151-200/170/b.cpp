#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int x, y;
  cin >> x >> y;
  bool can = false;
  for (int c = 0; c <= x; c++){
    int t = x - c;
    int legs = 2 * c + 4 * t;
    if (legs == y) can = true;
  }
  puts(can ? "Yes" : "No");
}