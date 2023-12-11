from math import log2, ceil
n = int(input())
nums = list(map(int, input().split()))
coord_comp = {}
nums_sorted = sorted(nums)
n = len(nums)
last_use = 0
for i in nums_sorted:
    if i in coord_comp: continue
    coord_comp[i] = last_use
    last_use += 1

class SegmentTree:
    def __init__(self, n, arr=None):
        true_n = 1 << (ceil(log2(n)) + 1)
        self.n = n
        self.st = true_n >> 1
        self.segtree = [float('-inf')] * true_n
        if arr:
            for i in range(n):
                self.segtree[self.st + i] = arr[i]

            for i in range(self.st - 1, 0, -1):
                self.segtree[i] = max(self.segtree[i << 1], self.segtree[(i << 1) + 1])

    def query(self, i, j=None):
        i += self.st;
        if not j: j = i
        else: j += self.st
        ans = float('-inf')
        while i <= j:
            if i & 1:
                ans = max(ans, self.segtree[i])
                i += 1
            if not j & 1:
                ans = max(ans, self.segtree[j])
                j -= 1
            i >>= 1;
            j >>= 1;
        return ans

    def update(self, i, val):
        i += self.st
        self.segtree[i] = val
        i >>= 1
        while i:
            self.segtree[i] = max(self.segtree[i << 1], self.segtree[(i << 1) + 1])
            i >>= 1

    def __len__(self): return self.n

s = SegmentTree(last_use, [0] * last_use)
for i in nums:
    if coord_comp[i] == 0:
        s.update(coord_comp[i], 1)
        continue
    k = s.query(0,coord_comp[i]-1)
    s.update(coord_comp[i], max(s.query(coord_comp[i]), 1 + k))

print(s.query(0,len(s)-1))
