//
//  main.cpp
//  sorting strings
//
//  Created by Navroop Singh Bajwa on 26/04/18.
//  Copyright © 2018 Navroop Singh Bajwa. All rights reserved.
//

#include "linked list.h"
int main(int argc, const char * argv[]) {
    numbers *sortedhead=NULL;
    int t;
    cin>>t;
    while(t--){
        string number;
        cin>>number;
        sortedhead=getinserted(getinsertedintolinkedlist(number), sortedhead);
    }
    
    cout<<"Result";
    displaysorted(sortedhead);
    return 0;
}
