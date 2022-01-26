#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  vector<int> q(n);

  rep(i, n) {
    int pi = p[i] - 1;
    q[pi] = i + 1;
  }
  for (auto r : q) {
    cout << r << endl;
  }
  return 0;
}