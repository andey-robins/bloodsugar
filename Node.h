class Node{

//values of the Node
public:
    float value;
    Node* next;

//functions for the node
public:
    //constructors
    Node(float v);

    Node(float v, Node* n);

    //destructors
    ~Node();

}
