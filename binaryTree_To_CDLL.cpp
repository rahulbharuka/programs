#include<bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int data;
};

Node *convertbTreeToCDLL(Node *root, Node **head, Node **tail)
{
    static Node *prev = NULL;

    if (!root)
        return NULL;

    if (*head == NULL)
        prev = NULL;

    convertbTreeToCDLL(root->left, head, tail);
    
    if (prev)
    {
        prev->right = root;
        root->left = prev;
    }
    else
        *head = root;
    
    prev = root;
    *tail = root; 

    convertbTreeToCDLL(root->right, head, tail);
}

Node *bTreeToCList(Node *root)
{
    Node *head = NULL, *tail = NULL;

    if (!root)
        return NULL;

    convertbTreeToCDLL(root, &head, &tail);

    head->left = tail;
    tail->right = head;
    
    return head;
}

void displayCList(Node *head)
{
    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout <<endl;
	itr=itr->left;
	do{
		cout<<itr->data<<" ";
		itr=itr->left;
	}while(head!=itr);
	cout<<itr->data<<endl;
}

Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
	int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
		if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        Node *child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    Node *head = bTreeToCList(root);
    displayCList(head); 
  }
    return 0;
}
