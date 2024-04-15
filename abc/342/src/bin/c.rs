use im_rc::HashMap;
use proconio::{fastout, input, marker::Chars};

#[fastout]
fn main() {
    input! {
        n: usize,
        s: Chars,
        q: usize,
        cd: [(char, char); q],
    }

    let mut edge: Vec<Vec<usize>> = vec![vec![]; 26];
    for (c, d) in cd {
        let c = c as usize - 'a' as usize;
        let d = d as usize - 'a' as usize;
        edge[c].push(d);
    }

    let mut converter: HashMap<char, char> = HashMap::new();
    for i in 0..26 {
        if edge[i].is_empty() {
            continue;
        }

        let mut stack = vec![i];
        while let Some(j) = stack.pop() {
            for &k in &edge[j] {
                if !converter.contains_key(&(k as u8 as char)) {
                    converter.insert(k as u8 as char, j as u8 as char);
                    stack.push(k);
                }
            }
        }
    }
}
