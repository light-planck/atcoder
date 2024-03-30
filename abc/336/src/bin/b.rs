use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i32,
    }

    let str = format!("{:b}", n);
    let mut ans = 0;

    for c in str.chars().rev() {
        if c == '0' {
            ans += 1;
        } else {
            break;
        }
    }

    println!("{}", ans);
}
