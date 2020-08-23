class Solution
{
public:
    int length[100005];
    int count[100005];
    int findLatestStep(vector<int> &arr, int m)
    {
        int ans = -1;
        int n = arr.size();

        for (int j = 0; j < arr.size(); j++)
        {
            int i = arr[j];
            int left = length[i - 1];
            int right = length[i + 1];

            int curr = left + right + 1;

            count[left]--;
            count[right]--;
            count[curr]++;
            if (count[m] > 0)
            {
                ans = j + 1;
            }
            length[i] = length[i - left] = length[i + right] = curr;
        }
        return ans;
    }
};