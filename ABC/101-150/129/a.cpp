#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9 + 7;

int main() {
  int p, q, r;
  cin >> p >> q >> r;
  cout << min({p+q, q+r, p+r}) << endl;
  return 0;
}