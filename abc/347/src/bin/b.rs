use im_rc::HashSet;
use proconio::{fastout, input, marker::Chars};

#[fastout]
fn main() {
    input! {
        s: Chars,
    }

    let mut hash: HashSet<String> = HashSet::new();
    let n = s.len();

    for l in 0..n {
        for r in l + 1..n + 1 {
            let str = s[l..r].iter().collect::<String>();
            hash.insert(str);
        }
    }

    println!("{}", hash.len());
}
