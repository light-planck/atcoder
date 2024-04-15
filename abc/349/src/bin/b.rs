use im_rc::HashMap;
use proconio::{fastout, input, marker::Chars};

#[fastout]
fn main() {
    input! {
        s: Chars,
    }

    let mut cnt: HashMap<char, i64> = HashMap::new();
    for c in s {
        *cnt.entry(c).or_insert(0) += 1;
    }

    let mut types: HashMap<i64, Vec<char>> = HashMap::new();
    for (c, n) in cnt {
        let entry = types.entry(n).or_insert(Vec::new());
        entry.push(c);
    }

    for (_, cs) in types {
        if cs.len() == 0 || cs.len() != 2 {
            println!("No");
            return;
        }
    }

    println!("Yes");
}
