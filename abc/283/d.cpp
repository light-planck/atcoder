#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  set<char> st;
  for (auto c : s) {
    if (c == '(') continue;;
    if (c == ')') st.clear();
    else {
      if (st.count(c)) {
        cout << "No" << '\n';
        return 0;
      }
      else st.emplace(c);
    }
  }
  
  cout << "Yes" << '\n';
  return 0;
}