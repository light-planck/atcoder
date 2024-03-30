use im_rc::HashMap;
use proconio::{fastout, input, marker::Chars};

#[fastout]
fn main() {
    input! {
        s: Chars,
    }

    let mut count: HashMap<char, i32> = HashMap::new();
    for c in s {
        let c = count.entry(c).or_insert(0);
        *c += 1;
    }

    let max_count = count.values().cloned().max().unwrap();
    let mut str = String::new();
    for (c, value) in count {
        if value == max_count {
            str.push(c);
        }
    }

    let mut sorted_str = str.chars().collect::<Vec<char>>();
    sorted_str.sort();
    println!("{}", sorted_str[0]);
}
