#pragma once
#include <iostream>
#include <fstream>
using namespace std;

typedef struct Node {
    string value;
    struct Node* next;
    struct Node* prev;
} node;

typedef struct List {
    size_t size;
    node* head;
    node* tail;



    List(size_t size = 0, Node* bn = nullptr) {
        this->size = size;
        this->head = bn;
        this->tail = bn;
    }

    size_t getSize() {
        return this->size;
    }

    void deleteList() {

    };
    
    void cleanList() {
        while (this->size != 0) {
            popBack();
        }
    };

    void printList() {
        node* tmp = this->head;
        for (size_t i = 0; i < this->size; i++) {
            cout << i << ": " << tmp->value << endl;
            tmp = tmp->next;
        }
        cout << endl;
    }

    void pushFront(string value) {
        node* tmp = new node;
        tmp->value = value;
        tmp->next = this->head;
        tmp->prev = nullptr;


        if (this->head) {
            this->head->prev = tmp;
        }
        this->head = tmp;

        if (this->tail == NULL) {
            this->tail = tmp;
        }

        this->size++;
        cout << "Element: \"" << value << "\" has been pushed to the begining." << endl;
    };

    void popFront() {
        node* prev = this->head;
        this->head = this->head->next;

        if (this->head) {
            this->head->prev = NULL;
        }
        if (prev == this->tail) {
            this->tail = NULL;
        }

        free(prev);

        this->size--;
    };

    void pushBack(string value, bool out = true) {
        node* tmp = new node;
        tmp->value = value;
        tmp->next = nullptr;
        tmp->prev = this->tail;

        if (this->tail) {
            this->tail->next = tmp;
        }
        this->tail = tmp;

        if (this->head == NULL) {
            this->head = tmp;
        }

        this->size++;
        if (out) {
            cout << "Element: \"" << value << "\" has been pushed to the end." << endl;
        }
    };

    void popBack() {
        node* next = this->tail;
        this->tail = this->tail->prev;

        if (this->tail) {
            this->tail->next = NULL;
        }
        if (next == this->head) {
            this->head = NULL;
        }

        free(next);

        this->size--;
    };

    Node* get(size_t index) {
        Node* tmp = NULL;
        size_t i;

        if (index < this->size / 2) {
            i = 0;
            tmp = this->head;
            while (tmp && i < index) {
                tmp = tmp->next;
                i++;
            }
        }
        else {
            i = this->size - 1;
            tmp = this->tail;
            while (tmp && i > index) {
                tmp = tmp->prev;
                i--;
            }
        }

        return tmp;
    }

    string read(size_t i) {
        return get(i)->value;
    }

    size_t search(string value) {
        Node* tmp = this->head;

        for (size_t i = 0; i < this->size; i++) {
            tmp = tmp->next;
            if (tmp->value == value) {
                return i;
            }
        }
        cout << "Element wasn`t found." << endl;
    }

    void insert(size_t index, string value) {
        if (index == -1) {
            pushFront(value);
        }
        else if (index == size + 1) {
            pushBack(value);
        }
        else {

            Node* elm = NULL;
            Node* ins = NULL;
            elm = get(index);

            ins = new node;
            ins->value = value;
            ins->prev = elm;
            ins->next = elm->next;
            if (elm->next) {
                elm->next->prev = ins;
            }
            elm->next = ins;

            if (!elm->prev) {
                this->head = elm;
            }
            if (!elm->next) {
                this->tail = elm;
            }

            this->size++;
            cout << "Element: \"" << value << "\" was inserted in " << index << " position." << endl;
        }
    }

    void deleteExactly(size_t index) {
        Node* elm = NULL;
        string tmp = NULL;
        elm = get(index);

        if (elm->prev) {
            elm->prev->next = elm->next;
        }
        if (elm->next) {
            elm->next->prev = elm->prev;
        }

        tmp = elm->value;

        if (!elm->prev) {
            this->head = elm->next;
        }
        if (!elm->next) {
            this->tail = elm->prev;
        }

        free(elm);
        this->size--;

        cout << "Element: \"" << tmp << "\" from " << index << "position." << endl;
    }

    void writeFile(const char* path) {
        ofstream file;
        file.open(path);

        if (!file.is_open()) {
            cout << "Error: File can`t be open." << endl;
            return;
        }

        node* tmp = this->head;
        for (size_t i = 0; i < this->size; i++) {
            file << i << ": " << tmp->value << endl;
            tmp = tmp->next;
        }
        file.close();
    }

    void readFile(const char* path) {
        ifstream file;
        file.open(path);

        if (!file.is_open()) {
            cout << "Error: File can`t be open." << endl;
            return;
        }

        char ch;
        string s_tmp;
        file.seekg(3, ios_base::cur);
        while (file.get(ch)) {
            if (ch == '\n') {
                this->pushBack(s_tmp, false);
                s_tmp = "";
                file.seekg(3, ios_base::cur);
                continue;
            }

            s_tmp += ch;

        }
        file.close();
        cout << "Database was read succesfully." << endl;
    }
};
