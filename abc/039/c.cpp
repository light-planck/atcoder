#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;
  s = s + s;

  string t = "WBWBWWBWBWBW";
  vector<string> melody = {"Do", "Re", "Mi", "Fa", "So", "La", "Si", "Do"};

  ll step = 0;
  rep(i, t.size()+1) {
    string u = s.substr(i, t.size());
    cout << u << '\n';
    cout << t << '\n';
    cout << "___________" << '\n';
    if (u == t) {
      cout << melody[step] << '\n';
      return 0;
    }
    ++step;
  }
  return 0;
}