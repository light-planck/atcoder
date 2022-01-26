#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
	int a1, a2, a3;
  cin >> a1 >> a2 >> a3;

  if (a3 == 2 * a2 - a1) cout << "Yes" << endl;
  else if (a3 == 2 * a1 - a2) cout << "Yes" << endl;
  else if (a2 == 2 * a1 - a3) cout << "Yes" << endl;
  else if (a2 == 2 * a3 - a1) cout << "Yes" << endl;
  else if (a1 == 2 * a2 - a3) cout << "Yes" << endl;
  else if (a1 == 2 * a3 - a2) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}