#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9 + 7;

int main() {
  int a, b, t;
  cin >> a >> b >> t;
  int time = 0;
  int sum  = 0;
  for (int i = 1; i < t+1; i++) {
    if (i % a == 0) sum += b;
  }
  cout << sum << endl;
  return 0;
}