class Solution {
public:
          
    void help(vector<vector<int>>& image, vector<vector<bool>>& visited, int& nrows, int& ncols, int r, int c, int& newColor, int& targetColor) {    
        
        if(r < 0 || r >= nrows || c < 0 || c >= ncols || visited[r][c] == true) 
        {
            return;
        }                
        if(image[r][c] == targetColor) 
        {            
            image[r][c] = newColor;
            visited[r][c] = true;
            help(image, visited, nrows, ncols, r + 1, c, newColor, targetColor);
            help(image, visited, nrows, ncols, r - 1, c, newColor, targetColor);
            help(image, visited, nrows, ncols, r, c + 1, newColor, targetColor);
            help(image, visited, nrows, ncols, r, c - 1, newColor, targetColor);
        }        
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int targetColor = image[sr][sc];
        int nrows = image.size();
        int ncols = image[0].size();
        vector<vector<bool>> visited(nrows, vector<bool>(ncols, false));
        help(image, visited, nrows, ncols, sr, sc, newColor, targetColor);
        return image;
    }
};
