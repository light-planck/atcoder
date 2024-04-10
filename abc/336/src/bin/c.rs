use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        mut n: i64,
    }
    n -= 1;

    let mut digits = Vec::new();
    while n >= 0 {
        digits.push(n % 5);
        n /= 5;

        if n == 0 {
            break;
        }
    }
    digits.reverse();

    for digit in digits {
        print!("{}", digit * 2);
    }
    println!();
}
