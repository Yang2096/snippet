/*
 * @lc app=leetcode.cn id=765 lang=rust
 *
 * [765] 情侣牵手
 */

struct Solution {}

// @lc code=start

fn find(union_set: &Vec<usize>, x: usize) -> usize {
    if union_set[x] != x {
        find(union_set, union_set[x])
    } else {
        x
    }
}

fn union(union_set: &mut Vec<usize>, x: usize, y: usize) {
    let y = find(union_set, y);
    let x = find(union_set, x);
    union_set[x] = union_set[y];
}

impl Solution {
    pub fn min_swaps_couples(row: Vec<i32>) -> i32 {
        let n = row.len() / 2;
        let mut union_set: Vec<_> = (0..n).collect();
        for i in 0..n {
            union(
                &mut union_set,
                row[i * 2] as usize / 2,
                row[i * 2 + 1] as usize / 2,
            );
        }
        let mut cycle_count = 0;
        for i in 0..n {
            if find(&union_set, i) == i {
                cycle_count += 1;
            }
        }
        (n - cycle_count) as i32
    }
}
// @lc code=end

fn main() {
    println!("{}", Solution::min_swaps_couples(vec![0, 2, 1, 3]));
}
