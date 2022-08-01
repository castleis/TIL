# 인접리스트로 구현
"""
O(d(v))
1. 어떤 정점 v에 대해 인접한 모든 노드를 탐색 
    -> 해당 정점을 인덱스로 삼아 해당되는 연결리스트를 통해 순회하므로 모든 정점을 조사할 필요 없이 해당 정점의 인접한 정점들만 조사
2. 정점 u에 대해 (u,v)가 E(G)에 속하는지 검사
    -> 해당 정점을 인덱스로 연결리스트를 가져와 인접한 모든 노드를 순회해야 함.
"""
class Graph_list:
    def __init__(self, vertex_num = None):
        self.vtx_num = 0 # 정점의 개수
        self.adj_list = [] # 인접 리스트
        self.vtx_arr = [] # 정점의 존재 여부 : 있다면 True, 없다면 False
        """
        vtx_arr가 필요한 이유 : 
        delete_vertex() 메서드로 도중에 있던 정점이 사라질 수 있기 때문에 필요.
        정점을 삭제할 때마다 뒤에 있는 모든 정점을 한칸씩 당긴다면 효율적이지 못하기 때문에
        delete 메서드를 호출할 때 실제로 삭제하지 않고 삭제할 정점의 인덱스만 비활성화
        """
        if vertex_num: #vertex_num(정점의 개수)을 매개변수로 넘기면 초기화 진행
            self.vtx_num = vertex_num
            self.adj_list = [[] for _ in range(self.vtx_num)] #배열의 요소로 연결리스트 대신 동적배열 사용
            self.vtx_arr = [True for _ in range(self.vtx_num)]
    
    def is_empty(self):
        if self.vtx_num == 0:
            return True
        return False
    
    # 정점을 추가하고 정점 인덱스 반환
    def add_vertex(self): # 모든 정점을 순회하면서 비활성화된 정점이 있다면 사용, 모두 사용중이라면 정점을 추가
        for i in range(len(self.vtx_arr)):
            if self.vtx_arr[i] == False: # i 번째 인덱스 정점이 삭제된 정점인 경우 (False인 경우)
                self.vtx_num += 1
                self.vtx_arr[i] = True
                return i

        self.adj_list.append([]) #삭제된 정점이 없다면 정점을 하나 추가
        self.vtx_num += 1
        self.vtx_arr.append(True)
        return self.vtx_num-1
    
    #정점 v 삭제
    def delete_vertex(self, v):
        if v >= self.vtx_num:
            raise Exception(f'There is no vertex of {v}')

        if self.vtx_arr[v]: #정점 v가 존재하면
            self.adj_list[v] = [] #정점 v의 인접 정점 집합을 초기화
            self.vtx_num -= 1
            self.vtx_arr[v] = False # 정점 v 삭제

            for adj in self.adj_list: # 나머지 정점 중 v와 인접한 정점이 있다면
                for vertex in adj: #2중 루프를 돌면서 해당 정점과 이어져있던 에지들 삭제
                    if vertex == v:
                        adj.remove(vertex) # 인접한 정점의 리스트에서 v 제거
    
    def add_edge(self,u,v): # 인접 리스트의 각 정점 마지막 요소에 에지 추가
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)

    def delete_edge(self,u,v): # 해당 정점(동적배열)의 요소 삭제
        self.adj_list[u].remove(v)
        self.adj_list[v].remove(u)

    def adj(self,v): # 해당 정점 v에 인접한 모든 노드 집합을 리스트로 반환
        return self.adj_list[v]


# 인접행렬로 구현 BFS
"""
행 : 정점 / 열 : 자신을 포함한 다른 정점
1. 어떤 정점 v에 대해 인접한 모든 노드를 탐색 : v행에 대하여 모든 열 탐색
2. (u,v)가 있는지 여부를 확인하는 연산 : adj_matrix[u][v] 확인
"""
from queue import Queue
class Graph_matrix:
    def __init__(self, vertex_num):
        self.adj_list = [[] for _ in range(vertex_num)]
        self.visited = [False for _ in range(vertex_num)] #정점의 방문 여부 확인
    
    def add_edge(self, u, v):
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)
    
    def init_visited(self): #방문 리스트를 초기화하기 위한 메서드
        for i in range(len(self.visited)):
            self.visited[i] = False

    def bfs(self,v):
        q = Queue()
        self.init_visited() #방문 체크리스트 초기화

        q.put(v) #첫번째 정점을 큐에 넣음
        self.visited[v] = True #첫번째 정점 방문

        while not q.empty(): #q가 비어있지 않는 동안
            v = q.get() #이미 방문한 정점을 dequeue로 front값을 pop하면서 그 값을 다음 정점으로 선정

            print(v, end='=')
            adj_v = self.adj_list[v] # 방문한 정점의 인접 정점 리스트
            for u in adj_v:
                if not self.visited[u]: #인접 정점을 방문하지 않았다면
                    q.put(u) # 해당 정점을 큐에 넣음
                    self.visited[u] = True # 해당 정점 방문