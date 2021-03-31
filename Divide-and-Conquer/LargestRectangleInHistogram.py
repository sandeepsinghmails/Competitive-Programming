class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack_heights = deque()
        stack_pos     = deque()
        
        max_area      = 0
        curr_index    = 0
        height        = 0        
        
        for index in range(len(heights)):
            if (not stack_heights or stack_heights[0]<heights[index]):
                stack_pos.appendleft(index)
                stack_heights.appendleft(heights[index])
                
            elif stack_heights[0]>heights[index]:
                while (stack_heights and stack_heights[0] > heights[index]):
                    curr_index  = stack_pos.popleft()
                    height      = stack_heights.popleft()
                    
                    max_area    = max(max_area, 
                                      height * (index-curr_index))
                    
                stack_heights.appendleft(heights[index]);
                stack_pos.appendleft(curr_index);
                
        while stack_heights:
            curr_area = stack_heights[0] * (len(heights) - stack_pos[0])
            stack_heights.popleft()
            stack_pos.popleft()
            
            max_area = max(curr_area, max_area)
        
        return max_area
