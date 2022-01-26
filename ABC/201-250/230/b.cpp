#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  string s;
  cin >> s;
  string t = "oxx";
  rep(i, 15) t += t;
  if (t.find(s) != string::npos) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}