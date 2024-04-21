use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        s: String,
    }

    let number = s[3..].parse::<i32>().unwrap();
    if 0 < number && number < 350 && number != 316 {
        println!("Yes");
    } else {
        println!("No");
    }
}
