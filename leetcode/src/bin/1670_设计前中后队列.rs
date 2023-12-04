/*
 * @lc app=leetcode.cn id=1670 lang=rust
 *
 * [1670] 设计前中后队列
 */

// @lc code=start
use std::collections::VecDeque;
struct FrontMiddleBackQueue {
    left: VecDeque<i32>,
    right: VecDeque<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FrontMiddleBackQueue {
    fn new() -> Self {
        Self {
            left: VecDeque::new(),
            right: VecDeque::new(),
        }
    }

    fn push_front(&mut self, val: i32) {
        self.left.push_front(val);

        self.banlance()
    }

    fn push_middle(&mut self, val: i32) {
        self.left.push_back(val);
        self.banlance();
    }

    fn push_back(&mut self, val: i32) {
        self.right.push_back(val);
        self.banlance();
    }

    fn pop_front(&mut self) -> i32 {
        let res = if self.left.is_empty() {
            self.right.pop_front().unwrap_or(-1)
        } else {
            self.left.pop_front().unwrap_or(-1)
        };
        self.banlance();
        res
    }

    fn pop_middle(&mut self) -> i32 {
        let res = if self.left.len() < self.right.len() {
            self.right.pop_front().unwrap_or(-1)
        } else {
            self.left.pop_back().unwrap_or(-1)
        };
        self.banlance();
        res
    }

    fn pop_back(&mut self) -> i32 {
        let res = self.right.pop_back().unwrap_or(-1);
        self.banlance();
        res
    }

    fn banlance(&mut self) {
        let n = self.left.len() + self.right.len();
        let mid = n / 2;
        while self.left.len() > mid && !self.left.is_empty() {
            self.right.push_front(self.left.pop_back().unwrap());
        }
        while self.right.len() > mid + (n % 2) && !self.right.is_empty() {
            self.left.push_back(self.right.pop_front().unwrap());
        }
    }
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * let obj = FrontMiddleBackQueue::new();
 * obj.push_front(val);
 * obj.push_middle(val);
 * obj.push_back(val);
 * let ret_4: i32 = obj.pop_front();
 * let ret_5: i32 = obj.pop_middle();
 * let ret_6: i32 = obj.pop_back();
 */
// @lc code=end

fn main() {
    let mut obj = FrontMiddleBackQueue::new();
    obj.push_front(1);
    obj.push_back(2);
    obj.push_middle(3);
    obj.push_middle(4);
    println!("{}", obj.pop_front());
    println!("{}", obj.pop_middle());
    println!("{}", obj.pop_middle());
    println!("{}", obj.pop_back());
    println!("{}", obj.pop_front());
}
