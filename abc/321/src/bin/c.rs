use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        _: String,
    }

    let mut k = 1;

    for i in 1.. {
        if k > 100 {
            break;
        }

        if is_321(i) {
            println!("k: {}, f: {}", k, i);
            k += 1;
        }
    }
}

fn is_321(k: i64) -> bool {
    let s = k.to_string().chars().collect::<Vec<char>>();
    let mut prev = '.';

    for c in s {
        match prev {
            '.' => prev = c,
            _ if c < prev => prev = c,
            _ => return false,
        }
    }

    true
}
