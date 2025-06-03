class Solution:
    def solve(self, i, nums, target, prod, temp, picked):
        if i == len(nums):
            return picked and temp == target and temp * temp == prod
        if self.solve(i + 1, nums, target, prod, temp, picked):
            return True
        return self.solve(i + 1, nums, target, prod, temp * nums[i], True)

    def checkEqualPartitions(self, nums, target):
        prod = 1
        for x in nums:
            prod *= x
        return self.solve(0, nums, target, prod, 1, False)
