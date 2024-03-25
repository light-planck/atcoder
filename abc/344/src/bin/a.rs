use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        s: String,
    }

    let t = s.split('|').collect::<Vec<&str>>();
    println!("{}{}", t.first().unwrap(), t.last().unwrap());
}
