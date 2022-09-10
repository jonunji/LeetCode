class Solution:
    def canJump(self, nums: List[int]) -> bool:        
        count = 0
        if nums[-1] == 0:
            count = -1
        for i in range(-1,-(len(nums)+1),-1):
            if nums[i] <= count:
                count+=1
            else:
                count = 0
        return count == 0 
        