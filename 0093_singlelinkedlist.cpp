#include <iostream>
#include <string>
using namespace std;

class node 
{
public:
    int noMhs;
    node *next;
}

class LinkedList
{
    Node *START;

public:
    LinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukan Nomor Mahasiswa : ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\n Duplikasikan noMhs tidak diijinkan\n";
                return;
            }
            
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }


