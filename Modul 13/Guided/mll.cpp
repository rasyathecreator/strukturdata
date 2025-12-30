#include <iostream>
#include <string>
using namespace std;

struct child_node
{
   string info;
   child_node* next;
};

struct parent_node
{
   string info;
   child_node* child_head;
   parent_node* next;
};

parent_node *create_parent(string info)
{
   parent_node* new_node = new parent_node;
   new_node->info = info;
   new_node->child_head = NULL;
   new_node->next = NULL;
   return new_node;
};

child_node *create_child(string info)
{
   child_node* new_node = new child_node;
   new_node->info = info;
   new_node->next = NULL;
   return new_node;
};

void insert_parent(parent_node *&head, string info)
{
   parent_node* new_node = create_parent(info);
   if (head == NULL)
   {
      head = new_node;
   }
   else
   {
      parent_node* temporary = head;
      while (temporary->next != NULL)
      {
         temporary = temporary->next;
      }
      temporary->next = new_node;
   }
}

void insert_child(parent_node *head, string parent_info, string child_info)
{
   parent_node *parent_temp = head;
   while (parent_temp != NULL && parent_temp->info != parent_info)
   {
      parent_temp = parent_temp->next;
   }
   if (parent_temp != NULL)
   {
      child_node *new_child = create_child(child_info);
      if (parent_temp->child_head == NULL)
      {
         parent_temp->child_head = new_child;
      }
      else
      {
         child_node *child_temp = parent_temp->child_head;
         while (child_temp->next != NULL)
         {
            child_temp = child_temp->next;
         }
         child_temp->next = new_child;
      }
   }
}

void print_all(parent_node *head)
{
   parent_node *parent_temp = head;
   while (parent_temp != NULL)
   {
      cout << parent_temp->info;
      child_node *child_temp = parent_temp->child_head;
      if (child_temp != NULL)
      {
         while (child_temp != NULL)
         {
            cout << " -> " << child_temp->info;
            child_temp = child_temp->next;
         }
      }
      cout << endl;
      parent_temp = parent_temp->next;
   }
}

int main()
{
   parent_node *list = NULL;

   insert_parent(list, "parent node 1");
   insert_parent(list, "parent node 2");

   print_all(list);
   cout << "\n";

   insert_child(list, "parent node 1", "child node a");
   insert_child(list, "parent node 1", "child node b");
   insert_child(list, "parent node 2", "child node c");

   print_all(list);

   return 0;
}