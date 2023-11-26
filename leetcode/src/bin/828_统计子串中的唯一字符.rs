/*
 * @lc app=leetcode.cn id=828 lang=rust
 *
 * [828] 统计子串中的唯一字符
 */

struct Solution {}

// @lc code=start
impl Solution {
    pub fn unique_letter_string(s: String) -> i32 {
        let mut char_pos = vec![(-1, -1); 26];
        let mut result = 0;
        for (i, ch) in s.into_bytes().iter().enumerate() {
            let ch = (ch - b'A') as usize;
            char_pos[ch] = (i as i32, char_pos[ch].0);
            for pos in char_pos.iter() {
                if pos.0 != -1 {
                    result += pos.0 - pos.1;
                }
            }
        }
        result
    }
}
// @lc code=end

fn main() {
    println!("{}", Solution::unique_letter_string("ABC".into()));
}
