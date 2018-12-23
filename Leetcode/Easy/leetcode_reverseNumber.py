class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        x = str(x)
        
        if x[0] == '-':
            x = '-' + x[:0:-1] #음수일때 -빼고 뒤집기
        else:
            x = x[::-1]
            
        x = int(x)
        pos_limit = 0x7fffffff
        neg_limit = -0x80000000
        
        if x<0:
            if (x & neg_limit) == neg_limit:
                return x
            else:
                return 0
        elif x == 0:
            return 0
        else:
            if (x & pos_limit) == x:
                return x
            else:
                return 0
