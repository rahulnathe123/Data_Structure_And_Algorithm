#ifndef _SINGLY_LINKED_LIST__HPP
#define _SINGLY_LINKED_LIST__HPP

#include<iostream>

/*symbolic constants */
const int SUCCESS               =  1;
const int TRUE                  =  1;
const int FALSE                 =  0;
const int LIST_DATA_NOT_FOUND   =  2;
const int LIST_EMPTY            =  3;

class Singly_Linked_List
{
    public:
        /*Create list*/
        static Singly_Linked_List* getLinkedListInstance();
        virtual ~Singly_Linked_List()noexcept = default;
        /*Data Addition Function*/
        virtual int insert_start(int new_data) = 0;
        virtual int insert_end(int new_data) = 0;
        virtual int insert_after(int existing_data , int new_data) = 0;
        virtual int insert_before(int existing_data , int new_data) = 0;
        
        /*Data Accessing function*/
        virtual int get_start(int& start_data)const = 0 ;
        virtual int get_end(int& end_data)const = 0;

        /*Data Remove functions*/
        virtual int pop_start(int& start_data) = 0;
        virtual int pop_end(int& end_data) = 0;
        virtual int remove_start() = 0;
        virtual int remove_end() = 0;
        virtual int remove_data(int r_data) = 0;

        /*Miscallenous function*/
        virtual int find(int f_data)const = 0;
        virtual int is_list_empty()const = 0;
        virtual int get_list_length()const = 0;
        virtual void print(std::ostream& os)const = 0;
        friend std::ostream& operator<<(std::ostream& os , const Singly_Linked_List& other)
        {
            other.print(os);
            return os;
        }

};
#endif
