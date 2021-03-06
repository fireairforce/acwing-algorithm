## DFS 和 BFS 
DFS 不具备最短路的性质，BFS 能搜到最短的路径，DFS 的空间消耗是要比 BFS 少很多的。DFS 使用 stask，而 BFS 使用 queue.

DFS 里面重要的两个概念为回溯和剪枝。

每个 DFS 都对应这一条搜索树。常见的例题可以看相关文件。
DFS 要思考一下顺序，使用一个怎么样的顺序去做一个遍历的方案。DFS 在回溯的时候**系统会为我们维护一个栈结构的**，因此我们不需要再去开空间去记录路径。

BFS 能够搜到最短的路径。

宽搜的基本框架
```bash
queue <- 初始
while queue 不空 {
  队头 <- t
  拓展 t
}

```

## 树与图的遍历
在研究遍历之前，是需要先研究一下树与图是如何进行存储的。

树其实就是一种特殊的图 **(无环联通图)**。因此我们其实只用学习图相关即可。

图可以分为无向图和有向图。(边是否存在方向)，无向图在算法里面需要建立两条边(从a->b即b->a)。无向图其实是一种特殊的有向图。

有向图则分为两种，一种是领接矩阵 `g[a,b]` 表示从 a -> b，空间复杂度是 O(N^2)，一般用的比较少。
另外一种是 领接表 (则是单链表)，领接表存储有向图相当于在每个点上存一个链表(每个点上都存一个单链表，存储这个点可以达到哪些点)。

代码参考树的重心。

注意树和图的遍历每个点都只会走一遍，因此算法的时间复杂度其实就是 O(N+M),N为点的数目，M 为点的数目，成一个线性的关系。


## 拓扑排序
拓扑序列是图的宽搜的一种很基本的方法。

拓扑序列只存在于有向图中，无向图是不存在拓扑序列的。(拓扑这个词是英文释意)。

拓扑序列要求每条边，起点都在终点的前面，这样才能构成一个拓扑序列。

只要图中存在环，那是一定不会存在拓扑序列的，有向无环图(DAG，也被称为拓扑图)是一定存在拓扑序列的。

拓扑序列是非常容易求的，根据入度和出度去做一个计算就可以了。

拓扑排序中，所有入度为0的点，都是可以作为起点的(因为不会有任意一条边指向该点)。

```bash
// 如果图上存在环的话，那么就存在突破不掉的点放不进去队列里面(环无论怎么删，都存在入度不为0的点)
queue <-  入度为 0 的点(放入队列中)
while queue 不空 {
  t <- 队头
  枚举 t 的所有出边(例如 t -> j)
    删掉 t -> j (使j的入度(如果用 d[j] 表示，那就 d[j]--))
    if (d[j] === 0) {
      queue <- j // 删了之后把 j 这个点放在队列里面去
    }
}
```

## 最短路
图论问题种，N 表示点数，M 表示边数。
最短路问题分为单源最短路和多源汇最短路。(源点指的就是起点，汇点就是终点)。

单源求的是一个点到其他点的最短路。同时又可以分为所有边权都是正数的问题和存在负权边。

所有边权的都是正数可以分为两种算法去进行求解：朴素的 Dijkstra 算法(`O(N^2)`) 和 堆优化版的 Dijkstra 算法(`O(MlogN)`)。

朴素算法比较适合稠密图(边数比较多的情况)，稀疏图则适合堆优化版本的 Dijkstra 算法。

存在负权边也是有两种求解算法，分为 Bellman-Ford 算法(时间复杂度`O(NM)`)和 SPFA 算法(一般情况下是 O(M), 最坏情况是 `O(MN)`)。SPFA 算法实际上是 Bellman-Ford 算法的优化。

但如果限制了经过的边数(最多不超过 k 条边)，还是只能用贝尔曼算法。

多源汇最短路算法则只能使用经典的 Floyd 算法(时间复杂度是 O(N^3))。求的是多个起点到其他点的最短路(可以分为多组查询)。

最短路算法的难点不会让我们去证明算法的正确性，考察的是建图能力(如何把实际的问题转换成图论问题)。

### 朴素 Dijkstra

Dijkstra 求的是单源最短路。

先初始化距离
1. dist[1] = 0, dist[i] = ∞(把起始点到其他点的距离初始化为0，其他点初始化为无穷大)
2. for i : 0 ~ n (s 为当前已确定最短距离的点)
     t <- 不在 s 中点距离最近的点(例如 t)
     s <- t(把 t 加到 s 中去 )
     用 t 更新其他点距离

朴素 dijkstra 一般遍历的边会很多，因此存图的话一般使用领接矩阵来存(稠密图)，比较方便

dijkstra 算法其实并不难写.

具体代码可以参考 `dijkstra.cpp`。

### 堆优化的 dijkstra 
如果是一个稀疏图的话，就可以使用堆去优化一下 dijkstra.

```bash
for i : 0 ~ n (s 为当前已确定最短距离的点) n^2 -> n
     t <- 不在 s 中点距离最近的点(例如 t) n -> n 次 
     s <- t(把 t 加到 s 中去 ) n -> n 次
     用 t 更新其他点距离 m -> mlogn
```
使用堆的话可以把时间复杂度优化到 MlogN
如果使用堆去进行一个优化的话(即用堆去存储所有点到其他点的距离):

堆的写法可以手写或者使用优先队列(一般使用优先队列，不过这里可能没有自己手写的好，因为会存很多冗余的值)。

### Bellman-Ford 算法
实现上而言也比较简单，算法行数并不多

本质是迭代 n 次
bellman-ford 算法存边方式比较简单，甚至可以直接用结构体来存:
```cpp
struct {
  int a, b, w
} e[N];
```

```cpp
for n 次 
  for 所有边  a, b, w a -(w)-> b(遍历一次所有边)
  // 更新方式和 dijkstra 类似(这里的更新操作称之为松弛)
    dist[b] = min(dist[b], dist[a] + w);
```

bellman-ford 算法就是以上两行循环就结束了。循环完成之后 bellman-ford 算法证明了循环完 n 次之后，所有边一定满足 `dist[b] <= dist[a] + w` 恒成立，这个式子被称之为三角不等式。

bellman-ford 算法用于求用负权边的情况，如果存在负权回路的话，最短路是可能不存在的(即图里面有个环，环里面边权的和为负值，那么最短路可能会求出一个负无穷的值)。**bellman-ford 算法能求出是否存在负权回路的这种情况**。

不过一般找负环不用 bellman-ford 算法(时间复杂度比较高，一般使用 spfa 算法来判断是否存在负环)。

如果要使用 spfa 算法就一定不能要求有负环。

如果限制了经过边的数目，则只能使用 bellman-ford 算法.

### spfa 算法
spfa 算法本质上是对 bellman-ford 算法做了一次优化。

使用宽搜来做优化(迭代的时候使用一个队列来做优化。

```bash
queue <- 1
while queue 不空
  1. t <- q.front
    q.pop()
  2. 更新 t 的所有出边 t ->(w) b
    queue <- b
```

写法有点像 dijkstra.

一般 spfa 用不了的话，就可以换成堆优化的 dijkstra，一般最短路的算法都可以用 spfa 来求解。

spfa 算法求负环思路同 bellman-ford 算法，都是利用了抽屉原理的概念。

维护一个 cnt 数组用来表示到达点x所走的边数
如果这个 cnt 数组在某一个时刻，达到了 cnt[x] >=n，那么负环就判断出来了。
```
dist[x] 表示(1~x)最短距离
cnt[x] 当前最短路的边数 

每次更新的时候 dist[x] = dist[t] + w[i]
则 cnt[x] = cnt[t] + 1;
```

### floyd
floyd 算法用于求多源汇最短路。

使用领接矩阵来存图，一共三层循环。

d[i,j] 循环完之前是邻接矩阵

循环完之后 d[i, j] 表示点i 到j 的最短路
算法框架大致如下(比较简单):
```cpp
for (k = 1; k <= n; k ++) {
  for (i = 1; i <= n; i ++) {
    for (j = 1; j <= n; j ++) {
      d[i, j] = min(d[i, j], d[i, k] + d[k, j]);
    }
  }
}
```

## 最小生成树
最短路的问题一般就是上面一些算法和最小生成树问题。
最小生成树的问题对应的都是无向图，有向图的生成树问题都一般不会用到。

最小生成树分为两种算法，分别为普里姆算法(Prim) 和克鲁斯卡尔算法(Kruskal)

Prim 算法和 dijkstra 算法有些相似，也分为两种稀疏图(朴素版 Prim O(N^2))，稠密图(堆优化版 Prim, 时间复杂度为 O(mlogN)).

kruskal 算法的时间复杂度为 O(mlogm)，稀疏图会使用这个.

最小生成树问题因为不存在环，所以可以有负边。

### 朴素 Prim
```
dist[i] <- 无穷
for i = 0; i<n;i++ {
  t <- 找到集合外距离最近的点
  用 t 更新其他点到集合(与dijkstra的区别)的距离
}
```

堆优化堆 prim 算法基本不会写，一般都是 kruskal 算法。

### Kruskal
- 将所有边按权重从小到大排序(`O(mlogM)`)
- 枚举每一条边a, b, 权重 c
  if a, b 不连通
    将这条边加入集合中

然后就结束了

## 二分图
二分图分为染色法(`O(n + m)`)和 匈牙利算法 O(n*m),实际运行时间一般远小于 O(n*m)，这种类型的算法其实挺多(例如最大流算法).

