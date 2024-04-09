use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i64,
        a: [i64; n],
    }

    let mut min_sum = 0;
    let mut sum = 0;
    for a in a {
        sum += a;
        min_sum = min_sum.min(sum);
    }

    let ans = sum - min_sum;
    println!("{}", ans);
}
