#include "Singly_Linked_List_Implementation.hpp"
#include<iostream>

Singly_Linked_List_Impl::Singly_Linked_List_Impl():p_list(new node(0))
{

}

Singly_Linked_List_Impl::~Singly_Linked_List_Impl()
{
    node* run = nullptr;
    node* run_next = nullptr;
    run = p_list;
    while(run)
    {
        run_next = run->next;
        delete run;
        run = run_next;
    }
    p_list = nullptr;
}

/*Data Addition Functions*/
int Singly_Linked_List_Impl::insert_start(int new_data)
{
    node* new_node = nullptr;
    new_node = new node(new_data);

    if(nullptr == new_node)
    {
        std::cout<<"Out of memory"<<std::endl;
        exit(EXIT_FAILURE);
    }

    new_node->next = p_list->next;
    p_list->next = new_node;
    return SUCCESS;
}

int Singly_Linked_List_Impl::insert_end(int new_data)
{
    node* run = nullptr;
    node* new_node = nullptr;

    new_node = new node(new_data);
    if(nullptr == new_node)
    {
        std::cout<<"Out of memory"<<std::endl;
        exit(EXIT_FAILURE);
    }

    run = p_list;
    while(run->next != nullptr)
    {
        run = run->next;
    }
    run->next = new_node;
    return SUCCESS;
}

int Singly_Linked_List_Impl::insert_before(int existing_data , int new_data)
{
    node* run = nullptr;
    node* run_previous = nullptr;

    if(p_list->next == nullptr)
    {
        return LIST_EMPTY;
    }

    //Step1 : Find the first apperance of existing_data
    run = p_list->next;
    run_previous = p_list;

    while(run)
    {
        if(run->data == existing_data)
        {
            break;
        }
        run_previous = run;
        run = run->next;
    }
    if(run == nullptr)
    {
        return LIST_DATA_NOT_FOUND;
    }

    node* new_node = new node(new_data);

    new_node->next = run;
    run_previous->next = new_node;
    return SUCCESS;
}

int Singly_Linked_List_Impl::insert_after(int existing_data , int new_data)
{
    node* run = nullptr;

    //Step1 : Find the first apperance of existing data
    run = p_list->next;
    while(run)
    {
        if(run->data == existing_data)
        {
            break;
        }
        run = run->next;
    }
    if(run == nullptr)
    {
        return LIST_DATA_NOT_FOUND;
    }

    node* new_node = new node(new_data);

    new_node->next = run->next;
    run->next  = new_node;
    return SUCCESS;
}

/*Data Access operations*/
int Singly_Linked_List_Impl::get_start(int& start_data)const
{
    if(p_list->next == nullptr )
    {
        return LIST_EMPTY;
    }
    start_data = p_list->next->data;
    return SUCCESS;
}

int Singly_Linked_List_Impl::get_end(int& end_data)const
{
    node* run = nullptr;
    if(p_list->next == nullptr)
    {
        return LIST_EMPTY;
    }

    run = p_list->next;
    while(run->next != nullptr)
    {
        run = run->next;
    }
    end_data = run->data;
    return SUCCESS;
}

/*Data Remove operations*/
int Singly_Linked_List_Impl::pop_start(int& start_data)
{
    node* delete_previous = nullptr;
    node* delete_node = nullptr;
    node* delete_next = nullptr;

    if(p_list->next == nullptr)
    {
        return LIST_EMPTY;
    }

    delete_previous = p_list;
    delete_node = p_list->next;
    delete_next = p_list->next->next;

    start_data = delete_node->data;
    delete_previous -> next = delete_next;
    delete delete_node;
    delete_node = nullptr;
    return SUCCESS;
}

int Singly_Linked_List_Impl::pop_end(int& end_data)
{
    node* run_previous = nullptr;
    node* run = nullptr;

    if(p_list->next == nullptr)
    {
        return LIST_EMPTY;
    }
    run = p_list->next;
    run_previous = p_list;
    while(run->next)
    {
        run_previous = run;
        run = run->next;
    }
    run_previous -> next = nullptr;
    end_data = run->data;
    delete run;
    run = nullptr;
    return SUCCESS;
}

int Singly_Linked_List_Impl::remove_start()
{
    node* delete_node = nullptr;
    node* delete_previous = nullptr;
    node* delete_next = nullptr;

    if(p_list->next == nullptr)
    {
        return LIST_EMPTY;
    }

    delete_previous = p_list;
    delete_next = p_list->next->next;
    delete_node = p_list->next;

    delete_previous -> next = delete_next;
    delete delete_node;
    delete_node = nullptr;
    return SUCCESS;
}


int Singly_Linked_List_Impl::remove_end()
{
    node* run = nullptr;
    node* run_previous = nullptr;

    if(p_list -> next == nullptr)
    {
        return LIST_EMPTY;
    }

    run = p_list->next;
    run_previous  = p_list;
    while(run->next)
    {
        run_previous = run;
        run = run->next;
    }
    run_previous->next = nullptr;
    delete run;
    run = nullptr;
    return SUCCESS;
}

int Singly_Linked_List_Impl::remove_data(int r_data)
{
    node* run = nullptr;
    node*run_previous = nullptr;
    run = p_list;
    while(run)
    {
        if(run->data == r_data)
        {
            break;
        }
        run_previous = run;
        run = run->next;
    }
    if(run == nullptr)
    {
        return LIST_DATA_NOT_FOUND;
    }

    run_previous->next = run->next;
    delete run;
    run = nullptr;
    return SUCCESS;
}

int Singly_Linked_List_Impl::find(int f_data)const
{
    node* run = nullptr;

    if(p_list->next == nullptr )
    {
        return LIST_EMPTY;
    }
    run = p_list->next;
    while(run)
    {
        if(run->data == f_data)
        {
            return TRUE;
        }
        run = run->next;
    }
    return FALSE;
}

int Singly_Linked_List_Impl::is_list_empty()const
{
    return (p_list->next == nullptr);
}

int Singly_Linked_List_Impl::get_list_length()const
{
    node* run = nullptr;
    int length = 0;
    run = p_list->next;
    while(run)
    {
        length = length + 1;
        run = run->next;
    }
    return length;
}

void Singly_Linked_List_Impl::print(std::ostream& os)const
{
    std::cout<<"LIST :- ";
    std::cout<<"[START] -> ";
    node* run = p_list->next;
    while(run)
    {
        std::cout<<run->data<<" -> ";
        run = run->next;
    }
    std::cout<<"[END] -> "<<std::endl;
}


Singly_Linked_List* Singly_Linked_List::getLinkedListInstance()
{
    return new Singly_Linked_List_Impl();
}
