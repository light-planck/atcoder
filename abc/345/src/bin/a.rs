use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        s: String,
    }

    let first = s.chars().next().unwrap();
    let between = &s[1..s.len() - 1];
    let last = s.chars().last().unwrap();

    if first == '<' && last == '>' && between.len() >= 1 && between.chars().all(|c| c == '=') {
        println!("Yes");
    } else {
        println!("No");
    }
}
