#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  int mx = 0;
  int cnt = 0;
  rep(i, n) {
    int h;
    cin >> h;
    if (mx <= h) {
      cnt++;
      mx = h;
    }
  }
  cout << cnt << endl;
  return 0;
}