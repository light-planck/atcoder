use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        mut s: String,
    }

    s.pop();
    s.push('4');
    println!("{}", s);
}
