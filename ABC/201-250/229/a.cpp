#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  if ((s1 == ".#" && s2 == "#.") || (s1 == "#." && s2 == ".#")) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}