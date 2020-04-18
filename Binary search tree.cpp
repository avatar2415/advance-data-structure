// C program to demonstrate insert operation in binary search tree
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};


struct node *newNode(int item)
{
	struct node *temp = new node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}
struct node* insert(node* root, int data)
{

	if (root== NULL)
        return newNode(data);

	else if (data <= root->data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);


	return root;
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout<<"   "<< root->data;
		inorder(root->right);
	}
}




struct node *search_num(node *node, int num)
{
    if(node==NULL)
    {

        return NULL;
    }
    if(num > node->data)
    {

        return search_num(node->right,num);
    }
    else if(num < node->data)
    {

        return search_num(node->left,num);
    }
    else
    {

        return node;
    }
}
node * findmin(node *root)
{
    if(root==NULL)
    {
        /* There is no element in the tree */
        return NULL;
    }
    if(root->left) /* Go to the left sub tree to find the min element */
        return findmin(root->left);
    else
        return root;
}
int maxdepth(node* root)
{
    if (root == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxdepth(root->left);
        int rDepth = maxdepth(root->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}
void mirror (node *root)
{

    if (root ==NULL)
        return ;
    else
    {

        node *p;
        mirror(root->left);
        mirror (root->right );
        p=root->left ;
        root->left=root->right;
        root->right=p;
    }
}
int main()
{
    int i ,num,ch,n;
    node *temp;

    struct node *root = NULL;
   do
  {
    cout<<"\n enter the choice";

    cout<<"\n 0.EXIT  \n 1.Insert new node \n 2.Find number of nodes in longest path  \n 3.Minimum data value found in the tree \n 4. swapping \n 5.search value";
	cin>>ch;

	switch (ch)
	{
	    case 1:
	    cout<<" \n how many number you want to insert ";
	    cin>>n ;
	    for (i=0;i<n;i++)
        {
            cout<<" \n which number you want to enter ";
            cin>>num;
            root=insert (root ,num);

        }
        inorder(root);
        break;
        case 2: cout<<" \n the depth of tree is "<< maxdepth(root);
            break;
        case 3:temp =findmin(root);
                    cout<<"\n the minimum number is "<<" : "<< root->data;
                break;
        case 4:mirror(root);
               inorder(root);
            break;
        case 5:
             cout<<"\n which number you want to find";
             cin>>num;
             temp=search_num(root ,num);
             if (temp==NULL)
             {


                 cout<<"\n element not found";

             }
             else
             {
                     cout<<"\n element found ";

             }
            break;

             break;

	}

  }while (ch !=0);



	return 0;
}
