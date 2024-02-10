class Solution {
public:
    void nextElement(vector<int> heights, vector<int>& nextElem) {
        stack<int> stack;
        stack.push(-1);
        for (int i = heights.size() - 1; i >= 0; i--) {
            int element = heights[i];
            while (stack.top()!=-1&&heights[stack.top()] >= element) {
                stack.pop();
            }
            nextElem[i] = stack.top();
            stack.push(i);
        }
    }

    void prevElement(vector<int> heights, vector<int>& prevElem) {
        stack<int> stack;
        stack.push(-1);
        for (int i = 0; i < heights.size(); i++) {
            int element = heights[i];
            while (stack.top()!=-1&&heights[stack.top()] >= element) {
                stack.pop();
            }
            prevElem[i] = stack.top();
            stack.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextElem(heights.size()); 
        vector<int> prevElem(heights.size());
        int area;
        nextElement(heights, nextElem);
        prevElement(heights, prevElem);
        int finalarea = INT_MIN;
        for (int i = 0; i < heights.size(); i++) {
            if(nextElem[i]==-1){
                nextElem[i]=heights.size();
            }
            int width = nextElem[i]-prevElem[i]-1;
            int area = heights[i]* width;
            finalarea = max(area,finalarea);
        }
        return finalarea;
    }
};
