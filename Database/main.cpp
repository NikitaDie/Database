#include <iostream>
#include "list.h";
using namespace std;

int main() {

    List data_base;
    string tmp;
    size_t index;

    const char* path = ".\\DataBase.txt";
    data_base.readFile(path);

    while (true) {
        cin >> tmp;

        if (tmp == "writeFile") {

            data_base.writeFile(path);
        }
        if (tmp == "readFile") {

            data_base.readFile(path);
        }
        if (tmp == "pushBack") {
            cout << "Value: ";
            cin >> tmp;
            data_base.pushBack(tmp);
        }
        else if (tmp == "pushFront") {
            cout << "Value: ";
            cin >> tmp;
            data_base.pushFront(tmp);
        }
        else if (tmp == "popBack") {
            data_base.popBack();
        }
        else if (tmp == "popFront") {
            data_base.popFront();
        }
        else if (tmp == "getSize") {
            cout << "Size: " << data_base.getSize();
        }
        else if (tmp == "printList") {
            cout << "List: " << endl;
            data_base.printList();
        }
        else if (tmp == "read") {
            cout << "Index: ";
            cin >> index;
            data_base.read(index);
        }
        else if (tmp == "search") {
            cout << "Value: ";
            cin >> tmp;
            data_base.search(tmp);
        }
        else if (tmp == "insert") {
            cout << "Value: ";
            cin >> tmp;
            cout << "Index: ";
            cin >> index;
            data_base.insert(index, tmp);
        }
        else if (tmp == "delete") {
            cout << "Index: ";
            cin >> index;
            data_base.deleteExactly(index);
        }
        else if (tmp == "exit") {
            data_base.writeFile(path);
            break;
        }

    }

}
