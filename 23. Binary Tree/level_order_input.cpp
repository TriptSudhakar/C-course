#include<iostream>
#include<queue>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int d){
		data = d;
		left = right = NULL;
	}
};

void createTree(Node* &root){
	int d;
	cin>>d;
	root = new Node(d);
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* f = q.front();
		q.pop();
		int c1,c2;
		cin>>c1>>c2;
		if(c1 != -1){
			f->left = new Node(c1);
			q.push(f->left);
		}
		if(c2 != -1){
			f->right = new Node(c2);
			q.push(f->right);
		}
	}
}

void printLeafNode(Node* root){
	if(root == NULL){
		return;
	}
	if(root->left == NULL && root->right == NULL){
		cout<<root->data<<" ";
	}
	printLeafNode(root->left);
	printLeafNode(root->right);
}

int main() {
	Node* root = NULL;
	createTree(root);
	printLeafNode(root);
	return 0;
}