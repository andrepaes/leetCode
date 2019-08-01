#include <iostream>
#include <vector>
#include <unordered_map>

void print(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int maxSubArray(std::vector<int> nums) {
    long long sum = nums[0], maxSum = nums[0];
    bool broken = sum < 0;
    for (int i = 1; i < nums.size(); i++) {
        if(broken){
            sum = nums[i];
            broken = sum < 0;
            if(nums[i] > maxSum)
                maxSum = nums[i];
            continue;
        }
        if(sum + nums[i] < 0){
            broken = true;
            continue;
        }else{
            sum += nums[i];
            broken = false;
            if(sum > maxSum)
                maxSum = sum;
        }
    }
    return maxSum;
}

void moveZeroes(std::vector<int>& nums) {
    int accumulator = 0;
    for(int i = 0, j = 0; i < nums.size() - j; i++){
        if(nums[i] == 0){
            accumulator = nums[i];
            nums.erase(nums.begin() + i);
            nums.push_back(accumulator);
            i--;
            j++;
        }
    }
}

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_map<int, int> copy;
    std::unordered_map<int,int>::const_iterator element;
    for (int i = 0; i < nums.size(); i++) {
         element = copy.find(nums[i]);
        if(element == copy.end())
            copy.insert({nums[i],i});
        else
            return true;
    }
    return false;
}

void rotate(std::vector<int>& nums, int k) {
        unsigned long quantityLoops = k % nums.size();
        auto first = nums.cend() - quantityLoops;
        auto last = nums.cend();

        std::vector<int> rotateVector(first, last);
        std::vector<int> remainingVector(nums.cbegin(), first);

        rotateVector.insert( rotateVector.end(), remainingVector.begin(), remainingVector.end());
        nums = rotateVector;
}



int main() {
    std::vector<int> vet{1,2};
    rotate(vet,2);
    return 0;
}