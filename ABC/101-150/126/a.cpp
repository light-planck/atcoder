#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9 + 7;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  s[k-1] = tolower(s[k-1]);
  cout << s << endl;
  return 0;
}