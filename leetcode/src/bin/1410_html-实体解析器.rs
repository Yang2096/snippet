/*
 * @lc app=leetcode.cn id=1410 lang=rust
 *
 * [1410] HTML 实体解析器
 */

struct Solution {}

// @lc code=start
impl Solution {
    pub fn entity_parser(text: String) -> String {
        let mut result = vec![];
        let n = text.len();
        result.reserve(n);
        let content = text.as_bytes();
        let mut i = 0;
        while i < n {
            let mut ch = content[i];
            i += 1;
            let mut go_on = true;
            if ch == b'&' {
                if n - i > 5 && content[i..i + 6].eq("frasl;".as_bytes()) {
                    ch = b'/';
                    i += 6;
                    go_on = false;
                }
                if go_on && n - i > 4 {
                    if content[i..i + 5].eq("quot;".as_bytes()) {
                        ch = b'"';
                        i += 5;
                        go_on = false
                    } else if content[i..i + 5].eq("apos;".as_bytes()) {
                        ch = b'\'';
                        i += 5;
                        go_on = false;
                    }
                }
                if go_on && n - i > 3 && content[i..i + 4].eq("amp;".as_bytes()) {
                    ch = b'&';
                    i += 4;
                    go_on = false;
                }
                if go_on && n - i > 2 {
                    if content[i..i + 3].eq("gt;".as_bytes()) {
                        ch = b'>';
                        i += 3;
                    } else if content[i..i + 3].eq("lt;".as_bytes()) {
                        ch = b'<';
                        i += 3;
                    }
                }
            }
            result.push(ch);
        }
        String::from_utf8(result).unwrap()
    }
}
// @lc code=end

fn main() {
    println!("{}", Solution::entity_parser("&amp;gt;".into()));
}
