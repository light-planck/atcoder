#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  string s;
  cin >> s;
  vector<string> t = {"dream", "dreamer", "erase", "eraser"};
  bool ans = true;
  bool can = false;

  reverse(s.begin(), s.end());
  rep(i, 4) reverse(t.at(i).begin(), t.at(i).end());

  for (int i = 0; i < s.size();){
    for (int j = 0; j < t.size(); j++){
      if(s.substr(i, t.at(j).size()) == t.at(j)){
        can = true;
        i += t.at(j).size();
      }
    }

    if (!can){
      ans = false;
      break;
    }
  }

  if(ans) cout << "YES" << endl;
  else cout << "NO" << endl;
}