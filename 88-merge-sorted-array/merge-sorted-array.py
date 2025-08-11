class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        # Pointer to the last element of the combined array in nums1
        last = m + n - 1

        # While there are elements to compare in both arrays
        while m > 0 and n > 0:
            # Compare the last element of the valid parts of each array
            if nums1[m - 1] > nums2[n - 1]:
                # If nums1's element is larger, place it at the 'last' position
                nums1[last] = nums1[m - 1]
                # Move the pointer for nums1 back
                m -= 1
            else:
                # If nums2's element is larger, place it at the 'last' position
                nums1[last] = nums2[n - 1]
                # Move the pointer for nums2 back
                n -= 1
            
            # Decrement the 'last' pointer after each placement
            last -= 1

        # After the loop, there might be remaining elements in nums2.
        # This loop copies any remaining elements from nums2 to the front of nums1.
        while n > 0:
            nums1[last] = nums2[n - 1]
            n -= 1
            last -= 1


