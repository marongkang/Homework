#include  <iostream>
using  namespace  std;
class  myArrayList
{
public:
    myArrayList(int  size = 0);
    myArrayList(const  myArrayList& t);
    //~myArrayList(void);
    void  Input(int  n);
    void  Output();
    void  SortBySelect();//选择排序
    void  Append(int  num);//在最后插入一个数num
private:
    int* m_arr;
    int  m_size;
    int  m_len;
};
myArrayList::myArrayList(int  size)
{
    m_size = size;
    m_len = size;
    m_arr = new int[size];
}
myArrayList::myArrayList(const  myArrayList& t)
{
    m_size = t.m_size;
    m_len = t.m_len;
    m_arr = t.m_arr;
}
void myArrayList::SortBySelect()
{
    for (int i = 0; i < m_len; i++) 
    {
        for (int j = i; j < m_len; j++)
        {
            if (m_arr[i] > m_arr[j]) 
            {
                int temp = m_arr[i];
                m_arr[i] = m_arr[j];
                m_arr[j] = temp;
            }
        }
    }
}
void  myArrayList::Append(int  num) 
{
    m_len++;
    m_arr[m_len - 1] = num;
}


void  myArrayList::Input(int  n)
{
    this->m_len = n;
    for (int i = 0; i < this->m_len; i++)
        cin >> this->m_arr[i];
}
void  myArrayList::Output()
{
    cout << endl;
    for (int i = 0; i < this->m_len; i++)
        cout << this->m_arr[i] << "    ";
    cout << endl;
}
int  main()
{
    myArrayList  list1(20);
    list1.Input(5);
    list1.SortBySelect();
    list1.Output();
    list1.Append(8);
    list1.Output();
    myArrayList  list2(list1);
    list2.Output();
}