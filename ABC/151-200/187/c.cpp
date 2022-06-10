#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  set<string> st;
  rep(i, n) st.insert(s[i]);
  rep(i, n) {
    if (st.count("!" + s[i])) {
      cout << s[i] << endl;
      return 0;
    }
  }
  cout << "satisfiable" << endl;
  return 0;
}