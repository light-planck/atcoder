use std::collections::HashMap;
use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        s: String,
    }

    let mut counts = HashMap::new();
    for c in s.chars() {
        *counts.entry(c).or_insert(0) += 1;
    }
    let target = *counts.iter().find(|(_, v)| **v == 1).unwrap().0;

    println!("{}", s.find(target).unwrap() + 1);
}
