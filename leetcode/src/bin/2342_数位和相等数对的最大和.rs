/*
 * @lc app=leetcode.cn id=2342 lang=rust
 *
 * [2342] 数位和相等数对的最大和
 */

// @lc code=start
pub fn maximum_sum(nums: Vec<i32>) -> i32 {
    fn digit_sum(mut num: i32) -> i32 {
        let mut result = 0;
        while num != 0 {
            result += num % 10;
            num /= 10;
        }
        result
    }

    let mut set = std::collections::HashMap::new();

    let mut result = -1;
    for num in nums.iter() {
        let s = digit_sum(*num);
        if let Some(sum) = set.get(&s) {
            result = std::cmp::max(result, *sum + *num);
            set.insert(s, std::cmp::max(*sum, *num));
        } else {
            set.insert(s, *num);
        }
    }
    result
}
// @lc code=end

fn main() {
    println!(
        "{}",
        maximum_sum(vec![
            368, 369, 307, 304, 384, 138, 90, 279, 35, 396, 114, 328, 251, 364, 300, 191, 438, 467,
            183
        ])
    );
}
