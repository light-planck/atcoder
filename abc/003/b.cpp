#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s, t;
  cin >> s >> t;

  ll n = s.size();
  set<char> st = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
  rep(i, n) {
    bool ng = false;
    if (t[i] == '@') swap(s[i], t[i]);
    if (s[i] == '@' and t[i] != '@' and not st.count(t[i])) {
      ng = true;
    }
    else if (s[i] != t[i]) ng = true;

    if (ng) {
      cout << "You will lose" << '\n';
      return 0;
    }
  }

  cout << "You can win" << '\n';
  return 0;
}