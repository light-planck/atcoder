#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  char a = s[0];
  char b = s[1];
  char c = s[2];

  string x;
  x += a;

  string y;
  y += b;

  string z;
  z += c;

  cout << stoi(x + y + z) + stoi(y + z + x) + stoi(z + x + y) << "\n";
  // string x = a + b + c;
  // cout << x << endl;
  // cout << stoi(a + b + c) + stoi(b + c + a) + stoi(c + a + b) << "\n";
  return 0;
}