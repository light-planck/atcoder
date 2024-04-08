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

    let ans;
    if l <= 0 && r >= 0 {
        ans = l.abs() / m + r / m + 1;
    } else {
        if l < 0 {
            (l, r) = (-r, -l);
        }
        ans = r / m - (l - 1) / m;
    }

    println!("{}", ans);
}
