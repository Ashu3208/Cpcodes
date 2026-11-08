
class SegmentTree {
    vector<long long> seg;
    int n;

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    // Build the segment tree
    void build(int idx, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;

        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    // Query sum in range [l, r]
    long long query(int idx, int low, int high, int l, int r) {
        // No overlap
        if (high < l || low > r)
            return 0;

        // Complete overlap
        if (low >= l && high <= r)
            return seg[idx];

        // Partial overlap
        int mid = low + (high - low) / 2;

        long long left = query(2 * idx + 1, low, mid, l, r);
        long long right = query(2 * idx + 2, mid + 1, high, l, r);

        return left + right;
    }

    // Point update: arr[pos] = val
    void update(int idx, int low, int high, int pos, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }

        int mid = low + (high - low) / 2;

        if (pos <= mid)
            update(2 * idx + 1, low, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, high, pos, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    // Public query function
    long long query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    // Public update function
    void update(int pos, int val) {
        update(0, 0, n - 1, pos, val);
    }
};
