#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() { 
  string s;
  cin >> s;

  set<string> st = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};

  if (st.count(s)) cout << "Yes" << '\n';
  else cout << "No" << '\n';
}
