/*
 * @lc app=leetcode.cn id=907 lang=rust
 *
 * [907] 子数组的最小值之和
 */

use std::vec;

struct Solution {}
// @lc code=start
impl Solution {
    pub fn sum_subarray_mins(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut stack = Vec::with_capacity(n);
        stack.push((0, -1, 0));
        let mut result = 0;
        for (i, a) in arr.iter().enumerate() {
            let mut top = stack.last().unwrap();
            while top.0 >= *a {
                stack.pop();
                top = stack.last().unwrap();
            }
            let new_sum = (a * (i as i32 - top.1) + top.2) % 1000000007;
            result = (result + new_sum) % 1000000007;
            let p = (*a, i as i32, new_sum);
            stack.push(p);
        }

        result
    }
}
// @lc code=end

fn main() {
    println!("{}", Solution::sum_subarray_mins(vec![11, 81, 94, 43, 3]));
    println!("{}", Solution::sum_subarray_mins(vec![3, 1, 2, 4]));
}
