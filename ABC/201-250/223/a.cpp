#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  string s;
  cin >> s;
  int len = s.size();
  if (len == 1 && s[0] == '0') {
    cout << "No" << endl;
    return 0;
  }
  if (s[1] == '0' && s[2] == '0') cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}