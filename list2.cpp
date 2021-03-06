#include <iostream>
#include <memory>

using namespace std;

class Node
{
public:
    Node(const int v) :
        next(nullptr),
        prev(nullptr),
        value(v)
    {}
    
    shared_ptr<Node> next;
    shared_ptr<Node> prev;
    int value;
};

class List
{
public:
    List();
    ~List();
    void add(shared_ptr<Node> node);              // dodaje element na koniec listy
    void addFirst(shared_ptr<Node> node);         // dodaje element na początek listy
    shared_ptr<Node> get(const int value);        // zwraca element o wskazanej wartości
    shared_ptr<Node> getBackward(const int value) // zwraca element od końca listy

private:
    shared_ptr<Node> first;
    shared_ptr<Node> last;
};

List::List() :
    first(nullptr)
    last(nullptr)
{}

void List::add(shared_ptr<Node> node)
{
    if(!first)
    {
        first = node;
    }
    else
    {
        shared_ptr<Node> current = first;
        while(current->next)
        {
            current = current->next;
        }
        current->next = node;
    }
}

void List::addFirst(shared_ptr<Node> node)
{
    if(!last)
    {
        last = node;
    }
    else
    {
        shared_ptr<Node> current = last;
        while(current->prev)
        {
            current = current->prev;
        }
        current->prev = node;
    }
}

shared_ptr<Node> List::get(const int value)
{
    if(!first)
    {
        cout << "List is empty!" << endl;
        return nullptr;
    }
    else
    {
        shared_ptr<Node> current = first;
        do
        {
            if(current->value == value)
            {
                cout << "Found value " << current->value << endl;
                return current;
            }
            else
            {
                cout << "Going through " << current->value << endl;
                current = current->next;
            }
        } while(current);
        cout << "Not found: value " << value << endl;
        return nullptr;
    }
}

shared_ptr<Node> List::getBackward(const int value)
{
    if(!first)
    {
        cout << "List is empty!" << endl;
        return nullptr;
    }
    else
    {
        shared_ptr<Node> current = last;
        do
        {
            if(current->value == value)
            {
                cout << "Found value " << current->value << endl;
                return current;
            }
            else
            {
                cout << "Going through " << current->value << endl;
                current = current->prev;
            }
        } while(current);
        cout << "Not found: value " << value << endl;
        return nullptr;
    }
}

int main()
{
    List lista;
    shared_ptr<Node> node4 {new Node(4)};
    auto node7 = make_unique<Node>(7);

    lista.add(node4);
    lista.add(make_shared<Node>(2));
    lista.add(node7);
    lista.add(new Node(9));
    auto node = lista.get(1);

    return 0;
}

