#include <iostream>

class Node
{
public:
    Node(int mData): Data(mData) {}
    int Data;
    Node *next;
    void thisNode() const
    {
        std::cout << Data << "\n";
    }
};

Node* revertList(Node* root)
{

    if(root==NULL||root->next==NULL)
        return root;

    Node* nextNode = revertList(root->next);

    root->next->next = root;
    root->next = NULL;
    return nextNode;
}

int main()
{

    Node* first = new Node(1);
    Node* second = new Node(2);

    first->next = second;
    second->next = nullptr;
    first->thisNode();
    first->next->thisNode();
    std::cout << std::endl;

    first = revertList(first);
    first->thisNode();
    first->next->thisNode();


    return 0;
}
