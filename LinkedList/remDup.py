class Node:
    def __init__(self,data):
        self.data = data
    def addNext(self,nd):
        self.next = nd
    
def remDup(node):
    temp = node
    data = {}
    while(temp.next.next!=None):
        if data[temp.next.data]:
            temp.next=temp.next.next
        else:
            data[temp.next.data]="1"
global n1,n2,n3,n4,n5,n6,n7,n8
n1 = Node(12)
n2 = Node(11)
n3 = Node(12)
n4 = Node(21)
n5 = Node(41)
n6 = Node(43)
n7 = Node(21)
n8 = Node(21)
n7.addNext(n8)
n6.addNext(n7)
n5.addNext(n6)
n4.addNext(n5)
n3.addNext(n4)
n2.addNext(n3)
n1.addNext(n2)

def printNode(nd):
    try:
        print(nd.data)
        printNode(nd.next)
    except:
        pass

def remDup(nd):
    data = {}
    try:
        if (data[nd.next.data]):
            nd.next=nd.next.next
            remDup(nd.next)
    except:
        try:
            # print(nd.data)
            data[nd.next.data]=" "
            remDup(nd.next)
        except:
            pass

printNode(n1)
remDup(n1)
printNode(n1)

