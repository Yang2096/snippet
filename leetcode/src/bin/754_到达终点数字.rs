/*
 * @lc app=leetcode.cn id=754 lang=rust
 *
 * [754] 到达终点数字
 */

struct Solution {}

// @lc code=start
impl Solution {
    pub fn reach_number(target: i32) -> i32 {
        let target = target.abs() as i64;

        let mut left = 1;
        let mut right = target;
        while left < right {
            let mid = left + (right - left) / 2;
            if (mid + 1) * mid / 2 < target {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        let mut n = right;
        while ((n + 1) * n / 2 - target) % 2 != 0 {
            n += 1;
        }

        n as i32
    }
}
// @lc code=end

fn main() {
    println!("{}", Solution::reach_number(2));
    println!("{}", Solution::reach_number(-6));
    println!("{}", Solution::reach_number(11));
    println!("{}", Solution::reach_number(1));
    println!("{}", Solution::reach_number(3));
    println!("{}", Solution::reach_number(4));
    println!("{}", Solution::reach_number(5));
    println!("{}", Solution::reach_number(1000000000));
}
