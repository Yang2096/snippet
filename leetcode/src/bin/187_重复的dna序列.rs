/*
 * @lc app=leetcode.cn id=187 lang=rust
 *
 * [187] 重复的DNA序列
 */

struct Solution {}
// @lc code=start
use std::collections::hash_set;
impl Solution {
    pub fn find_repeated_dna_sequences(s: String) -> Vec<String> {
        let mut hs = hash_set::HashSet::<String>::new();
        let mut result = hash_set::HashSet::<String>::new();
        s.as_bytes().windows(10).for_each(|input| {
            let s = std::str::from_utf8(input).unwrap().to_string();
            if !hs.contains(&s) {
                hs.insert(s);
            } else {
                result.insert(s);
            }
        });
        result.drain().collect()
    }
}
// @lc code=end

fn main() {
    println!(
        "{:?}",
        Solution::find_repeated_dna_sequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT".into())
    );
}
