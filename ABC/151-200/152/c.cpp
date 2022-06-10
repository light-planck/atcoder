#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  int cnt = 0;
  int mn = 1e9;
  rep(i, n) {
    int p;
    cin >> p;
    if (mn > p) {
      mn = p;
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}