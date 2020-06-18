/* \author Aaron Brown */
// Quiz on implementing kd tree, copied the original code from the quiz and changed KdTree Struct to a Class

#include "render/render.h"


// Structure to represent node of kd tree
struct Node
{
	std::vector<float> point;
	int id;
	Node* left;
	Node* right;

	Node(std::vector<float> arr, int setId)
	:	point(arr), id(setId), left(NULL), right(NULL)
	{}
};

class KdTree
{
public:
	Node* root;

	KdTree()
	: root(NULL)
	{}
	virtual ~KdTree(){
		delete_tree();
	}
	void delete_tree(){
		delete_tree_helper(root);
	}
	void delete_tree_helper(Node* &node){
		if (node == NULL)
			return;
		
		delete_tree_helper(node->left);
		delete_tree_helper(node->right);
		delete node;
		node = NULL;
	}

	void insertHelper(Node** node, uint depth, std::vector<float> point, int id)
	{
		// Tree is empty
		if ( *node == NULL)
		{
			*node = new Node(point, id);
		}
		else
		{
			// Calculate current distance
			uint cd = depth % 2;

			if (point[cd] < ((*node)->point[cd]))
			{
				insertHelper(&((*node)->left), depth + 1, point, id);
			}
			else
			{
				insertHelper(&((*node)->right), depth + 1, point, id);
			}
		}
	}

	void insert(std::vector<float> point, int id)
	{
		// TODO: Fill in this function to insert a new point into the tree
		// the function should create a new node and place correctly with in the root 
		insertHelper(&root, 0, point, id);

	}
	
	void searchHelper(std::vector<float> target, Node* node, float distanceTol, int depth, std::vector<int>& ids)
	{
		if (node != NULL)
		{
			if (
				node->point[0] >= (target[0] - distanceTol) &&
				node->point[0] <= (target[0] + distanceTol) &&
				node->point[1] >= (target[1] - distanceTol) &&
				node->point[1] <= (target[1] + distanceTol)

			) {
				float a = (node->point[0]-target[0]);
				float b = (node->point[1]-target[1]);
				float distance = sqrt(a*a+b*b);
				if (distance <= distanceTol)
				{
					ids.push_back(node->id);
				}				
			}

			//check across boundary
			if ((target[depth%2] - distanceTol) <= node->point[depth%2] ){
				searchHelper(target, node->left, distanceTol, depth + 1, ids);
			}
			if ((target[depth%2] + distanceTol) >= node->point[depth%2]){
				searchHelper(target, node->right, distanceTol, depth + 1, ids);
			}
		}
	}

	// return a list of point ids in the tree that are within distance of target
	std::vector<int> search(std::vector<float> target, float distanceTol)
	{
		std::vector<int> ids;
		searchHelper(target, root, distanceTol, 0, ids);
		return ids;
	}

};