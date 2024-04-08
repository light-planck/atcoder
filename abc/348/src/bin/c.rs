use im_rc::HashMap;
use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i64,
        ac: [(i64, i64); n],
    }

    let mut min_a: HashMap<i64, i64> = HashMap::new();
    for (a, c) in ac {
        let entry = min_a.entry(c).or_insert(a);
        *entry = (*entry).min(a);
    }

    let ans = min_a.values().max().unwrap();
    println!("{}", ans);
}
