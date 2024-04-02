use itertools::Itertools;
use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i64,
        k: i64,
        a: [i64; n],
    }

    let ans = a
        .into_iter()
        .filter(|a| a % k == 0)
        .map(|a| a / k)
        .join(" ");
    println!("{}", ans);
}
