use proconio::{fastout, input, marker::Chars};

#[fastout]
fn main() {
    input! {
        _: usize,
        s: Chars,
        q: usize,
        cd: [(char, char); q],
    }

    let alp = 'z' as u8 - 'a' as u8 + 1;
    let mut converter = (0..alp).map(|i| i).collect::<Vec<u8>>();

    for (c, d) in cd {
        for (i, j) in converter.clone().iter().enumerate() {
            if ('a' as u8 + *j) as char == c {
                converter[i] = d as u8 - 'a' as u8;
            }
        }
    }

    let ans = s
        .into_iter()
        .map(|c| ('a' as u8 + converter[c as usize - 'a' as usize]) as char)
        .collect::<String>();
    println!("{}", ans);
}
