/*
 * @lc app=leetcode.cn id=1657 lang=rust
 *
 * [1657] 确定两个字符串是否接近
 */

struct Solution {}
// @lc code=start
impl Solution {
    pub fn close_strings(word1: String, word2: String) -> bool {
        let calculate = |s: &str| -> [i32; 26] {
            let mut count = [0; 26];
            s.as_bytes().iter().for_each(|ch| {
                count[(*ch - b'a') as usize] += 1;
            });
            count
        };

        let mut c1 = calculate(&word1);
        let mut c2 = calculate(&word2);
        let check = c1
            .iter()
            .zip(c2.iter())
            .all(|(a, b)| (*a == 0 && *b == 0) || (*a != 0 && *b != 0));
        if !check {
            return false;
        }
        c1.sort_unstable();
        c2.sort_unstable();

        c1.eq(&c2)
    }
}
// @lc code=end

fn main() {
    println!("{}", Solution::close_strings("uau".into(), "ssx".into()));
}
