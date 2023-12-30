class Solution(object):
    def makeEqual(self, words):
        """
        :type words: List[str]
        :rtype: bool
        """
        total_characters = 0
        character_count = {}

        for word in words:
            for char in word:
                total_characters += 1
                character_count[char] = character_count.get(char, 0) + 1
        

        if total_characters % len(words) != 0:
            return False


        for count in character_count.values():
            if count % len(words) != 0:
                return False    


        return True    
       
    
        