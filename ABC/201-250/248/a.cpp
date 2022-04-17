#include <bits/stdc++.h>
using namespace std;


/*
0 ~ 9までの10個の数字のうち、9文字の文字列で
登場しなかった数字を求めたい。
*/


int main() {
  string s;
  cin >> s;

  // 0 ~ 9の数字で出現した数
  // trueは出現、falseは出現していないことを表す
  // seen[2] = true => 2は出現した
  vector<bool> seen(10, false);

  for (int i = 0; i < 9; ++i) {
    // s[i]を数字に変換
    int num = s[i] - '0';

    // 出現したらtrueにする
    seen[num] = true;
  }

  for (int i = 0; i < 10; ++i) {

    // 出現していない数字を出力
    if (seen[i] == false) {
      cout << i << endl;
    }
  }
  return 0;
}