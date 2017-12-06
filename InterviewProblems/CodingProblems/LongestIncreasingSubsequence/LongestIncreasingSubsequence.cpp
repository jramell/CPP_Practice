#include <algorithm>
#include <vector>


int lengthOfLIS(std::vector<int>& numbers) {
    if(numbers.empty()) {
        return 0;
    }
    std::vector<int> bestLISEndingAt(numbers.size(), 1);
    int longestIncreasingSubsequence = 1;
    for(int i = 1; i < numbers.size(); i++) {
        for(int j = i-1; j >= 0; j--) {
            if(numbers.at(i) > numbers.at(j)) {
                bestLISEndingAt.at(i) = std::max(bestLISEndingAt.at(i), bestLISEndingAt.at(j)+1);
                longestIncreasingSubsequence = std::max(longestIncreasingSubsequence, bestLISEndingAt.at(i));
            }
        }
    }
    return longestIncreasingSubsequence;
}