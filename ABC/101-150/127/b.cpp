#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9 + 7;

int main() {
  int r, d;
  cin >> r >> d;
  vector<int> x(10);
  cin >> x[0];
  rep(i, 10) {
    x[i+1] = r * x[i] - d;
    cout << x[i+1] << endl;
  }
  return 0;
}