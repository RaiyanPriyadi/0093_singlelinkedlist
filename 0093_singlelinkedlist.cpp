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

        node *previous = START;
        node *current = START;

        while (current != NULL && nim > current->noMhs)
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasikan noMhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        nodeBaru->next = current;
        previous->next = nodeBaru;
    }

    bool listEmpty()
    {
        return (START == NULL);
    }

    bool search(int nim, node *&previous, node *&current)
    {
        previous = START;
        current = START;

        while (current != NULL && nim != current->noMhs)
        {
            previous = current;
            current = current->next;
        }

        return (current != NULL);
    }

    bool delNode(int nim)
    {
        node *current, *previous;

        if (!search(nim, previous, current)) 
            return false;

        if (current == START)
            START = START->next;
        else
            previous->next = current->next;
    
        delete current;
        return true;
    }

    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nList Kosong\n";
        }
        else
        {
            cout << "\nData di dalam list adalah: \n";
            node *currentNode = START;

            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
}

int main ()
{
    linkedList mhs;
    int nim;
    char ch;

    do
    {
        cout << "\nMenu" << endl;
        cout << "1. Menambahkan data ke dalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data didalam list" << endl;
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. Keluar" << endl;
        
        cout << "\nMasukan pilihan (1-5): ";
        cin >> ch;

        switch (ch)
        {
        case '1':
            mhs.addNode();
            break;
        case '2':
            if (mhs.listEmpty())
            {
                cout << "\nList Kosong\n";
                break;
            }

            cout << "\nMasukan no mahasiswa yang akan dihapus: ";
            cin >> nim;

            if (mhs.delNode(nim) == false)
                cout << "\nData tidak ditemukan" << endl;
            else
                cout << "\nData dengan no mahasiswa" << nim << " berhasil dihapus\n";
            break;

        case '3':
            mhs.traverse();
            break;
        
        case '4':
        {
            if (mhs.listyEmpty())
            {
                cout << "\nList Kosong\n";
                break;
            }

            node *previous, *current;
            cout << ""
        }
    }
    
}

