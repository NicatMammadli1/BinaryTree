#include <iostream>
#include <algorithm>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node* insert(Node* root, int data)
{
    if(root == NULL)
    {
        return new Node(data);
    }
    if(root->data == data)
    {
        return root;
    }
    if(root->data < data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        root->left = insert(root->left, data);
    }
    return root;
}
Node* minValue(Node*root)
{
    while(root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node* remove(Node* root, int data)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == data)
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if(root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node* temp = minValue(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
        if(root->data < data)
        {
            root->right = remove(root->right, data);
        }
        if(root->data > data)
        {
            root->left = remove(root->left, data);
        }
    }
    return root;
}
void inorder(Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}
void postorder(Node* root)
{
    if(root !=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        std::cout <<root->data << " ";
    }
}
void preorder(Node* root)
{
    if(root != NULL)
    {
        std::cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
Node* search(Node* root, int data)
{
    if(root == NULL || root->data == data)
    {
        return root;
    }
    if(root->data < data)
    {
        return search(root->right, data);
    }
    else
    {
        return search(root->left, data);
    }
}
int treeheight(Node* root)
{
    if(root == NULL)
    {
        return -1;
    }
    return 1 + std::max(treeheight(root->left), treeheight(root->right));
}
Node* value(Node* root)
{
    while(root && root->right !=NULL)
    {
        root = root->right;
    }
    return root;
}
int CountNodes(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1+ CountNodes(root->left) + CountNodes(root->right);
}
int ChildNodes(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return ChildNodes(root->left) + ChildNodes(root->right);
}
int InternalNodes(Node* root)
{
    if(root == NULL || (root->left == NULL && root->right == NULL))
    {
        return 0;
    }
    return 1+ InternalNodes(root->left) + InternalNodes(root->right);
}
void printmenu()
{
    std::cout << "===== BINARY TREE ===== \n";
    std::cout << "1. ADD NODE: \n";
    std::cout << "2. REMOVE NODE: \n";
    std::cout << "3. INORDER TRAVERSAL: \n";
    std::cout << "4. POSTORDER TRAVERSAL: \n";
    std::cout << "5. PREORDER TRAVERSAL: \n";
    std::cout << "6. SEARCH NODE: \n";
    std::cout << "7. HEIGHT OF TREE: \n";
    std::cout << "8. MAX NODE: \n";
    std::cout << "9. NODE COUNT: \n";
    std::cout << "10. CHILD NODE: \n";
    std::cout << "11. INTERNAL NODE: \n";
    
}
int main()
{
    Node* root = NULL;

    int choice;
    do
    {
        printmenu();
        if(!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        switch(choice)
        {
            case 1:
            {
                int input;

                std::cout << "ADD NODE\n";
                std::cout << '\n';
                if(!(std::cin >> input))
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }
                root = insert(root, input);
                break;
            }
            case 2:
            {
                int input;

                std::cout << "REMOVE NODE\n";
                std::cout << '\n';
                if(!(std::cin >> input))
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }
                root = remove(root, input);
                break;
            }
            case 3:
            {
                std::cout << "INORDER TRAVERSAL: \n";
                inorder(root);
                break;
            }
            case 4:
            {
                std::cout << "POSTORDER TRAVERSAL: \n";
                postorder(root);
                break;
            }
            case 5:
            {
                std::cout << "PREORDER TRAVERSAL: \n";
                preorder(root);
                break;
            }
            case 6:
            {
                int input;

                std::cout << "SEARCH NODE\n";
                std::cout << '\n';
                if(!(std::cin >> input))
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }
                Node* result = search(root, input);
                if(result !=NULL)
                {
                    std::cout << input << " exists in tree!\n";
                }
                else
                {
                    std::cout << "NOT SUCH NODE!\n";
                }
                
                break;
            }
            case 7:
            {
                std::cout << "HEIGHT OF TREE: \n";
                std::cout << treeheight(root) << "\n";
                break;
            }
            case 8:
            {
                std::cout << "MAX NODE: \n";
                std::cout << value(root)->data << "\n";
                break;
            }
            case 9:
            {
                std::cout << "NODE COUNT: \n";
                std::cout << CountNodes(root) << "\n";
                break;
            }
            case 10:
            {
                std::cout << "CHILD NODE: \n";
                std::cout << ChildNodes(root) << "\n";
                break;
            }
            case 11:
            {
                std::cout << "INTERNAL NODE: \n";
                std::cout << InternalNodes(root) << "\n";
                break;
            }
            default:
            std::cout << "Invalid!\n";
            break;
        }
    } while (true);
    
    return 0;
}
