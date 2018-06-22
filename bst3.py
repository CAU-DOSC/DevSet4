class Node():
    
    def __init__(self, val):
        self.value = val
        self.left = None
        self.right = None
        
    def _insert(self,data):
        if data == self.value:
            return False
        
        elif data < self.value:
            if self.left:
                return self.left._insert(data)
            else:
                self.left=Node(data)
                return True
        else:
            if self.right:
                return self.right._insert(data)
            else:
                self.right = Node(data)
                return True
       
class Tree():
    
    def __init__(self):
        self.root = None
        
    def insert(self,data):
        if self.root:
            return self.root._insert(data)
        else:
            self.root = Node(data)
            return True