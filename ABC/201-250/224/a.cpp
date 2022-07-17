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
  int n = s.size();
  if (s[n-1] == 'r') cout << "er" << endl;
  else if (s[n-1] == 't') cout << "ist" << endl;
  return 0;
}