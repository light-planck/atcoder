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

    let mut converter: HashMap<char, char> = HashMap::new();
    for c in 'a'..='z' {
        converter.insert(c, c);
    }

    for (c, d) in cd {
        for (k, v) in converter.clone() {
            if v == c {
                converter.insert(k, d);
            }
        }
    }

    let ans = s
        .into_iter()
        .map(|c| converter.get(&c).unwrap())
        .collect::<String>();
    println!("{}", ans);
}
