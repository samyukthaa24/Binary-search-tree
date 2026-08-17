#include <iostream>
using namespace std;
class tree {
    struct node {
        int data;
        node *left;
        node *right;
       
    }*root;
	
	node *insert(int X, node *T) {
        if (T == NULL) {
            T = new node;
			T->data=X;
			T->left=T->right=NULL; 
        } else if (X < T->data) {
            T->left = insert(X, T->left);
        } else if (X > T->data) {
            T->right = insert(X, T->right);
        }
        return T;
    }

    
    void inorder_recursive(node *T) {
        if (T != NULL) {
            inorder_recursive(T->left);
            cout << T->data << " "; 
            inorder_recursive(T->right);
        }
    }
    
    void preorder_recursive(node *T){
    	if (T!=NULL){
    		cout<<T->data<<" ";
    		preorder_recursive(T->left);
    		preorder_recursive(T->right);
		}
	}
	
	void postorder_recursive(node *T){
		if(T!=NULL){
			postorder_recursive(T->left);
			postorder_recursive(T->right);
			cout<<T->data<<" ";
		}
	}

   
    node *find_recursive(int X, node *T) {
        if (T == NULL || T->data == X) {
            return T;
        }
        if (X < T->data) {
            return find_recursive(X, T->left);
        } else {
            return find_recursive(X, T->right);
        }
    }
    
	
	node *findmin(node *T) {
        if (T == NULL) {
            return NULL;
        } else if (T->left == NULL) {
            return T;
        }
        return findmin(T->left);
    }
    
    
	node *findmax(node *T) {
        if (T == NULL) {
            return NULL;
        } else if (T->right == NULL) {
            return T;
        }
        return findmax(T->right);
    }
	
	
	
    node *deletion(int X, node *T) {
        if (T == NULL) {
            return NULL;
        }
        if (X < T->data) {
            T->left = deletion(X, T->left);
        } else if (X > T->data) {
            T->right = deletion(X, T->right);
        } else { 
            if (T->left == NULL) {
                node *temp = T->right;
                delete T;
                return temp;
            } else if (T->right == NULL) {
                node *temp = T->left;
                delete T;
                return temp;
            }
            node *temp = findmin(T->right);
            T->data = temp->data;
            T->right = deletion(temp->data, T->right);
        }
        return T;
    }
    

public:
    tree(){
	    root=NULL;
    }

    
    void insert_tree(int X) {
        root = insert(X, root);
    }

    
    void inorder() {
        inorder_recursive(root);
        cout << endl; 
    }
    
    void preorder(){
    	preorder_recursive(root);
    	cout<<endl;
    	
	}
	
	void postorder(){
		postorder_recursive(root);
		cout<<endl;
	}

    
    bool find(int X) {
        return find_recursive(X, root) != NULL;
    }
    
    bool findmax(){
    	return findmax(root);
	}
    
    void delete_tree(int X) {
        root = deletion(X, root);
    }
    
    void display(){
    	if (root == NULL) {
            cout << "Tree is empty." << endl;
            return;
        }
        cout << "BST Tree (In-order traversal): ";
        inorder_recursive(root);
        cout<<endl;
        cout<<"BST Tree(Pre-Order traversal):";
        preorder_recursive(root);
        cout<<endl;
        cout<<"BST Tree(Post-Order traversal):";
        postorder_recursive(root);
        cout << endl;
	}
};

int main() {
    tree ob;
    int x,y,z,no,w;
   /* ob.insert_tree(50);
    ob.insert_tree(30);
    ob.insert_tree(70);
    ob.insert_tree(20);
    ob.insert_tree(40);
    ob.insert_tree(60);
    ob.insert_tree(80);*/ 
    cout<<"Enter num of digits:";
    cin>>no;
    for(int i=0;i<no;i++){
    	cout<<"Enter the digit:";
    	cin>>w;
    	ob.insert_tree(w);
	}

    ob.display();
    cout<<"Enter a number to find:";
    cin>>x;
    y=ob.find(x);
    if (y==true){
    	cout<<"YES.The number "<<x<<" is present\n";
	}
	else{
		cout<<"NO.The number "<<x<<" is not present\n";
	}
	
	cout<<"Enter a number to delete:";
	cin>>z;
	ob.delete_tree(z);
	cout<<"Inorder traversal after deleting "<<z<<":\n";
	ob.display();
	
    
}













