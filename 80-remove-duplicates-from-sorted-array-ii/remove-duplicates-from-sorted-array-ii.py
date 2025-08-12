class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # A two-pointer approach to remove duplicates in a sorted array
        # where each element can appear at most twice.
        
        # 'i' is the "writer" pointer. It tracks the position where the
        # next valid element should be placed. It also serves as the
        # final length of the modified array.
        i = 0
        
        # We iterate through the original array with 'num' as the "reader" pointer.
        for num in nums:
            # The core logic: check if the current number 'num' is a valid addition.
            # A number is valid if:
            # 1. The new array has less than two elements (i < 2). The first
            #    two elements are always valid as they have no preceding duplicates.
            # 2. The current number 'num' is greater than the element two positions
            #    behind the writer pointer (nums[i - 2]). Since the array is sorted,
            #    this ensures we are not adding a third or more duplicate.
            if i < 2 or num > nums[i - 2]:
                nums[i] = num
                i += 1
        
        # 'i' now holds the length of the new, compressed array.
        # The modified array is from index 0 to i-1.
        return i
