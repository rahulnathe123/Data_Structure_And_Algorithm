#ifndef __Singly_Linked_List_Implement__HPP
#define __Singly_Linked_List_Implement__HPP

#include "Singly_Linked_List_Interface.hpp"



class node
{
    friend class Singly_Linked_List_Impl;
    private:
        int data;
        node* next;
    public:
        node(int newdata = 0)
        {
            data = newdata;
            next = nullptr;
        }
        friend std::ostream& operator<<(std::ostream& os , const Singly_Linked_List_Impl& other);

};

class Singly_Linked_List_Impl:public Singly_Linked_List
{
    private:
        node* p_list;
    public:
        Singly_Linked_List_Impl();
        ~Singly_Linked_List_Impl()override;
        /*Data Addition functions*/
        int insert_start(int new_data);
        int insert_end(int new_data);
        int insert_before(int existing_data , int new_data);
        int insert_after(int existing_data , int new_data);

        /*Data Accessing functions*/
        int get_start(int& start_data)const;
        int get_end(int& end_data)const;

        /*Data Remove Functions*/
        int pop_start(int& start_data);
        int pop_end(int& end_data);
        int remove_start();
        int remove_end();
        int remove_data(int r_data);

        /*Miscellenous functions*/
        int find(int f_data)const;
        int is_list_empty()const;
        int get_list_length()const;
        void print(std::ostream& os)const;
};


#endif
