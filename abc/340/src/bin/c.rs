use im_rc::HashMap;
use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i64,
    }

    let mut memo: HashMap<i64, i64> = HashMap::new();
    let ans = f(n, &mut memo);
    println!("{}", ans);
}

fn f(x: i64, memo: &mut HashMap<i64, i64>) -> i64 {
    if x == 1 {
        return 0;
    }

    if memo.contains_key(&x) {
        return memo[&x];
    }

    let res = x + f(x / 2, memo) + f((x + 2 - 1) / 2, memo);
    memo.insert(x, res);
    res
}
