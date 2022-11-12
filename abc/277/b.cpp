#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  ll n;
  cin >> n;

  set<string> st;

  rep(i, n) {
    string s;
    cin >> s;

    if (st.count(s)) {
      cout << "No" << '\n';
      return 0;
    }

    bool ok = true;
    set<char> c1 = {'H' , 'D' , 'C' , 'S'};
    if (not c1.count(s[0])) ok = false;

    // if (s[0] != 'H' and s[0] != 'D' and s[0] != 'C' and s[0] != 'S') ok = false;

    set<char> cs = {'A' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'T' , 'J' , 'Q' , 'K'};
    if (not cs.count(s[1])) ok = false;

    if (not ok) {
      cout << "No" << '\n';
      return 0;
    }

    st.emplace(s);
  }

  cout << "Yes" << '\n';
  return 0;
}