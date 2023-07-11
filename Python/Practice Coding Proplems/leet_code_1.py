class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        unique = []
        k = 0

        for i, num in enumerate(nums):
            if num == '_' and i != (len(nums) - 1):
                nums[i], nums[i+1] = nums[i+1], nums[i]

            elif num in unique:
                nums[i] = '_'
                nums[i], nums[i+1] = nums[i+1], nums[i]
                k += 1
            elif num != '_':
                unique.append(num)
                k += 1
        nums = unique
        return k

a = Solution()
print(a.removeDuplicates([0,0,1,1,1,2,2,3,3,4]))
