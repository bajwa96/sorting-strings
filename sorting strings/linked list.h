//
//  Header.h
//  sorting strings
//
//  Created by Navroop Singh Bajwa on 26/04/18.
//  Copyright © 2018 Navroop Singh Bajwa. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <iostream>
using namespace std;

struct digit {
    int size;
    char n;
    struct digit *next;
    digit(int no){
        this->n=no;
        this->next=NULL;
    }
};

struct numbers{
    struct digit *head;
    struct numbers *next;
    numbers(struct digit *agla){
        this->head=agla;
        this->next=NULL;
    }
};
struct digit *insert(char t,struct digit *head,int size){//insertion at end O(1)
    if(head==NULL){
        digit *temp=new digit(t);
        temp->size=size;
        return temp;
    }else{
        struct digit *temp=new digit(t);
        head->next=temp;
        return temp;
    }
}

struct digit *getinsertedintolinkedlist(string number){
    digit *head=NULL,*tail=NULL;
    if(number.length()>0){
        for(int i=0;i<number.length();i++){
            if(head==NULL){
                head=insert(number[i],head,(int)number.length());
                tail=head;
            }else{
                tail=insert(number[i],tail,(int)number.length());
            }
        }
    }
    return head;
}
bool is_first_small_or_second(struct digit *a,digit *b){
    // if a is small then true will be returned
    // else false will be returned
    if(a->size==b->size){
        while(a&&b){
            cout<<a->n<<" "<<b->n<<endl;
            if(a->n  > b->n ){ //a=3 b=2 return false
                //cout<<"f";
                return false;break;
            }
            if(a->n  < b->n  ){ // a= 2 b= 3 2<3 return true
                //cout<<"t";
                return true;break;
            }
            a=a->next;
            b=b->next;
        }
        //cout<<"t";
        return true;
    }else if (a->size<b->size){
        //cout<<"t";
        return true;
    }else
        //cout<<"f";
        return false;
    
    
}
struct numbers *getinserted(struct digit *number,struct numbers *head){
    if(head==NULL){
        return new numbers(number);
    }else{
        struct numbers *temp=new numbers(number);
        
        if(is_first_small_or_second(number,head->head)==true){ //if number is less than starting from list
            temp->next=head;
            return temp;
        }
        
        struct numbers *last=head,*rethead=head;
        head=head->next;
        while(head!=NULL){
            if(is_first_small_or_second(number,head->head)==true){
                temp->next=head;
                last->next=temp;
                return rethead;
            }
            last=head;
            head=head->next;
        }
        //insertion at last
        temp->next=NULL;
        last->next=temp;
        return rethead;
    }
    return head;
    
}
void display(struct digit *head){
    //cout<<head->size<<"| ";
    while(head){
        cout<<head->n;
        head=head->next;
    }cout<<endl;
}
void displaysorted(struct numbers *head){
    while(head){
        display(head->head);
        head=head->next;
    }
}


#endif /* Header_h */
