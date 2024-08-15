//  res [i] is a vector containing all possible sum by considering i elements
//For eg let arr = [2,4,2] then res[2] = {6,4,6} i.e. the sum of elements of arr taken  two at a time

vector<vector<int>> findAllSubsetsSum(vector<int>& nums, int l, int r) {
        int totLengthOfSubarray = r - l + 1;
        vector<vector<int>> res(totLengthOfSubarray + 1);
        for (int i = 0; i < (1 << totLengthOfSubarray); i++) {
            int sum = 0, countOfChosenNos = 0;
            for (int j = 0; j < totLengthOfSubarray; j++) {
                if (i & (1 << j)) {
                    sum += nums[l + j];
                    countOfChosenNos++;
                }
            }
        res[countOfChosenNos].push_back(sum);
    }
        return res;
    }
