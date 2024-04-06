#graph = {
#  'a': {'b': 1, 'c': 2, 'd': 3},
#  'b': {'a': 1, 'c': 5},
#  'c': {'a': 2, 'b': 5, 'd': 5, 'e': 5, 'f': 2, 'g': 4},
#    'd': {'a': 3, 'c': 5, 'g': 4},
#   'e': {'b': 3, 'c': 5, 'f': 3, 'h': 2},
#   'f': {'c': 2, 'e': 3, 'g': 4, 'h': 1},
#   'g': {'c': 4, 'd': 4, 'f': 4, 'h': 2},
#   'h': {'e': 2, 'f': 1, 'g': 2, "i": 5, 'j': 5, 'k': 3},
#   'i': {'h': 5, 'k': 4},
#   'j': {'h': 5, 'k': 3},
#   'k': {'h': 3, 'i': 4, 'j': 3}
#}
graph = {
    'S': {'A':2, 'B':5, 'C':3},
    'A': {'B':2, 'D':6},
    'B': {'D':3, 'F':6},
    'C': {'B':2, 'F':7},
    'D': {'E':3, 'T':6},
    'E': {'T':2},
    'F': {'E':3, 'T':2},
    'T': {}
}


def djikstra(graph, start, end):
    shortways = {}  # ทางที่สั้นที่สุดจากจุดเริ่มต้นถึงจุดๆนึง
    back = {}  # ทางที่มา
    unseenNodes = graph  # จุดที่ยังไม่ได้ไป
    inf = float('inf')  # ค่าinfinity
    path = []  # ทางที่เคยผ่านไปแล้ว

    # สร้างways ให้เป็น infinity เพื่อมาแก้ไขหาค่าน้อยสุเ
    for node in unseenNodes:
        shortways[node] = inf   #กำหนดให้ทุกค่าเป็น inf 
        shortways[start] = 0    #กำหนดให้จุดเริ่มต้น เป็น 0

    while unseenNodes:  #ลูปทุกตัวที่ยังไม่ไป
        mindis = None
        for node in unseenNodes:
            if mindis is None or shortways[node] < shortways[mindis]:
                mindis = node   #กำหนดระยะทางจากจุดเริ่มต้นถึงจุดๆนึงที่มีค่าน้อยที่สุด
        pdict = graph[mindis].items()   #ให้pdictเป็นจุดต่อไปที่สามารถไปได้ในจุดนั้นๆ

        # เช็คระยะทาง
        for node1, w in pdict:
            if w + shortways[mindis] < shortways[node1]:    #ถ้าระยะทางจาก start ถึง จุด misdis ผ่านจุด w แล้วน้อยกว่าไปทางอื่น
                shortways[node1] = w + shortways[mindis]    #ให้ผ่าน w สั้นกว่า
                back[node1] = mindis    #เก็บค่า back ของ node1 เช่น b มาจาก a
        unseenNodes.pop(mindis) #popตัวนั้นออกจากunseennode เพราะส่าเป็นตัวที่หาแล้วว่าไปทางไหนสั้นสุด

    now = end   #now เป็นตัว end ของกราฟ
    while now != start:
        try: 
            path.insert(0, now) #ใส่ตัวสุดท้ายลงไปใน path
            now = back[now]     #ย้อนกลับไปหาตัว back ของnow
        except KeyError:
            print('no path')
            break
        
    path.insert(0, start)   #insert start ไปที่ตัวแรกของลิสต์
    if shortways[end] != inf:
        print(str(shortways[end]) + " " + (str(path)))  #print ระยะทางที่สั้นที่สุดตั้งอต่จุดเริ่มต้นถึงจุดจบ และเส้นทาง


djikstra(graph, 'S', 'T')