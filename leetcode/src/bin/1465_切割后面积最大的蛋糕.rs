/*
 * @lc app=leetcode.cn id=1465 lang=rust
 *
 * [1465] 切割后面积最大的蛋糕
 */

struct Solution {}
// @lc code=start
impl Solution {
    pub fn max_area(
        h: i32,
        w: i32,
        mut horizontal_cuts: Vec<i32>,
        mut vertical_cuts: Vec<i32>,
    ) -> i32 {
        horizontal_cuts.extend_from_slice(&[0, h]);
        vertical_cuts.extend_from_slice(&[0, w]);
        horizontal_cuts.sort_unstable();
        vertical_cuts.sort_unstable();

        let get_max = |v: &Vec<i32>| v.windows(2).map(|v| v[1] - v[0]).max().unwrap() as i64;

        (get_max(&horizontal_cuts) * get_max(&vertical_cuts) % 1000000007) as i32
    }
}
// @lc code=end

fn main() {
    println!("{}", Solution::max_area(5, 4, vec![1, 2, 4], vec![1, 3]));
}
