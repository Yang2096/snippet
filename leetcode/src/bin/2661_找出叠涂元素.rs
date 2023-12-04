/*
 * @lc app=leetcode.cn id=2661 lang=rust
 *
 * [2661] 找出叠涂元素
 */

struct Solution {}
// @lc code=start
impl Solution {
    pub fn first_complete_index(arr: Vec<i32>, mat: Vec<Vec<i32>>) -> i32 {
        let mut position = vec![(0, 0); arr.len()];
        let n = mat.len();
        let m = mat[0].len();

        for i in 0..n {
            for j in 0..m {
                position[(mat[i][j] - 1) as usize] = (i, j);
            }
        }

        let mut col = vec![0; n];
        let mut row = vec![0; m];

        for (i, num) in arr.iter().enumerate() {
            let (x, y) = position[(*num - 1) as usize];
            col[x] += 1;
            row[y] += 1;
            if col[x] == m || row[y] == n {
                return i as i32;
            }
        }
        0
    }
}
// @lc code=end

fn main() {
    println!(
        "{}",
        Solution::first_complete_index(vec![1, 3, 4, 2], vec![vec![1, 4], vec![2, 3]])
    );
    println!(
        "{}",
        Solution::first_complete_index(
            vec![2, 8, 7, 4, 1, 3, 5, 6, 9],
            vec![vec![3, 2, 5], vec![1, 4, 6], vec![8, 7, 9]]
        )
    );
}
