#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
  rep(i, m) cin >> b[i];
  
  int cnt = 0;
  rep(i, n) {
    int sum = 0;
    rep(i, m) {
      int a;
      cin >> a;
      sum += a * b[i];
    }
    if (sum + c > 0) cnt++;
  }
  
  cout << cnt << endl;
  return 0;
}