use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        s: String,
    }

    match s[3..].parse::<i32>() {
        Ok(number) if 0 < number && number < 350 && number != 316 => println!("Yes"),
        _ => println!("No"),
    }
}
