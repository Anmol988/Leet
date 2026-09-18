class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;

        while (left < right) {
            // Water capacity is constrained by the shorter line
            int current_height = min(height[left], height[right]);
            int current_width = right - left;
            int current_area = current_height * current_width;

            max_water = max(max_water, current_area);

            // Move the pointer corresponding to the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};

