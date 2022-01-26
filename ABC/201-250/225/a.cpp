#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int fact(int x) {
  if (x == 1) return 1;
  return x * fact(x - 1);
}

int main() {
  string s;
  cin >> s;
  set<char> st;
  rep(i, (int)s.size()) st.insert(s[i]);
  int sum = st.size();
  if (sum == 3) cout << 6 << endl;
  else if (sum == 2) cout << 3 << endl;
  else cout << 1 << endl;
  return 0;
}