use im_rc::HashMap;
use proconio::{fastout, input, marker::Chars};

#[fastout]
fn main() {
    input! {
        s: Chars,
    }

    let mut ans = 0;
    let mut cnt: HashMap<char, i64> = HashMap::new();
    for (j, c) in s.iter().enumerate() {
        let count = cnt.entry(*c).or_insert(0);
        ans += j as i64 - *count;
        *count += 1;
    }

    if let Some(max_cnt) = cnt.values().max() {
        if max_cnt > &1 {
            ans += 1;
        }
    }

    println!("{}", ans);
}
