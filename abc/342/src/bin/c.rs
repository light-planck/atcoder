use im_rc::HashMap;
use proconio::{fastout, input, marker::Chars};

#[fastout]
fn main() {
    input! {
        _: usize,
        s: Chars,
        q: usize,
        cd: [(char, char); q],
    }

    let mut converter: HashMap<char, char> = ('a'..='z').map(|c| (c, c)).collect();

    for (c, d) in cd {
        for (k, v) in converter.clone() {
            if v == c {
                converter.insert(k, d);
            }
        }
    }

    let ans = s.into_iter().map(|c| converter[&c]).collect::<String>();
    println!("{}", ans);
}
