class Solution:
    def hasTrailingZeros(self, nums: List[int]) -> bool:
        count = 0
    
        for num in nums:
            if not num & 1:
                count += 1
    
        return True if count >= 2 else False
    
        
        
        
        
        