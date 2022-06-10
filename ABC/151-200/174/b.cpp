#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  double d;
  cin >> n >> d;
  int cnt = 0;
  rep(i, n){
    double x, y;
    cin >> x >> y;
    double l = sqrt(x * x + y * y);
    if (l <= d) cnt++;
  }
  cout << cnt << endl;
}