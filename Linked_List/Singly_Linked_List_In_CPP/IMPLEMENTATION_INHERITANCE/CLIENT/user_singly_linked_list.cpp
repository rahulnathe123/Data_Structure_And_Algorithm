#include<iostream>
#include<assert.h>

#include "Singly_Linked_List_Interface.hpp"


void test_for_data_addition_function(Singly_Linked_List& S);
void test_for_assertion_on_empty_list(Singly_Linked_List& S);
void test_for_GetData_on_list(Singly_Linked_List& S);
void test_for_data_remove_funtion(Singly_Linked_List& S);
void test_for_miscallenous_function(Singly_Linked_List& S);


int main(void)
{
    std::cout<<"-----Entered : main()-----"<<std::endl;
    const char* line = "\n------------------------------------------------------------------------\n";
    Singly_Linked_List* p_SLL = Singly_Linked_List::getLinkedListInstance();
    std::cout<<"List created Successfully"<<std::endl;
    std::cout<<line;
    std::cout<<"Testing Assertion on the empty list"<<std::endl;
    test_for_assertion_on_empty_list(*p_SLL);
    std::cout<<line;

    std::cout<<"Testing on Data Insertion on the list"<<std::endl;
    test_for_data_addition_function(*p_SLL);
    std::cout<<line;

    std::cout<<"Testing on Accessing Data on the list"<<std::endl;
    test_for_GetData_on_list(*p_SLL);
    std::cout<<line;

    std::cout<<"Testing on Removing Data on the list"<<std::endl;
    test_for_data_remove_funtion(*p_SLL);
    std::cout<<line;

    std::cout<<"Testing on Miscallenous Operation on the list"<<std::endl;  
    test_for_miscallenous_function(*p_SLL);
    delete p_SLL;
    p_SLL = nullptr;
    std::cout<<"-----Leaving : main()-----"<<std::endl;
    return 0;   
}


void test_for_data_addition_function(Singly_Linked_List& S)
{
    const char* line = "\n---------------------------------------------------------\n";
    std::cout<<"-----Entered : test_for_data_addition_function()----"<<std::endl;
    int status;
    for(int i =0 ;i<5;i++)
    {
        status = S.insert_start((i+1)*100);
        assert(status == SUCCESS);
        std::cout<<(i+1)*100<<" inserted successfully at the start of the list"<<std::endl;
    }
    std::cout<<"Showing list after inserting 5 elements successfully"<<std::endl<<S<<std::endl;
    std::cout<<line;
    for(int i = 0;i<5;i++)
    {
        status = S.insert_end((i+1) * 1000);
        assert(status == SUCCESS);
        std::cout<<(i+1)*1000<<" inserted Successfully at the end of the list"<<std::endl;
    }
    std::cout<<"Showing list after inserting 5 elements successfully at the end of the list"<<S<<std::endl;
    std::cout<<line;

    status = S.insert_before(50 , 10000);
    assert(status == LIST_DATA_NOT_FOUND);
    std::cout<<"Expected Results Come after inserting 10000 before non existent data 50"<<std::endl;
    std::cout<<line;

    status = S.insert_before(100 , 10000);
    assert(status == SUCCESS);
    std::cout<<"Showing list after Successfully inserting 10000 before existent data 100"<<std::endl<<S<<std::endl;
    std::cout<<line;

    status = S.insert_after(50 , 20000);
    assert(status == LIST_DATA_NOT_FOUND);
    std::cout<<"Expected Results Come after inserting 20000 after non-existent data 50"<<std::endl;
    std::cout<<line;

    status = S.insert_after(100 , 20000);
    assert(status == SUCCESS);
    std::cout<<"Showing list After successfully inserting 20000 after existent data 100"<<std::endl<<S;
    std::cout<<line;


    std::cout<<"-----Leaving : test_for_data_addition_function()----"<<std::endl;
}


void test_for_assertion_on_empty_list(Singly_Linked_List& S)
{
    std::cout<<"-----Entered : test_for_assertion_on_empty_list()-----"<<std::endl;

    int status , start_data , end_data;
    status = S.is_list_empty();
    assert(status == TRUE);
    status = S.get_list_length();
    assert(status == 0);
    status = S.get_start(start_data);
    assert(status == LIST_EMPTY);
    status = S.get_end(end_data);
    assert(status == LIST_EMPTY);
    status = S.pop_start(start_data);
    assert(status == LIST_EMPTY);
    status = S.pop_end(end_data);
    assert(status == LIST_EMPTY);
    status = S.remove_start();
    assert(status == LIST_EMPTY);
    std::cout<<std::endl<<"All insertion on list is successfully";

    std::cout<<"-----Leaving : test_for_assertion_on_empty_list()-----"<<std::endl;
}

void test_for_GetData_on_list(Singly_Linked_List& S)
{
    const char* line = "\n---------------------------------------------------------\n";

    std::cout<<"-----Entered : test_for_GetData_on_list()-----"<<std::endl;

    int status ,start_data,end_data;
    status = S.get_start(start_data);
    assert(status == SUCCESS);
    std::cout<<"Starting data : "<<start_data<<std::endl;
    std::cout<<"Showing list after demonstrate get_start() on the list"<<std::endl<<S<<std::endl;
    std::cout<<line;

    status = S.get_end(end_data);
    assert(status == SUCCESS);
    std::cout<<"Ending data : "<<end_data<<std::endl;
    std::cout<<"Showing list after demonstrate get_end() on the list"<<std::endl<<S<<std::endl;
    std::cout<<"-----Leaving : test_for_GetData_on_list()-----"<<std::endl;
    std::cout<<line;
}


void test_for_data_remove_funtion(Singly_Linked_List& S)
{
    const char* line = "\n---------------------------------------------------------\n";
    std::cout<<"-----Entered : test_for_data_remove_function()-----"<<std::endl;
    int status ,start_data,end_data;
    status = S.pop_start(start_data);
    assert(status == SUCCESS);
    std::cout<<"Start data : "<<start_data<<std::endl;
    std::cout<<"Showing list after demonstrate pop_start() with removing it"<<std::endl<<S<<std::endl;

    std::cout<<line;


    status = S.pop_end(end_data);
    assert(status == SUCCESS);
    std::cout<<"End Data : "<<end_data<<std::endl;
    std::cout<<"Showing list after demonstrate pop_end() with removing it"<<std::endl<<S<<std::endl;
    std::cout<<line;

    status = S.remove_start();
    assert(status == SUCCESS);
    std::cout<<"Showing list after remove_start()"<<std::endl<<S;
    std::cout<<line;

    status = S.remove_end();
    assert(status == SUCCESS);
    std::cout<<"Showing list after remove_start()"<<std::endl<<S;
    std::cout<<line;

    status = S.remove_data(50);
    assert(status == LIST_DATA_NOT_FOUND);
    std::cout<<"Expected error comes out after remove non existent data 50"<<std::endl;
    std::cout<<line;

    status = S.remove_data(10000);
    assert(status == SUCCESS);
    std::cout<<"Showing list After demonstrate remove 10000 from list"<<std::endl<<S;
    std::cout<<line;

    std::cout<<"-----Leaving : test_for_data_remove_function()-----"<<std::endl;
}   


void test_for_miscallenous_function(Singly_Linked_List& S)
{
    const char* line = "\n---------------------------------------------------------\n";

    std::cout<<"-----Entered : test_for_miscallenous_function()-----"<<std::endl;
    int status ;
    status = S.find(50);
    assert(status == FALSE);
    std::cout<<"Expected error comes FALSE after finding non existing data 50"<<std::endl;
    std::cout<<line;
    
    status = S.find(20000);
    assert(status == TRUE);
    std::cout<<"Expected results TRUE come after Finding data 20000"<<std::endl;
    std::cout<<line;

    int length = S.get_list_length();
    std::cout<<"Length of the list : "<<length<<std::endl;

    status = S.is_list_empty();
    assert(status == 0);
    std::cout<<"Expected result FALSE come after checking is_list_empty()"<<std::endl;

    std::cout<<"-----Leaving : test_For_miscallenous_function()-----"<<std::endl;
}
