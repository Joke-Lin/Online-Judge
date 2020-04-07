# PAT Advanced 题目

> 题目考点以及基础坑点总结

1. [1003 Emergency（最短路）](https://joke-lin.top/2020/02/24/2020-02-24-PAT-Advanced-1003/)

2. [1010 Radix（二分法）](https://joke-lin.top/2020/03/19/2020-03-19-PAT-Advanced-1010/)

3. [1012 The Best Rank（排序）](https://joke-lin.top/2020/03/21/2020-03-21-PAT-Advanced-1012/)

	需要四舍五入，以及并列排名：1 1 3 4 5 这种（没有第二名了就）

4. [1014 Waiting in Line（优先队列）](https://joke-lin.top/2020/03/21/2020-03-24-PAT-Advanced-1014/)

	17：00后的不予服务，只要在17：00之前接受服务的都可以，不用管截止时间。

5. [1016 Phone Bills（排序）](https://joke-lin.top/2020/03/27/2020-03-27-PAT-Advanced-1016/)

	没有符合条件的时间对时，不输出该用户信息。。

6. [1017 Queueing at Bank（优先队列）](https://joke-lin.top/2020/03/29/2020-03-29-PAT-Advanced-1017/)

	17：00之后不能被服务，17：00 是到达时间。。不是服务时间，服务时间不能超过1小时是指大于1小时的按一小时处理，而不是不处理

7. [1018 Public Bike Management（Dijkstra + DFS）](https://joke-lin.top/2020/03/31/2020-03-31-PAT-Advanced-1018/)

	在计算携带数量和带回数量的时候需要考虑先后关系，即后面多余的车不能补充前面的。

8. [1020 Tree Traversals （二叉树）](https://joke-lin.top/2020/04/01/2020-04-01-PAT-Advanced-1020/)

9. [1021 Deepest Root （连通分量+树的直径）](https://joke-lin.top/2020/04/03/2020-04-03-PAT-Advanced-1021/)

10. 1022 Digital Library（Map的使用）

	注意数据的保存，id保存为int的时候注意输出任然是7位，据说year可能超出题目限定的范围，所以都用string保存的好。。

