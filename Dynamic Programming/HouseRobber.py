class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        numHouses  = len(nums)
        
        maxRobbery = [None for _ in range(numHouses+1)]
        maxRobbery[numHouses-1] = nums[numHouses-1]
        maxRobbery[numHouses] = 0
        
        for i in range(numHouses-2, -1, -1):
            maxRobbery[i] = max(maxRobbery[i+1], maxRobbery[i+2] + nums[i])
            
        return maxRobbery[0]
