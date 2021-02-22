/**
 * 题目:给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。
 *     返回仅包含 1 的最长（连续）子数组的长度。
 * 示例1： 输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
 *        输出：6
 *        解释： [1,1,1,0,0,1,1,1,1,1,1]
 * 示例2: 输入：A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
 *        输出：10
 *        解释：[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 */

#include <vector>
int longestOnes(std::vector<int>& A, int K) {
    int max_length = 0;
    int begin_index = 0, end_index = 0;
    int first_zero_index = -1;
    int change_size = K;
    while(begin_index < A.size() && end_index < A.size()) {
        if (A[begin_index] == 0) {
            first_zero_index = begin_index;
            change_size--;
        }
        while(change_size >= 0) {
            end_index++;
            if (end_index >= A.size()) {
                break;
            }
            if (A[end_index] == 0) {
                if (first_zero_index == -1) first_zero_index = end_index;
                if (change_size > 0) {
                    change_size--;
                } else {
                    break;
                }
            }
        }
        max_length = std::max(end_index - begin_index, max_length);
        if (begin_index == end_index) {
            begin_index++;
            end_index = begin_index;
        } else {
            if (end_index < A.size()) {
                begin_index = first_zero_index + 1;
                end_index = begin_index;
            } else {
                break;
            }
        }
        change_size = K;
        first_zero_index = -1;
    }
    return max_length;
}