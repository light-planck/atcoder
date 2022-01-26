#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

string base_x(int n, int x) {
  string s;
  while (n > 0) {
    int d = n % x;
    s = to_string(d) + s;
    n /= x;
  }
  return s;
}

int main() {
  int n;
  cin >> n;
  int cnt = 0;

  string base10;
  string base8;

  for (int i = 1; i <= n; i++) {
    int x = i;

    base10 = base_x(i, 10);
    base8 = base_x(i, 8);

    if (base10.find("7") == string::npos && base8.find("7") == string::npos) {
      cnt++;
    }
  }

  cout << cnt << endl;
  return 0;
}