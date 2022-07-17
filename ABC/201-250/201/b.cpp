#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
	int n;
  cin >> n;

  vector<pair<int, string>> mou(n);
  rep(i, n){
    string s; int t;
    cin >> s >> t;
    mou[i].first = t;
    mou[i].second = s;
  }

  sort(mou.rbegin(), mou.rend());

  cout << mou[1].second << endl;
}