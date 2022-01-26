#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  if (s.size() <= k) cout << s << endl;
  else{
    cout << s.substr(0, k) << "..." << endl;
  }
}