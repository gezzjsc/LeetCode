#include <vector>
int longestOnes(std::vector<int>& A, int K) {
    int max_length = 0;
    int begin_index = 0, end_index = 0;
    int change_size = K;
    while(begin_index < A.size() && end_index < A.size()) {
        int tmp_max = 0;
        if (A[begin_index] == 0) {
            change_size--;
        }
        while(change_size >= 0) {
            end_index++;
            if (end_index >= A.size()) break;
            if (A[end_index] == 1) {
                end_index++;
            } else {
                change_size--;
            }
            tmp_max++;
        }
        max_length = std::max(tmp_max, max_length);
    }

}