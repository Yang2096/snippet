/*
 * @lc app=leetcode.cn id=1094 lang=rust
 *
 * [1094] 拼车
 */
struct Solution {}
// @lc code=start
impl Solution {
    pub fn car_pooling(trips: Vec<Vec<i32>>, capacity: i32) -> bool {
        let mut stops = [0; 1005];
        for trip in trips.iter() {
            stops[trip[1] as usize] += trip[0];
            stops[trip[2] as usize] -= trip[0];
        }

        let mut sum = 0;
        for i in stops.iter() {
            sum += *i;
            if sum > capacity {
                return false;
            }
        }
        true
    }
}
// @lc code=end

fn main() {
    println!(
        "{}",
        Solution::car_pooling(vec![vec![2, 1, 5], vec![3, 3, 7]], 5)
    );
}
