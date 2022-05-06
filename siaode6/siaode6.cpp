// siaode6.cpp : 
//1.	Дана последовательность из N чисел Х1,Х2,....,ХN. Вычислить значение выражения: Хn(Хn+Xn-1)(Хn+Xn-1+Xn-2)(Хn+Xn-1+Xn-2+Xn-3)... (Хn+Xn-1+Xn-2+...+X1). Массив не использовать.
//2.	Удалить из однонаправленного списка нули.

#include <iostream>
using namespace std;
struct Node //однонаправленный список
{
    Node* next;
    int key;
    Node(int n)
    {
        key = n;
        next = nullptr;
    }
};
void InsertNode(Node*& list, int n)
{
    Node* N1 = new Node(n);
    N1->next = list;
    list = N1;
}
void PrintNode(Node* list) //вывести
{
    while (list)
    {
        cout << list->key << " ";
        list = list->next;
    }
}
int Rekk(Node* list, int rek,int count)
{
    Node* buflist = list;
    int XN = list->key;
    bool flag = false;
    for (int i = 0; i < count; i++)
    {
        buflist = buflist->next;
        if (buflist == nullptr)
        {
            flag = true;
            break;
        }
        XN += buflist->key;        
    }
    if(!flag)
        rek = XN * rek;
    if (!flag)
        rek = Rekk(list, rek, count+1);
    return rek;
}
bool DeleteNull(Node* list) //удалить нули
{
    Node* pre = nullptr;
    Node* post = list;
    bool flag = false;
    while (list)
    {
        if (list->key == 0)
        {
            flag = true;
            post = post->next;
            if (pre)
            {
                delete pre->next;
                pre->next = post;
            }
            else
            {
                delete list;
                list = post;
            }
            break;
        }
        pre = list;
        post = post->next;
        list = list->next;
    }
    if (flag)
        return true;
    else return false;
}
int main()
{
    int X = 1;
    Node* list = new Node(1);
    for (int i = 0; i < 5; i++)
    {
        if (i == 3 || i==2)
        {
            X = 0;
            InsertNode(list, X); 
        }
        else
        {
            X += i + 1;
            InsertNode(list, X);
        }
    }
    PrintNode(list);
    cout << "Final value: " << Rekk(list, list->key, 1) << endl;
    bool flag = true;
    while (flag)
        flag = DeleteNull(list);
    PrintNode(list);
    cout << "Final value without null: " << Rekk(list, list->key, 1) << endl;
}

