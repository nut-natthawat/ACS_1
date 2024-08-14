INF = 9999999   #กำหนดเพื่อให้ทุกค่าน้อยกว่า inf
N = 11
G = [[0, 1, 2, 3, 0, 0 ,0 ,0 ,0 ,0 ,0],
     [1, 0, 3, 0, 4, 5, 0, 0, 0, 0, 0],
     [2, 3, 0, 5, 0, 2, 0, 0, 0, 0, 0],
     [3, 0, 5, 0, 0, 4, 5, 0, 0, 0, 0],
     [0, 4, 0, 0, 0, 3, 0, 4, 0, 0, 0],
     [0, 5, 2, 4, 3, 0, 3, 2, 3, 2, 0],
     [0, 0, 0, 5, 0, 3, 0, 0, 0, 4, 0],
     [0, 0, 0, 0, 4, 2, 0, 0, 5, 0, 4],
     [0, 0, 0, 0, 0, 3, 0, 5, 0, 4, 3],
     [0, 0, 0, 0, 0, 2, 4, 0, 4, 0, 4],
     [0, 0, 0, 0, 0, 0, 0, 4, 3, 4, 0]]


selected_node = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,]
sum = 0
no_edge = 0
o = str(input("enter your node ")) #input node ที่จะเริ่ม
selected_node[int(o)] = True    #กำหนดจุดเริ่มเปนจุดที่ input เข้ามา
print("Edge : Weight")
while (no_edge < N - 1):    #loop

    minimum = INF   # กำหนดให้minimunเป็น inf แปลว่าทำให้เส้นทางไหนๆก็น้อยกว่า inf
    a = 0 
    b = 0
    for m in range(N):  # loop วนทุกจุดในกราฟ
        if selected_node[m]: #check ว่า node เป็น True ไหม
            for n in range(N):  #loop หาทางที่น้อยที่สุดใน node นั้นๆ
                if ((not selected_node[n]) and G[m][n]): #check ว่าจุด n ยังไม่ถูกเลือกและมีเส้นทางที่เชื่อมละหว่างจุด m กับ n
                    if minimum > G[m][n]: 
                        minimum = G[m][n]       # เก็บค่าเส้นทางที่น้อยที่สุด
                        a = m
                        b = n
    print(str(a) + "->" + str(b) + ":" + str(G[a][b]))
    sum += int(G[a][b])
    selected_node[b] = True # เปลี่ยนจุดbเป็น True แปลว่าเป็นจุดที่ไปมาแล้ว
    no_edge += 1    # เอาไว้เก็บค่าเส้นทางที่เลือกไปแล้ว
print(sum)