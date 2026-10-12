class Solution(object):
    def checkValidString(self, s):
        leftpar = "("
        rightpar =")"
        cl =0
        cr =0

        for char in s:
            if(char ==leftpar):
                cl +=1
                cr+=1

            if(char == rightpar):
                cl-=1
                cr-=1


            if(char =="*"):
                cl +=1
                cr-=1


            if(cl<0):
                return False
            

            if(cr<0):
                cr =0

        return cr ==0




