class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        
        leng = len(letters)
        for i in range(0, leng):
            if letters[i] > target:
                return letters[i]
        return letters[0]
    
       


