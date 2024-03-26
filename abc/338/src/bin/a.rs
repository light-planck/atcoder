use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        s: String,
    }

    if s.chars().next().unwrap().is_uppercase() && s[1..].chars().all(char::is_lowercase) {
        println!("Yes");
    } else {
        println!("No");
    }
}
