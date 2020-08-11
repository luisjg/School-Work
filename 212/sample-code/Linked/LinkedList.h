typedef int ItemType;

struct Node 
{
  ItemType item;
  Node * next;
};

class LinkedList
{
  public:
    LinkedList();
    ~LinkedList();
    bool isEmpty() const;
    int getLength() const;
    void insert(ItemType val);
    void remove(ItemType val);
    void retrieve(int index, ItemType& dataItem) const;
    void print();

  private:
    Node *head;
};

