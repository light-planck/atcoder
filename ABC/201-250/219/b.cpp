#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  string t;
  cin >> t;
  rep(i, t.size()) {
    if (t[i] == '1') cout << s1;
    if (t[i] == '2') cout << s2;
    if (t[i] == '3') cout << s3;
  }
  cout << endl;
  return 0;
}