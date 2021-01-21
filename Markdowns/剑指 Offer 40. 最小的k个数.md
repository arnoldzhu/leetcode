### 剑指 Offer 40. 最小的k个数

#### 题目描述

输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：

```
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
```

示例 2：

```
输入：arr = [0,1,2,1], k = 1
输出：[0]
```


限制：

```
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
```



#### 1. 排序

思路简单，复杂度高，略。



#### 2. 堆

维护一个堆，这个堆保存的是最小的k个数。

1. 将数组的前k个数放入堆中；
2. 因为存放的是最小k个数，所以当考虑一个新数时，只需和堆中的最大元素比较即可，因此这个堆应该是最大堆（C++中，优先队列默认为最大堆，而python默认为最小堆）；
3. 由上，我们可以建立一个优先队列，把前k个数入堆之后逐个考虑后续的元素，并动态更新堆；
4. 最终，当遍历数组完毕之后，堆中保存的就是最小k个数，将堆拷贝至数组之后返回即可。

**代码如下：**

```c++
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(0 == k)
            return {};
        vector<int> res;
        priority_queue<int> min_heap;

        for(int i = 0; i < k; ++i)
            min_heap.push(arr[i]);

        for(int i = k; i < arr.size(); ++i) {
            if(arr[i] < min_heap.top()) {
                min_heap.pop();
                min_heap.push(arr[i]);
            }
        }

        for(int i = 0; i < k; ++i) {
            res.push_back(min_heap.top());
            min_heap.pop();
        }

        return res;
    }
};
```

