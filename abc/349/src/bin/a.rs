use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i64,
        a: [i64; n - 1],
    }

    let ans = -a.into_iter().sum::<i64>();
    println!("{}", ans);
}
