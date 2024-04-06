import heapq

class Solution:
    def shortestPath(self, n: int, edges: list[list[int]], src: int) -> dict[int, int]:
        adj = {}
        for i in range(n):
            adj[i] = [] #สร้างจุดแต่ละจุดแล้วให้เป็นเซตว่าง โดย {จุด: [],จุด: []}

        for s, dst, weight in edges: #dst เป็น index ของ list adj 
            adj[s].append([dst, weight]) #ลูปเพื่อหาจุดใกล้เคียงว่ามีกี่จุดแล้วให้ append [] ตามจำนวนจุดใกล้เคียงที่เจอ ใกล้จุด 0 มี 1 กับ 2 สร้าง [] มา 2 อัน

        shortest = {}  # Map vertex -> dist of shortest path
        minHeap = [[0, src]]
        #(minHeap) ตอนแรกเปน [[0, 0]]
        while minHeap:
            current_dist, current_node = heapq.heappop(minHeap) #[ระยะทาง, จุดปลาย] โดยรันแล้วเลือกเส้นทางที่ส้นที่สุดที่จะไปถึงจุดนั้นจากการใช้ heappop ระยะทีสั้นสุดจะถูก pop ออกไป
            if current_node in shortest:
                continue
            shortest[current_node] = current_dist #บันทึกจุดกับขนาดเส้นไว้ใน shortest โดยถ้ามีจุดนี้อยู่ใน shortest แล้ว ให้ข้ามไปทำลูปต่อไป

            for neighbor, neighbor_dist in adj[current_node]: #neighbor ของ current node ex.current node is 0 so, neighbor is 1,2 ตามด้วย dist_neighbor
                if neighbor not in shortest:
                    heapq.heappush(minHeap, [current_dist + neighbor_dist, neighbor]) #เอาระยะทางที่สั้นที่สุดบวกกับระยะทางไปจุดใกล้เคียง ไล่เช้คจากทุกจุดใกล้ 0 แล้วค่อยไปจุดอื่น

        for i in range(n): # n=5
            if i not in shortest:
                shortest[i] = -1

        # Print the shortest distances
        for vertex, distance in shortest.items():
            print(f"Shortest distance from {src} to {vertex} is {distance}")

        print(shortest)

        return shortest

# Testcase
solution = Solution()
n = 5
edges = [[0, 1, 2], [0, 2, 4], [1, 2, 1], [1, 3, 7], [2, 3, 3], [2, 4, 5], [3, 4, 2]]
src = 0

result = solution.shortestPath(n, edges, src)
