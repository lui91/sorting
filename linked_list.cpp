#include <iostream>

using namespace std;


class linked_list{

    struct Node { 
    string text; 
    struct Node *next; 
    }; 
    struct Node* head = NULL;

    public:

        int search_node(string text){
            struct Node* ptr;
            ptr = head;
            while (ptr != NULL) { 
                if (ptr->text == text)
                {
                    cout << text << " already in the list" << endl;
                    return 1;
                }
                ptr = ptr->next; 
            }
            return 0;
        }

        void insert(string new_data) { 
            if (search_node(new_data))
            {
                cout << "That entry already exists" << endl;
            }else
            {
                struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
                new_node->text = new_data; 
                new_node->next = head; 
                head = new_node; 
            } 
        } 

        void display() { 
        struct Node* ptr;
        ptr = head;
        while (ptr != NULL) { 
            cout<< ptr->text << endl; 
            ptr = ptr->next; 
        } 
        } 

};


// int main(int argc, char const *argv[])
// {
//     string s1 [5]= { "Mario","Jorge", "Luisa", "Mario" ,"Marta" };
//     string s2 [5]= { "Mar","Jor", "Lui", "Abd" ,"Martinoli" };

//     linked_list l1 [2];
//     // linked_list l2;

//     for (size_t i = 0; i < 5; i++)
//     {
//         l1[0].insert(s1[i]);
//         l1[1].insert(s2[i]);
//     }
    
//     cout << "oli" << endl;
//     cout<<"The l1 linked list is: " <<endl;
//     l1[0].display();

//     cout<<"The l2 linked list is: " <<endl;
//     l1[1].display();
//     return 0;
// }