class Solution {
public:
    // Custom comparator to sort the stones based on the combined value for Alice and Bob
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] + a[1] > b[0] + b[1];
    }

    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();
        // Combine the values for Alice and Bob into a single vector
        vector<vector<int>> combined_vector(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            combined_vector[i][0] = a[i];
            combined_vector[i][1] = b[i];
        }

        // Sort the combined vector based on the sum of values
        sort(combined_vector.begin(), combined_vector.end(), cmp);

        int alice = 0, bob = 0;
        // Alternate picking stones between Alice and Bob
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                // Alice's turn
                alice += combined_vector[i][0];
            } else {
                // Bob's turn
                bob += combined_vector[i][1];
            }
        }

        // Determine the winner
        return alice > bob ? 1 : alice == bob ? 0 : -1;
    }
};