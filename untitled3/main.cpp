#include <iostream>
#include<queue>
#include<cassert>
using namespace std;

//二分查找法，有序数组中查找target
//找到target返回index
//没有找到返回-1
template <typename T>
int binarySearch(T arr[],int n,T target){
    //在arr[l,r]之间查找target
    int l=0,r=n-1;
    while(l<=r){
        //mid=(r+l)/2;
        int mid=l+(r-l)/2;
        if(arr[mid]==target)
            return mid;
        if(target<arr[mid])
            r=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

template <typename Key,typename Value>
class BST{
            private:

            struct Node{
                Key key;
                Value value;
                Node*left;
                Node*right;
                Node(Key key,Value value){
                    this->key=key;
                    this->value=value;
                    this->left=this->reght=NULL;
                }
                Node(Node* node){
                    this->key=node->key;
                    this->value=node->value;
                    this->left=node->left;
                    this->right=node->right;
                }
            };
            Node*root;
            int count;
        public:
            BST(){
                root=NULL;
                count=0;
            }
            ~BST(){
                destroy(root);
            }
            int size(){
                return count;
            }
            bool isEmpty(){
                return count==0;
            }
            void insert(Key key,Value value){
                root=insert(root,key,value);
            }
            bool contain(Key key){
                return contain(root,key);
            }
            Value* search(Key key){
                return search(root,key);
            }
            //前序遍历
            void preOrder(){
                preOrder(root);
            }
            //中序遍历
            void inOrder(){
                inOrder(root);
            }
            //后序遍历
            void postOrder(){
                postOrder(root);
            }
            //层序遍历
            void levelOrder(){
                queue<Node*>q;
                q.push(root);
                while(!q.empty()){
                    Node*node=q.front();
                    q.pop();
                    cout<<node->key<<endl;
                    if(node->left)
                        q.push(node->left);
                    if(node->right)
                        q.push(node->right);

                }
            }
            //寻找最小值
            Key mininum(){
                assert(count!=0);
                Node*minNode=mininum(root);
                return minNode->key;
            }
            //寻找最大值
            Key maxnum(){
                assert(count!=0);
                Node*maxNode=maxnum(root);
                return maxNode->key;
            }
            //删除二分搜索树中的最小key
            void removeMin(){
                if(root)
                    root=removeMin(root);
            }
            //删除二分搜索树中的最大key
            void removeMax(){
                if(root)
                    root=removeMax(root);
            }
            //从二分搜索树中删除key值为key的节点
            void remove(Key key){
                root=remove(root,key);
            }


private:
            //向以Node为根的二叉搜索树中插入节点（key，value）
            //返回插入新节点的二叉搜索树的根
            Node* insert(Node*node,Key key,Value value){
                if(node==NULL){
                    count++;
                    return new Node(key,value);
                }
                if(key==node->key)
                    node->value=value;
                else if(key<node->key)
                    node->left=insert(node->left,key,value);
                else
                    node->right=insert(node->right,key,value);
                return node;
            }
            //查看以node为根的节点是否包含key值为key的节点
            bool contain(Node*node,Key key){
                if(node==NULL)
                    return false;
                if(key==node->key)
                    return true;
                else if(key<node->key)
                    return contain(node->left,key);
                else
                    return contain(node->right,key);
            }
            Value* search(Node*node,Key key){
                if(node==NULL)
                    return NULL;
                if(key==node->key)
                    return &(node->value);
                else if(key<node->key)
                    return search(node->left,key);
                else
                    return search(node->right,key);
            }
            void preOrder(Node*node){
                if(node!=NULL){
                    cout<<node->key<<endl;
                    preOrder(node->left);
                    preOrder(node->right);
                }
            }
            void inOrder(Node*node){
                if(node!=NULL){
                    inOrder(node->left);
                    cout<<node->key<<endl;
                    inOrder(node->right);
                }
            }
            void postOrder(Node*node){
                postOrder(node->left);
                postOrder(node->right);
                cout<<node->key<<endl;
            }
            void destroy(Node*node){
                if(node!=NULL){
                    destroy(node->left);
                    destroy(node->right);
                    delete node;
                    count--;
                }
            }
            Node*mininum(Node*node){
                if(node->left==NULL)
                    return node;
                return mininum(node->left);
            }
            Node*maxnum(Node*node){
                if(node->right==NULL)
                    return node;
                return maxnum(node->right);
            }
            Node* removeMin(Node*node){
                if(node->left==NULL){
                    Node* rightNode=node->right;
                    delete node;
                    count--;
                    return rightNode;
                }
                node->left=removeMin(node->left);
                return node;
            }
            Node*removeMax(Node*node){
                if(node->right==NULL){
                    Node*rightNode=node->right;
                    delete node;
                    count--;
                    return rightNode;
                }
                node->right=removeMax(node->right);
                return node;
            }
            Node*remove(Node*node,Key key){
                if(node==NULL)
                    return NULL;
                if(key<node->key){
                    node->left=remove(node->left,key);
                }
                else if(key>node->key){
                    node->right=remove(node->right,key);
                }
                else{//key==node->key
                    if(node->left==NULL){
                        Node*rightNode=node->right;
                        delete node;
                        count--;
                        return rightNode;
                    }
                    if(node->right==NULL){
                        Node*leftNdoe=node->left;
                        delete node;
                        count--;
                        return leftNdoe;
                    }
                    //node->left!=NULL&&node->right!=NULL
//                    Node *delNode=node;
                    Node *successor=new Node(mininum(node->right));
                    count++;
                    successor->right=removeMin(node->right);
                    successor->left=node->left;
//                    delete delNode;
                    delete node;
                    count--;
                    return successor;
                }
            }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}