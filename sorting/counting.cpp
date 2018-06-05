vector<int> countingSort(vector<int> arr) {
    vector<int> freq(100);
    do {
        freq[arr.back()]++;
        arr.pop_back();
    } while(!arr.empty());
    for(int i = 0; i < 100; i++) {
        while(freq[i]-- > 0)
            arr.push_back(i);
    }
    return arr;
}

