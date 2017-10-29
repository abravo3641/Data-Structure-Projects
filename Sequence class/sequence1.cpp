// Name:Anthony Bravo
// Class: CS 212
// Date: 10/24/2017
#include"sequence1.h"
#include <assert.h>
#include<iostream>

namespace main_savitch_3 {
    
    const sequence::size_type sequence::CAPACITY;
    
    //Default constructor
    sequence::sequence() {
        used = 0;                                   //Empty Sequence
    }
    
    //Start function
    void sequence::start() {
            if(size()>0)                            //Only initialize the sequence if is not empty
                current_index = 0;                  //Start at first item
    }
    
    //Advance function
    void sequence::advance() {
          assert(is_item());                        //Check if our current index is valid (between data[0] to data [used-1])
          current_index++;                          //Move current index
    }
    
    //Insert function
    void sequence::insert(const value_type& entry) {
        assert(size()<CAPACITY);                    //Theres room for one more entry
       
        if(!is_item())                              //2 cases: list is empty or current index is at used
            current_index = 0;                      //In either case we insert at the front of the sequence
        
        for(size_t i=used; i>current_index; i--) {  //Shift from data[current] to data[used-1] to the right
            data[i] = data[i-1];
        }
        data[current_index] = entry;                //New item is out current index
        used++;                                     //increment size
    }
    
    //Attach function
    void sequence::attach(const value_type& entry) {
        assert(size()<CAPACITY);                    //Theres room for one more entry
        
        if(!is_item())                              //2 cases: list is empty or current index is at used
            current_index = used-1;                 //In either case we insert at end of the of sequence
        
        for(size_t i=used;i>current_index+1; i--)   //Shift form data[current+1] to data[used-1] to the rigth
            data[i] = data[i-1];
        
        current_index++;                            //Current index is at the wrong spot
        data[current_index] = entry;                //Make new input current index
        used++;                                     //increment size
    }
    
    void sequence::remove_current( )
    {
        assert(is_item());                          //Check if we have an item to delete
        for(size_t i = current_index;i<used-1;i++)  //Shift from data[current+1] to data[used-1] to the left
            data[i]=data[i+1];
        
        used--;                                     //Decrease size
    }
    
    //Size function
    sequence::size_type sequence::size()const{
        return used;
    }
    
    //Is item function
    bool sequence::is_item()const {                 //There is an item between data[0] and data[used-1]
        return (current_index != used && used!=0);  //True if current index is not beyond the array (current!=used)
    }                                               //and the list is not empty (used!=0)
    
    //Current function
    sequence::value_type sequence::current()const {
        assert(is_item());
        return data[current_index];
    }
    
}

