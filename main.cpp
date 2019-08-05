#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

void print(std::vector<std::string> const &input)
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

std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> vec(n);
    std::generate(vec.begin(), vec.end(), [] {
        static int i = 1;
        return std::to_string(i++);
    });
    if (n > 2){
        for(int i = 2; i < n; i +=3){
            if((i + 1) % 5 == 0)
                vec[i] = "FizzBuzz";
            else
                vec[i] = "Fizz";
        }
        int a = 1;
        for(int i = 4; i < n; i += 5){
            if((i + 1) % 3 == 0)
                vec[i] = "FizzBuzz";
            else
                vec[i] = "Buzz";
        }
    }
    return vec;
}

int movesToMakeZigzag(std::vector<int>& nums) {
    int stepsOdd = 0, stepsEven = 0;
    std::vector<int> numsCopy = nums;

    if(nums.size() == 2){
        if(nums[0] == nums[1])
            return 1;
        else
            return 0;
    }

    if(nums.size() == 3){
        if(nums[0] <= nums[1]){
            stepsEven += nums[1] - nums[0] + 1;
            nums[1] = nums[0] - 1;
        }
        if(nums[2] <= nums[1]){
            stepsEven += nums[1] - nums[2] + 1;
            nums[1] = nums[2] - 1;
        }
        //ODD
        if(numsCopy[1] <= numsCopy[0]){
            stepsOdd += numsCopy[0] - numsCopy[1] + 1;
        }
        if(numsCopy[1] <= numsCopy[2]){
            stepsOdd += numsCopy[2] - numsCopy[1] + 1;
        }

        return stepsEven < stepsOdd ? stepsEven : stepsOdd;
    }

    for(int i = 0; i < nums.size(); i += 2){
        //EVEN
        if(i == 0){
            if(nums[i] <= nums[i + 1]){
                stepsEven += nums[i + 1] - nums[i] + 1;
                nums[i + 1] = nums[i] - 1;
            }
        }else{
            if(nums[i] <= nums[i - 1]){
                stepsEven += nums[i - 1] - nums[i] + 1;
                nums[i - 1] = nums[i] - 1;
            }
            if(i < nums.size() - 1){
                if(nums[i] <= nums[i + 1]){
                    stepsEven += nums[i + 1] - nums[i] + 1;
                    nums[i + 1] = nums[i] - 1;
                }
            }

        }

        //ODD
        if(i == 0){
            if(numsCopy[i] >= numsCopy[i + 1]){
                stepsOdd += numsCopy[i] - numsCopy[i + 1] + 1;
                numsCopy[i] = numsCopy[i + 1] - 1;
            }
        }else{
            if(numsCopy[i] >= numsCopy[i - 1]){
                stepsOdd += numsCopy[i] - numsCopy[i - 1] + 1;
                numsCopy[i] = numsCopy[i - 1] - 1;
            }
            if(i < numsCopy.size() - 1){
                if(numsCopy[i] >= numsCopy[i + 1]){
                    stepsOdd += numsCopy[i] - numsCopy[i + 1] + 1;
                    numsCopy[i] = numsCopy[i + 1] - 1;
                }
            }

        }

    }


    return stepsOdd < stepsEven ? stepsOdd : stepsEven;
}

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
    };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry  = 0, sum = 0, overflow = 0;
    ListNode *l3 = new ListNode(0);
    ListNode *auxL3 = l3;
    while (l1 != NULL || l2 != NULL){
        if(l1 != NULL){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL){
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum % 10;
        overflow = sum / 10;
        auxL3->val = carry;
        if(l1 != NULL || l2 != NULL || overflow > 0){
            auxL3->next = new ListNode(0);
            auxL3 = auxL3->next;
        }
        sum = overflow;
    }
    if(overflow > 0){
        auxL3->val = overflow;

    }

    return l3;
}


int main() {
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    ListNode *aux1 = l1->next;
    aux1->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    aux1 = l2->next;
    aux1->next = new ListNode(4);
    ListNode *l3 = addTwoNumbers(l1,l2);
    return 0;
}