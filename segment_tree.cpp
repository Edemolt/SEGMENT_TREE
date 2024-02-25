class SGTree{
public:
    vector<int> seg;
    
    SGTree(int n){
       seg.resize(4 * n + 1); 
    }
    
    void build(int node, int low, int high, int arr[]){
        if(low == high){
            seg[node] = arr[low];
            return;
        }
    
        int mid = (low + high)/2;
        build(2 * node + 1, low, mid, arr);
        build(2 * node + 2, mid+1, high, arr);
    
        seg[node] = min(seg[node * 2 + 1], seg[node * 2 + 2]);
    }

    int query(int node, int left, int right, int low, int high){
        // no overlap
        if(right < low || high < left) return 1e9;
        // complete high
        if(low >= left && right >= high) return seg[node];
    
        int mid = (low + high)/2;
        int l = query(node * 2 + 1, left, right, low, mid);
        int r = query(node * 2 + 2, left, right, mid + 1, high);
        return min(l, r);
    }

    void update(int node, int ind, int val, int low, int high){
        if(low == high){
            seg[ind] = val;
            return;
        }
        int mid = (low + high)/2;
        if(ind <= mid) update(2 * node + 1, ind, val, low, mid);
        else update(2 * node + 2, ind, val, mid + 1, high);
    }
};
