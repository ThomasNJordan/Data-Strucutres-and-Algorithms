// abstract TreeNode class

template <typename E>
class TreeNode{
public:
  E value;  // data value
  int key;  // key for comparison
  TreeNode* left; // left child tree node
  TreeNode* right;  // right hcild tree node

  TreeNode(){ // default
    key = 0;
    value = E();
    left = nullptr;
    right = nullptr;
  }
  TreeNode(E k, E v){ // overlaoded constructor
    key = k;
    value = v;
    left = nullptr;
    right = nullptr;
  }
  virtual ~TreeNode(){}
};
