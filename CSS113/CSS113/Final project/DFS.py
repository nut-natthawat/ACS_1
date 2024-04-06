# Python3 program to print DFS traversal
from collections import defaultdict
class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
    def addEdge(self, u, v):     # เพิ่มเส้นกราฟแต่ละจุด
        self.graph[u].append(v)

    def DFSUtil(self, v, visited):
        visited.add(v)  # add node ตัวที่ตรวจแล้วใน visited และ print
        print(v, end=' ')
        for neighbour in self.graph[v]:   #loop ตัวที่ติดกับ node V 
            if neighbour not in visited: # check ตัวที่ติดมีอยู่ใน visited หรือยัง
                self.DFSUtil(neighbour, visited) # ถ้ายังไม่มี ก็ใช้functionอีกรอบ
    def DFS(self, v):
        visited = set() #สร้างตัวแปรเก็บค่าที่ตรวจแล้ว
        self.DFSUtil(v, visited) #call function หา DFS
if __name__ == "__main__":  
    g = Graph()         #เพิ่มเส้นกราฟ by call function addedge
    g.addEdge(0, 1)
    g.addEdge(0, 2)
    g.addEdge(1, 2)
    g.addEdge(2, 0)
    g.addEdge(2, 3)
    g.addEdge(3, 3)
    start_vertex = int(input("Enter vertex to start "))
    print("Following is DFS from (starting from vertex",start_vertex,")")
    g.DFS(start_vertex) # call function DFS โดยเริ่มที่vertex 2
