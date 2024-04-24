use std::mem::swap;

use proconio::{fastout, input, marker::Chars};

#[fastout]
fn main() {
    input! {
        (n, t): (usize, Chars),
        s: [Chars; n],
    }

    let mut ans = vec![];

    for (i, s) in s.iter().enumerate() {
        if s.len() == t.len() {
            if *s == t {
                ans.push(i + 1);
            } else if diff_char(&s, &t) == 1 {
                ans.push(i + 1);
            }
        } else if (s.len() as i32 - t.len() as i32).abs() == 1 {
            let mut short = s.clone();
            let mut long = t.clone();

            if short.len() > long.len() {
                swap(&mut short, &mut long);
            }

            if removed_one_char_strings(&long)
                .into_iter()
                .any(|str| str == short)
            {
                ans.push(i + 1);
            }
        }
    }

    println!("{}", ans.len());
    println!(
        "{}",
        ans.iter()
            .map(|x| x.to_string())
            .collect::<Vec<String>>()
            .join(" ")
    );
}

fn diff_char(s: &Vec<char>, t: &Vec<char>) -> usize {
    let mut diff = 0;

    for i in 0..s.len() {
        if s[i] != t[i] {
            diff += 1;
        }
    }

    diff
}

fn removed_one_char_strings(s: &Vec<char>) -> Vec<Vec<char>> {
    (0..s.len())
        .map(|i| {
            let mut t = s.clone();
            t.remove(i);
            t
        })
        .collect()
}
