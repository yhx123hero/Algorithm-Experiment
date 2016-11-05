import numpy as np
import time;

L1 = []
L2 = []
def left(self, node):
    if node.rchild == self.nil:
        return
    y = node.rchild
    node.rchild = y.lchild
    if y.lchild != self.nil:
        y.lchild.parent = node
    y.parent = node.parent
    if node.parent == self.nil:
        self.root = y
    elif node == node.parent.lchild:
        node.parent.lchild = y
    else:
        node.parent.rchild = y
    y.lchild = node
    node.parent = y


def right(self,node):
    if node.lchild == self.nil:
        return
    y = node.lchild
    node.lchild = y.rchild
    if y.rchild != self.nil:
        y.rchild.parent = node
    y.parent = node.parent
    if node.parent == self.nil:
        self.root = y
    elif node == node.parent.rchild:
        node.parent.rchild = y
    else:
        node.parent.lchild = y
    y.rchild = node
    node.parent = y


def fixup(self, node):
    while node.parent.color == 0:
        if node.parent == node.parent.parent.lchild:
            y = node.parent.parent.rchild
            if y.color == 0:
                node.parent.color = 1
                y.color = 1
                node.parent.parent.color = 0
                node = node.parent.parent
            elif node == node.parent.rchild:
                node = node.parent
                left(self, node)
            else:
                node.parent.color = 1
                node.parent.parent.color = 0
                right(self, node.parent.parent)
        else:
            y = node.parent.parent.lchild
            if y.color == 0:
                node.parent.color = 1
                y.color = 1
                node.parent.parent.color = 0
                node = node.parent.parent
            elif node == node.parent.lchild:
                node = node.parent
                left(self, node)
            else:
                node.parent.color = 1
                node.parent.parent.color = 0
                right(self,node.parent.parent)
    self.root.color = 1

class Node(object):
    def __init__(self, elem=-1,color = 1,parent=None,lchild=None, rchild=None):
        self.elem = elem
        self.color = color
        self.parent = parent
        self.lchild = lchild
        self.rchild = rchild

class RBTree(object):
    def __init__(self):
        self.root = Node()
        self.nil = self.root

    def insert(self, elem):
        node = Node(elem)
        y = self.nil
        x = self.root
        while x != self.nil:
            y = x
            if node.elem < x.elem:
                x = x.lchild
            else:
                x = x.rchild
        node.parent = y
        if y == self.nil:
            self.root = node
        elif node.elem < y.elem:
            y.lchild = node
        else:
            y.rchild = node
        node.lchild = self.nil
        node.rchild = self.nil
        node.color = 0
        fixup(self,node)

    def preoreder(self, root):
        if root == self.nil:
            return
        L1.append(root.elem)
        self.preoreder(root.lchild)
        self.preoreder(root.rchild)

    def inoreder(self, root):
        if root == self.nil:
            return
        self.inoreder(root.lchild)
        L1.append(root.elem)
        self.inoreder(root.rchild)

    def postoreder(self, root):
        if root == self.nil:
            return
        self.postoreder(root.lchild)
        self.postoreder(root.rchild)
        L1.append(root.elem)

if __name__ == '__main__':
    fin = open("/home/yhx/PB14011025-project2/ex/input/input.txt", 'r')
    str1 = "/home/yhx/PB14011025-project2/ex/output/size"
    L = []
    for eachLine in fin:
        line = eachLine.strip().decode('utf-8','ignore')
        L.append(int(line))
    fin.close()
    for i in range(1,5):
        L2 = []
        tree = RBTree()
        n = 20 * i
        str2 = str(n)
        time_start = time.time()
        time_start1 = time.time()
        for j in range(0,n):
            if(j%10 == 0 and j>0):
                time_end = time.time()
                L2.append(time_end-time_start)
                time_start = time.time()
            tree.insert(L[j])
        time_end = time.time()
        time_end1 = time.time()
        L2.append(time_end - time_start)
        L2.append(time_end1 - time_start1)
        L1 = []
        tree.preoreder(tree.root)
        str3 = "/preoreder.txt"
        str4 = str1 + str2 + str3
        fout = open(str4, 'w')
        for j in range(0, n):
            fout.write(str(L1[j]).strip().encode('utf-8') + '\n')
        fout.close()

        L1 = []
        tree.inoreder(tree.root)
        str3 = "/inoreder.txt"
        str4 = str1 + str2 + str3
        fout = open(str4, 'w')
        for j in range(0, n):
            fout.write(str(L1[j]).strip().encode('utf-8') + '\n')
        fout.close()

        L1 = []
        tree.postoreder(tree.root)
        str3 = "/postoreder.txt"
        str4 = str1 + str2 + str3
        fout = open(str4, 'w')
        for j in range(0, n):
            fout.write(str(L1[j]).strip().encode('utf-8') + '\n')
        fout.close()

        str4 = str1 + str2 + "/time1.txt"
        fout = open(str4, 'w')
        p = len(L2)
        for j in range(0, p):
            fout.write(str(L2[j]).strip().encode('utf-8') + '\n')
        fout.close()



