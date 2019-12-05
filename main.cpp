#include <iostream>

using namespace std;

struct tree_node
{
	tree_node *left;
	tree_node *right;
	int key;
};

class BTree
{
public:
	tree_node* root;

	BTree(struct tree_node* head)
	{
		this->root = head;
	}

	struct tree_node* insertNode(struct tree_node* node, int key);
	struct tree_node* minValueNode(struct tree_node* node);
	struct tree_node* deleteNode(struct tree_node* root, int key);
	void printTree(struct tree_node* root);

	~BTree()
	{
	    delete root;
	}
};

struct tree_node* BTree::insertNode(struct tree_node* node, int key)
{
	if (node==NULL)
    {
        node = new tree_node;
        node->left=NULL;
        node->right=NULL;
        node->key=key;
        return node;
    }
	if (key < node->key)
		node->left = insertNode(node->left, key);
	else
		node->right = insertNode(node->right, key);
	return node;
}

struct tree_node* BTree::minValueNode(struct tree_node* node)
{
	struct tree_node* current = node;

	while (current && current->left != NULL)
		current = current->left;

	return current;
}

struct tree_node* BTree::deleteNode(struct tree_node* root, int key)
{
	if (root==NULL)
	{
		cout << "The tree is empty or there is no such element. Check your command\n";
		return root;
	}

	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else
	{
		if (root->left == NULL)
		{
			struct tree_node* temp = root->right;
			cout << root->key << " was deleted\n";
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct tree_node* temp = root->left;
			cout << root->key << " was deleted\n";
			free(root);
			return temp;
		}

		struct tree_node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

void BTree:: printTree(struct tree_node* root)
{
	if (root==NULL)
		return;
	printTree(root->left);
	cout << root->key << " ";
	printTree(root->right);
}

int main()
{
		BTree tree(NULL); //create the Binary Tree
		cout << "Let delete a node with the key 3!\n";
		tree.deleteNode (tree.root, 3);
		tree.root=tree.insertNode(tree.root, 10);
		tree.root=tree.insertNode(tree.root, 7);
		tree.root=tree.insertNode(tree.root, 12);
		tree.root=tree.insertNode(tree.root, 8);
		tree.root=tree.insertNode(tree.root, 11);
		tree.root=tree.insertNode(tree.root, 9);
		tree.root=tree.insertNode(tree.root, 15);
		tree.root=tree.insertNode(tree.root, 4);
		tree.root=tree.insertNode(tree.root, 1);
		tree.root=tree.insertNode(tree.root, 5);
		tree.root=tree.insertNode(tree.root, 20);
		tree.root=tree.insertNode(tree.root, 18);

		tree.printTree(tree.root);
		cout << endl;
		cout << endl;
        cout << "Let delete a node with the key 20!\n";
		tree.deleteNode (tree.root, 20);
		tree.printTree(tree.root);
		cout << endl;
		cout << endl;
		cout << "Let delete a node with the key 2!\n";
		tree.deleteNode(tree.root, 2);
		cout << endl;
		cout << endl;
		cout << "Let delete a node with the key 18!\n";
		tree.deleteNode(tree.root, 18);
		cout << endl;
		cout << "Let delete a node with the key 8!\n";
		tree.deleteNode(tree.root, 8);
		tree.printTree(tree.root);
		cout << endl;
		cout << endl;
		cout << "Let delete a node with the key 5!\n";
		tree.deleteNode(tree.root, 5);
		tree.printTree(tree.root);

		return 0;
}
