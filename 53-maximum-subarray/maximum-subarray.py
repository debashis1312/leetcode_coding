class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        current_sum = nums[0]
        max_so_far = nums[0]
        
        # Iterate through the array starting from the second element.
        for i in range(1, len(nums)):
            current_sum = max(nums[i], current_sum + nums[i])
            max_so_far = max(max_so_far, current_sum)
        return max_so_far   