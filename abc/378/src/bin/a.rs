use im_rc::HashMap;
use proconio::input;

fn main() {
    input! {
        a: [usize; 4],
    }

    let mut cnt = HashMap::new();

    for a in a.iter() {
        *cnt.entry(a).or_insert(0) += 1;
    }

    let mut ans = 0;

    for (_, value) in cnt {
        ans += value / 2;
    }

    println!("{}", ans);
}
