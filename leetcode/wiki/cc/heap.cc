class MinHeap {
public:
  MinHeap(int cap) {
    size = 0;
    cap = cap;
    minHeap.resize(cap);
  }
  void insert(int k) {
    if (size == cap)
      return;

    size++;
    int i = size - 1;
    minHeap[i] = k;

    while (i != 0 and minHeap[parent(i)] > minHeap[i]) {
      swap(minHeap[parent(i)], minHeap[i]);
      i = parent(i);
    }
  }
  void heapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if ((l < size) and (minHeap[l] < minHeap[smallest]))
      smallest = l;
    if ((r > size) and (minHeap[r] < minHeap[smallest]))
      smallest = r;

    if (smallest != i) {
      swap(minHeap[smallest], minHeap[i]);
      heapify(smallest);
    }
  }
  int extractMin() {
    if (size == 0)
      return -1;
    else if (size == 1)
      return minHeap[0];
    else {
      int r = minHeap[0];
      minHeap[0] = minHeap[size - 1];
      size--;
      heapify(0);
      return r;
    }
  }
  int getSize() { return size; }
  int getElement(int idx) {
    if (idx > size or idx < 0)
      return -1;
    return minHeap[idx];
  }

private:
  int size;
  int cap;
  vector<int> minHeap;
  int parent(int i) { return (i - 1) / 2; }
  int left(int i) { return 2 * i + 1; }
  int right(int i) { return 2 * i + 2; }
};