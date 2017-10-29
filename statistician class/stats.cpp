// Name: Anthony Bravo
// Data Structures
// September 20, 2017

#include "stats.h"
#include <assert.h>

namespace main_savitch_2C
{
    //Default Cosntructor
    statistician::statistician() {
        count = 0;
        total = 0.0;
    }
    
    //Next Member Function
    void statistician::next(double r) {
        if(count==0) //first input is default min and max
        {
            tinyest=r;
            largest=r;
        }
        else { //if its not the 1st input
            if(r<tinyest) //check tiny condition
            {
                tinyest = r;
            }
            if(r>largest) //check large condition
            {
                largest = r;
            }
        }
        count++;
        total += r;
    }
    
    //Reset Member Function
    void statistician::reset() {
        count =0;
        total =0.0;
    }
    
    //Length Member Function
    int statistician::length()const {
        return count;
    }
    
    //Sum Member Function
    double statistician::sum()const {
        return total;
    }
    
    //Mean Member Function
    double statistician::mean()const {
        assert(length()>0);
        return total/count;
    }
    
    //Minimum Member Function
    double statistician::minimum()const{
        assert(length()>0);
        return tinyest;
    }
    
    //Maximum Member Function
    double statistician::maximum()const{
        assert(length()>0);
        return largest;
    }
    
    //Operator + Function
    statistician operator +(const statistician& s1, const statistician& s2) {
        statistician s3;
        
        //Checks simple case if one of the stastician is empty(no entries)
        if(s1.length() == 0) {
            return s2;
        }
        if(s2.length() == 0) {
            return s1;
        }
        
        //Runs if there are entries on both stats
        if(s1.tinyest<s2.tinyest) {
            s3.tinyest = s1.tinyest;
        }
        else { //Takes care of 2 cases: both having same tiny or s2 tiny < s1 tiny
            s3.tinyest = s2.tinyest;
        }
        
        if(s1.largest>s2.largest) {
            s3.largest = s1.largest;
        }
        else //Takes care of 2 cases: both having same large or s2 large > s1 large
        {
            s3.largest = s2.largest;
        }
        
        s3.total = s1.total + s2.total;
        s3.count = s1.count + s2.count;
        
        return s3;
    }
    
    //Operator * Function
    statistician operator *(double scale, const statistician& s) {
        statistician s2;
        
        // if size is 0 then return s since scale does not affect it
        if(s.length() == 0) {
            return s;
        }
        
        
        if(scale>0) { //case 1: scale is positive
            s2.count = s.count;
            s2.tinyest = (s.tinyest)*scale;
            s2.largest = (s.largest)*scale;
            s2.total = (s.total)*scale;
            return s2;
        }
        else if(scale<0) { //case 2: scale is negative
            s2.count = s.count;
            s2.tinyest = (s.largest)*scale;
            s2.largest = (s.tinyest)*scale;
            s2.total = (s.total)*scale;
            return s2;
        }
        else {  //case 3: scale is 0;
            s2.count = s.count;
            s2.tinyest = 0;
            s2.largest = 0;
            s2.total = 0;
            return s2;
        }
        return s2;
    }
    
    //Operator == Function
    bool operator==(const statistician& s1, const statistician& s2) {
        if(s1.length() == s2.length()) { //to be equal they must have same length
            
            if(s1.length()==0) { //if both length are 0 then they meet all conditions, no need to check
                return true;
            }
            // if both length>0, then they must meet all conditions
            else if(s1.mean() == s2.mean() && s1.sum() == s2.sum() && s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum()) {
                return true;
            }
        }
        return false;
    }
    
}


