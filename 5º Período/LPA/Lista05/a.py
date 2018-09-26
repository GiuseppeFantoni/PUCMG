import io

class Needle:
    @staticmethod
    def count(needle, haystack):
        
        return len(str(haystack).split(str(needle))) - 1
    
        for i in haystack:
            
        
       
        return None

stream = io.StringIO("Hello, there!\nHow are you today?\nYes, you over there.")
print(Needle.count('there', stream))
stream.close()