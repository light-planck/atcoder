use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        a: i64,
        m: i64,
        mut l: i64,
        mut r: i64,
    }

    l -= a;
    r -= a;

    let d = 1e18 as i64 / m + 1;
    l += d * m;
    r += d * m;

    let ans = r / m - (l - 1) / m;
    println!("{}", ans);
}
