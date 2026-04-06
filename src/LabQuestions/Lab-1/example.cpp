#include <iostream>

struct node {
    int data;
    struct node* next;
};

int main(int argc, char const *argv[])
{
    /* code */
    std::cout << "Hello World" << std::endl;

    std::cout << "argc:" << argc << std::endl;
    std::cout << "argv:" << argv << std::endl;

    node mynode;
    mynode.data = 17;
    mynode.next = nullptr;

    mynode.next = new node;
    (*mynode.next).data = 7;
    mynode.next->next = new node;
    mynode.next->next->data = 15;
    mynode.next->next->next = nullptr;

    node* np;
    
    for (np = &mynode; np != nullptr; np = np->next) {
        std::cout << "&np: " << mynode.data << std::endl;
        std::cout << "np.data: " << np->data << std::endl;
        std::cout << "np.next: " << np->next << std::endl;
        std::cout << "--" << std::endl;
    }

    std:: cout << " " << std::endl;

    // node mynode2 = mynode;

    std::cout << "Node Data: " << mynode.data << std::endl;
    std::cout << "Node : Next: " << mynode.next << std::endl;

    std::cout << "Node 2 Data: " << (*mynode.next).data << std::endl;
    std::cout << "Node 3 Data: " << mynode.next->next->data << std::endl;

    return 0;
}
