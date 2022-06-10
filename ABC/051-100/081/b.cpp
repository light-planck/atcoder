#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
	int n;
    cin >> n;
    vector<int> a(n);
		vector<int> cnt(n);

    rep(i, n){
        cin >> a.at(i);
    }

		for (int i = 0; i < a.size(); i++){
			while(a.at(i) % 2 == 0){
				a.at(i) /= 2;
				cnt.at(i) += 1;
			}
		}

		int ans = *min_element(cnt.begin(), cnt.end());

		cout << ans << endl;
}