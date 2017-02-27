class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        size = len(nums)
        sum = 0
        for i in range(0, size):
            sum += nums[i]
        num = (size * (size + 1)) / 2 - sum
        if num:
            return num
        elif nums[0]:
            return 0
        else:
            return size + 1
            