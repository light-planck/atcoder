use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        mut n: i64,
    }

    n -= 1;
    let mut digits = Vec::new();

    while n > 0 {
        digits.push(n % 5);
        n /= 5;
    }

    if digits.is_empty() {
        digits.push(0);
    }

    digits.reverse();

    let ans = digits
        .into_iter()
        .map(|d| (d * 2).to_string())
        .collect::<String>();
    println!("{}", ans);
}
