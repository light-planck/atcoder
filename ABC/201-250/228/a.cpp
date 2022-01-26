#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int s, t, x;
  cin >> s >> t >> x;

  for (int i = s; ; i++) {
    if (i == t) break;
    if (i == 24) i = 0;
    if (i == x) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}