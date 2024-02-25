s Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int,int> map;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto it = q.front();
                q.pop();
                Node *node = it.first;
                int line = it.second;
                if(node->left!=nullptr){
                    q.push({node->left,line-1});
                }
                if(node->right!=nullptr){
                    q.push({node->right,line+1});
                }
                map[line] = node->data;
            }
        }
        vector<int> ans;
        for(auto it: map){
            ans.push_back(it.second);
        }
        return ans;
        // Your Code Here
    }
};
