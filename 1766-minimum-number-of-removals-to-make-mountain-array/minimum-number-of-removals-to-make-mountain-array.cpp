class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n = arr.size();
        vector<int> increasingSubsequence(n, 1);
        vector<int> decreasingSubsequence(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (arr[j] < arr[i]) {
                    increasingSubsequence[i] = max(
                        increasingSubsequence[i], 1 + increasingSubsequence[j]);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (arr[j] < arr[i]) {
                    decreasingSubsequence[i] = max(
                        decreasingSubsequence[i], 1 + decreasingSubsequence[j]);
                }
            }
        }
        // for (int i = 0; i < n; i++) cout << increasingSubsequence[i] << " ";
        // cout << endl;
        // for (int i = 0; i < n; i++) cout << decreasingSubsequence[i] << " ";
        int ans = 0,prevEle = 0;
        int increasingSubsequenceLenght = increasingSubsequence[0],
            maxMountainSeqeunceLenght = 0;

        for (int i = 0; i < n - 1; i++) {
            int decreasingSubsequenceLenght = 0;
            
            if (increasingSubsequence[i] >= increasingSubsequenceLenght) {
                if (increasingSubsequenceLenght == increasingSubsequence[i]) {
                    if (arr[prevEle] < arr[i])
                        prevEle = i;
                    continue;
                }
                increasingSubsequenceLenght =
                    max(increasingSubsequenceLenght, increasingSubsequence[i]);
                prevEle = i;
            }
            // if(increasingSubsequence[i] < increasingSubsequenceLenght) continue;
            
            if (increasingSubsequenceLenght == 1)
                continue;
            for (int j = i + 1; j < n; j++) {
                if (arr[prevEle] > arr[j]) {
                    // cout<<arr[prevEle]<<" "<<arr[j]<<" "<<endl;
                    decreasingSubsequenceLenght = max(
                        decreasingSubsequenceLenght, decreasingSubsequence[j]);
                }
            }
            if (decreasingSubsequenceLenght)
                maxMountainSeqeunceLenght = max(
                    maxMountainSeqeunceLenght,
                    increasingSubsequenceLenght + decreasingSubsequenceLenght);
            // cout<<maxMountainSeqeunceLenght<<endl;
        }
        return n - maxMountainSeqeunceLenght;
    }
};