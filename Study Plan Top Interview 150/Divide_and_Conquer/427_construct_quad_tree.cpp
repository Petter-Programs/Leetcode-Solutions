/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* div_and_conq(vector<vector<int>>& grid, int start_row, int end_row, int start_col, int end_col)
    {
        Node* curr = new Node();
        curr->val = grid[start_row][start_col];

        int number = grid[start_row][start_col];
        for(int i = start_row; i<end_row; ++i)
        {
            for(int j = start_col; j<end_col; ++j)
            {
                if(grid[i][j] != number)
                {
                    curr->topLeft = div_and_conq(grid, start_row, (start_row+end_row)/2, start_col, (start_col+end_col)/2);
                    curr->topRight = div_and_conq(grid, start_row, (start_row+end_row)/2, (start_col+end_col)/2, end_col);
                    curr->bottomLeft = div_and_conq(grid, (start_row+end_row)/2, end_row, start_col, (start_col+end_col)/2);
                    curr->bottomRight = div_and_conq(grid, (start_row+end_row)/2, end_row, (start_col+end_col)/2, end_col);
                    return curr;
                }
                    
            }
        }

        curr->isLeaf = true;
        return curr;

    }
public:
    Node* construct(vector<vector<int>>& grid) 
    {
        // divide into 4 sections
        // evaluate our section:
        // if all same value, create a leaf node
        // if not, divide again into 4 sections
        // etc.

        // from conditions we can tell that
        // the matrix will be nicely divisible into 4
        
        return div_and_conq(grid, 0, grid.size(), 0, grid.size());
    }
};