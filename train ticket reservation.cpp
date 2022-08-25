#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
using namespace std;
struct Node
{
    string leave_name;
    int duration;
    struct Node* next;
};

struct Head
{
    int counter;
    struct Node* p;
};

struct Head* create_head()
{
    struct Head* head;
    head = (struct Head*) malloc(sizeof(struct Head));
    head->counter = 0;
    head->p = NULL;
    return head;
}

void insertdata(struct Head* head,string a, int d)
{
    struct Node* node;
    struct Node* temp;
    if(head->counter == 0)
    {
        node = new Node();
        node->leave_name = a;
        node->duration = d;
        node->next = head->p;
        head->p = node;
    }
    else
    {
        temp = head->p;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        node = new Node();
        node->leave_name = a;
        node->duration = d;
        node->next = NULL;
        temp->next = node;
    }
    head->counter++;
}

void display_linked_list(struct Head* head)
{
    struct Node* temp;
    temp = head->p;
    cout.setf(ios::fixed);


    while(temp!= NULL)
    {
        cout << "Leave name: " << temp->leave_name << endl;
        cout << "Duration: " << temp->duration<< endl;
        temp = temp->next;
    }
}



struct StackNode
{
    string train_name;
    string source;
    string destination;
    int time;
    struct StackNode* next;
};

struct StackHead
{
    int counter;
    struct StackNode* top;
};

struct StackHead* create_stackHead()
{
    struct StackHead* head = (struct StackHead*) malloc(sizeof(struct StackHead));
    head->counter = 0;
    head->top = NULL;
};

void push(struct StackHead* head,struct Head* head1, string name, string s, string de, int d)
{
    struct StackNode* node;
    node = new StackNode();

    node->train_name = name;
    node->source = s;
    node->destination = de;
    node->time = d;
    node->next = head->top;
    head->top = node;
    head->counter++;
}

void display_stack(struct StackHead* head)
{
    cout << "\n Stack Display: "<< endl;
    struct StackNode* temp;
    temp = head->top;
    cout << endl;
    while(temp!= NULL)
    {
        cout << "Train name: " << temp->train_name << endl;
        cout << "Starting Point(Source): " << temp->source << endl;
        cout << "Ending Point(Destination): " << temp->destination << endl;
        cout << "Departure time: " << temp->time <<endl<<endl;
        temp= temp->next;
    }
}



struct QueueNode
{
    int customer_number;
    string destination;
    struct QueueNode* next;
};
struct QueueHead
{
    int counter;
    struct QueueNode* top;
    struct QueueNode* rear;
};

struct QueueHead* create_qHead()
{
    struct QueueHead* head;
    head = (struct QueueHead*) malloc(sizeof(struct QueueHead));
    head->counter = 0;
    head->top = NULL;
    head->rear = NULL;
};

void enqueue(struct QueueHead* head)
{
    struct QueueNode* node;
    node = new QueueNode ();

    cout << "Enter the customer number: ";
    cin >> node->customer_number;
    cout << "Enter the destination: ";
    cin >> node->destination;
    cout<<endl;

    node->next = NULL;

    if(head->counter == 0)
    {
        head->top = node;
    }
    else
        head->rear->next = node;
    head->counter++;
    head->rear = node;
}



void search_train(struct StackHead* head, string d)
{
    struct StackNode* temp;
    temp = head->top;

    while(temp!= NULL)
    {
        if(d == temp->destination)
        {
            cout << endl;
            cout << "Train found.....Yeah.. " << endl;
            cout << "Train name: " << temp->train_name << endl;
            cout << "Starts from : " << temp->source << endl;
            cout << "Goes to : " << temp->destination << endl;
            break;
        }

        else
            temp = temp->next;
    }
}



void dequeue(struct QueueHead* head, struct StackHead* head1)
{

     struct QueueNode* temp;
    temp = head->top;
    string des = temp->destination;
    if(head->counter == 0)
        cout << "Empty queue" << endl;
    else if(head->counter == 1)
    {
        head->top = head->rear = NULL;
    }
    else
        head->top = temp->next;
    free(temp);
    head->counter--;

    search_train(head1, des);
}


void display_queue(struct QueueHead* head)
{
    cout << "\n Queue display: " << endl;
    struct QueueNode* temp;
    temp = head->top;

    cout << endl;
    while(temp!= NULL)
    {
        cout << "Customer number: " << temp->customer_number << endl;
        cout << "Destination: " << temp->destination << endl;

        temp =  temp->next;
    }
}





int main()
{
    struct Head* head;
    head = create_head();
    struct StackHead* head1;
    head1 = create_stackHead();
    struct QueueHead* head2;
    head2 = create_qHead();


    string name;
    string source;
    string des;
    int d;
    char ch;
    for(; ;)
    {
        cout << "Enter Train name: ";
        cin >> name;
        cout << "Starting Point(Source): ";
        cin >> source;
        cout << "Ending Point(Destination): ";
        cin >> des;
        cout << "Departure Time: ";
        cin >> d;
        push(head1, head, name, source, des, d);

        cout << "Continue?(y/n): ";
        cin >> ch;

        if(ch == 'n')
            break;

    }

    for(int i = 0; i<2; i++)
    {
        enqueue(head2);
    }
    for(int i = 0; i<2; i++)
        dequeue(head2,head1);
    cout << endl;

    display_stack(head1);

    cout << endl;
    //display_queue(head2);
}
