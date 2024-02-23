using namespace std;
#include <iostream>
#include <vector>
#include <numeric>
//KMP string matching
//Time:O(n)
//Space:O(n)
void kmp0dixed(string s, string p){
    //1-indexed
    //s is long text, p is pattern
    int m = p.size();
    int n = s.size();
    //compute next
    vector<int>ne(m, 0);
    ne[0] = -1;
    for(int i = 1, j=-1; i<m; i++){
        while(j>=0 && p[i] != p[j+1]) j = ne[j];
        if (p[i] == p[j+1]) j++;
        ne[i] = j;
    }

    //match
    for(int i=0, j=-1; i<n; i++){
        while(j>=0 && s[i] != p[j+1]) j = ne[j];
        if (s[i] == p[j+1]) j++;
        if(j == m-1){
            //matched
            printf("%d ", i - j);
            j = ne[j];
        }
    }

}

//Tire
class TrieNode {
    public:
    TrieNode* childNode[26];
    bool isVal;
    TrieNode(): isVal(false) {
        for (int i = 0; i < 26; ++i) {
            childNode[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;
    public:
    Trie(): root(new TrieNode()) {}
    // 向字典树插入一个词
    void insert(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!temp->childNode[word[i]-'a']) {
                temp->childNode[word[i]-'a'] = new TrieNode();
            }
            temp = temp->childNode[word[i]-'a'];
        }
        temp->isVal = true;
    }
 // 判断字典树里是否有一个词
    bool search(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!temp) {
                break;
            }
            temp = temp->childNode[word[i]-'a'];
        }
        return temp? temp->isVal: false;
    }
 // 判断字典树是否有一个以词开始的前缀
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for (int i = 0; i < prefix.size(); ++i) {
            if (!temp) {
                break;
            }
            temp = temp->childNode[prefix[i]-'a'];
        }
        return temp;
    }
};

//Union-Find
class UF {
    vector<int> id, size;
    public:
    UF(int n): id(n), size(n, 1){
        iota(id.begin(), id.end(), 0); // iota函数可以把数组初始化为0到n-1
    }

    int find(int p) {
        if (id[p] != p) id[p] = find(id[p]);
        return id[p];
    }

    void connect(int p, int q) {
        int i = find(p), j = find(q);
        if(i != j){
            if(size[i] < size[j]){
                id[i] = j;
                size[j] += size[i];
            }else{
                id[j] = i;
                size[i] += size[j];
            }
        }
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UF uf(n + 1);
        for (auto e: edges) {
            int u = e[0], v = e[1];
            if (uf.isConnected(u, v)) {
                return e;
            }
            uf.connect(u, v);
        }
        return vector<int>{-1,-1};
    }
};

//heap
class Heap{
    vector<int> heap;
    public:
    // 获得最大值
    int top() {
        return heap[0];
    }
    // 插入任意值：把新的数字放在最后一位，然后上浮
    void push(int k) {
        heap.push_back(k);
        up(heap.size()- 1);
    }
    // 删除最大值：把最后一个数字挪到开头，然后下沉
    void pop() {
        heap[0] = heap.back();
        heap.pop_back();
        down(0);
    }
    // 上浮
    void up(int pos) {
        while (pos/2 >= 0 && heap[pos/2] < heap[pos]) {
            swap(heap[pos/2], heap[pos]);
            pos /= 2;
        }
    }
    // 下沉
    void down(int pos) {
        while (2 * pos < heap.size()) {
            int i = 2 * pos;
            if (i < heap.size()-1 && heap[i] < heap[i+1]) ++i;
            if (heap[pos] >= heap[i]) break;
            swap(heap[pos], heap[i]);
            pos = i;
        }
    }
    // build heap O(n)
    void build(){
        for(int i = heap.size()/2; i>=0; i--) down(i);
    }
};

//BST
template <class T>
class BST {
    struct Node {
        T data;
        Node* left;
        Node* right;
    };
    Node* root;
    Node* makeEmpty(Node* t) {
        if (t == NULL) return NULL;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        return NULL;
    }
    Node* insert(Node* t, T x) {
        if (t == NULL) {
        t = new Node;
        t->data = x;
        t->left = t->right = NULL;
        } else if (x < t->data) {
        t->left = insert(t->left, x);
        } else if (x > t->data) {
        t->right = insert(t->right, x);
        }
        return t;
    }
    Node* find(Node* t, T x) {
        if (t == NULL) return NULL;
        if (x < t->data) return find(t->left, x);
        if (x > t->data) return find(t->right, x);
        return t;
    }
    Node* findMin(Node* t) {
        if (t == NULL || t->left == NULL) return t;
        return findMin(t->left);
    }
    Node* findMax(Node* t) {
        if (t == NULL || t->right == NULL) return t;
        return findMax(t->right);
    }
    Node* remove(Node* t, T x) {
        Node* temp;
        if (t == NULL) return NULL;
        else if (x < t->data) t->left = remove(t->left, x);
        else if (x > t->data) t->right = remove(t->right, x);
        else if (t->left && t->right) {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->right, t->data);
        } else {
            temp = t;
            if (t->left == NULL) t = t->right;
            else if (t->right == NULL) t = t->left;
            delete temp;
        }
        return t;
    }
    public:
    BST(): root(NULL) {}
    ~BST() {
        root = makeEmpty(root);
    }
    void insert(T x) {
        insert(root, x);
    }
    void remove(T x) {
        remove(root, x);
    }
};



int main(){
    kmp0dixed("wssasdsvssd", "sd");
    return 0;
}