//
//  main.cpp
//  Hashing_2
//
//  Created by Администратор on 5/20/13.
//  Copyright (c) 2013 Администратор. All rights reserved.
//

#include <iostream>


struct Item {
    Item *next;
    Item *prev;
    int key;
};

#pragma mark - Declare Vars
Item* dic = new Item[9];

#pragma mark - Declare Functions
void insert(int	key);
int hash(int k, int M);

#pragma mark - Main
int main(int argc, const char * argv[]) {
    // insert code here...
    insert(5);
    insert(28);
    insert(19);
    insert(15);
    insert(20);
    insert(33);
    insert(12);
    insert(17);
    insert(10);
    return 0;
}

#pragma mark - Define Functions
void insert(int key) {
    Item *item = new Item();
    item->key = key;
    
    Item *_item = &dic[hash(key, 9)];
    if (_item->key == 0) {
        dic[hash(key, 9)] = *item;
    } else {
        while (_item->next != NULL) {
            _item = _item->next;
        }
        _item->next = item;
    }
}

int hash(int k, int M) {
    return k % 9;
}