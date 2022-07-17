#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i, n) cin >> x[i];
  ll m = 0;
  ll e = 0;
  int c = 0;
  rep(i, n) m += abs(x[i]);
  rep(i, n) e += pow(abs(x[i]), 2);
  rep(i, n) c = max(c, abs(x[i]));

  cout << m << endl;
  printf("%.10f\n", sqrt(e));
  cout << c << endl;
}