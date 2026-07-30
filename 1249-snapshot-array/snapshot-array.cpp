class SnapshotArray {
public:
    vector<map<int, int>> arr;
    int snapid;

    SnapshotArray(int length) {
        arr.resize(length);
        snapid = 0;
    }

    void set(int index, int val) {
        arr[index][snapid] = val;
    }

    int snap() {
        return snapid++;
    }

    int get(int index, int snap_id) {
        auto it = arr[index].upper_bound(snap_id);
        if (it == arr[index].begin()) {
            return 0;
        }
        --it;
        return it->second;
    }
};