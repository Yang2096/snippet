/*
 * @lc app=leetcode.cn id=1625 lang=rust
 *
 * [1625] 执行操作后字典序最小的字符串
 */

use std::collections::HashSet;
// @lc code=start

pub fn find_lex_smallest_string(s: String, a: i32, b: i32) -> String {
    let mut checked_str = HashSet::<String>::new();
    let mut smallest_str = s.clone();
    traval(&s, &mut checked_str, &mut smallest_str, a, b);

    smallest_str
}

fn traval(s: &str, checked: &mut HashSet<String>, smallest: &mut String, a: i32, b: i32) {
    let current = string_add(s, a);
    if checked.contains(&current) {
        return;
    } else {
        checked.insert(current.clone());
        if current < *smallest {
            *smallest = current.clone();
        }
        traval(&current, checked, smallest, a, b);
    }

    let m = string_move(&current, b);
    if checked.contains(&m) {
        return;
    }
    checked.insert(m.clone());
    if m < *smallest {
        *smallest = m.clone();
    }
    traval(&m, checked, smallest, a, b);
}

fn string_add(s: &str, a: i32) -> String {
    let mut count = 0;
    s.chars()
        .map(|ch| {
            count = 1 - count;
            if count == 0 {
                ((ch as i32 - 48 + a) % 10 + 48) as u8 as char
            } else {
                ch
            }
        })
        .collect()
}

fn string_move(s: &String, b: i32) -> String {
    let mut res = String::with_capacity(s.len());
    let b = b as usize;
    res += &s[b..];
    res += &s[..b];
    res
}
// @lc code=end
fn main() {
    assert_eq!(
        "2050".to_string(),
        find_lex_smallest_string("5525".to_string(), 9, 2)
    );
    assert_eq!(
        "24".to_string(),
        find_lex_smallest_string("74".to_string(), 5, 1)
    );
}
