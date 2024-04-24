use proconio::{fastout, input, marker::Chars};

#[fastout]
fn main() {
    input! {
        (n, t): (usize, Chars),
        s: [Chars; n],
    }

    let solve = |s: &Vec<char>| -> bool {
        (s.len() as i32 - t.len() as i32).abs() <= 1
            && (*s == t
                || hamming_distance(&s, &t) == 1
                || is_substring(&s, &t)
                || is_substring(&t, &s))
    };

    let ans = s
        .iter()
        .enumerate()
        .filter_map(|(i, s)| if solve(&s) { Some(i + 1) } else { None })
        .collect::<Vec<usize>>();

    println!("{}", ans.len());
    println!(
        "{}",
        ans.into_iter()
            .map(|x| x.to_string())
            .collect::<Vec<String>>()
            .join(" ")
    );
}

fn hamming_distance(s: &Vec<char>, t: &Vec<char>) -> usize {
    if s.len() != t.len() {
        return usize::MAX;
    }

    s.iter().zip(t.iter()).filter(|&(a, b)| a != b).count()
}

// sがtの1文字だけ削除した部分文字列か判定
fn is_substring(s: &Vec<char>, t: &Vec<char>) -> bool {
    if s.len() + 1 != t.len() {
        return false;
    }

    let mut si = 0;
    for t in t {
        if *t == s[si] {
            si += 1;

            if si == s.len() {
                return true;
            }
        }
    }

    false
}
