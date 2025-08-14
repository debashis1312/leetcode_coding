class Solution(object):
    def largestGoodInteger(self, num):
        """
        :type num: str
        :rtype: str
        """
        largest_good_int = ""

        for i in range(0, len(num) - 2):  # Corrected 'for i from 0 TO ...'
            substring = num[i:i+3]

            # Check if all 3 digits are the same
            if substring[0] == substring[1] and substring[1] == substring[2]:
                # Compare with the current largest good integer
                if largest_good_int == "" or substring > largest_good_int:
                    largest_good_int = substring

        return largest_good_int
