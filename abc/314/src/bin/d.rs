use proconio::{input, marker::Chars};

fn main() {
    input! {
        _: usize,
        mut s: Chars,
        q: usize,
        queries: [(usize, usize, char); q],
    }

    // 最後に大文字か小文字に変換したクエリのインデックスを取得する
    let last_convert_query_idx = if let Some(idx) = queries.iter().rposition(|&(t, _, _)| t > 1) {
        idx
    } else {
        0
    };

    for (i, (t, x, c)) in queries.into_iter().enumerate() {
        if t == 1 {
            s[x - 1] = c;
        } else if i == last_convert_query_idx {
            match t {
                2 => s = s.iter().map(|c| c.to_ascii_lowercase()).collect(),
                3 => s = s.iter().map(|c| c.to_ascii_uppercase()).collect(),
                _ => unreachable!(),
            }
        }
    }

    println!("{}", s.iter().collect::<String>());
}
