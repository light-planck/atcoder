use proconio::{fastout, input, marker::Chars};

#[fastout]
fn main() {
    input! {
        s: Chars,
    }

    let mut t = s.clone();
    t.sort();

    if s == t {
        println!("Yes");
    } else {
        println!("No");
    }
}
