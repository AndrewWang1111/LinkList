#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <iomanip>
#include <vector>
bool Check_int(std::string str);
struct datanode
{
  int         index = -1;
  int         age   = -1;
  std::string name  = "null";
  datanode*   next;    //指向下一节点
  datanode*   pre;     //指向上一节点
};

class Linklist
{
public:
  Linklist();
  ~Linklist();
  int       NodeInit(const int&, const std::string&);            //初始化
  int       LinkLength = 0;                                      //链表长度
  datanode* head       = nullptr;                                //头节点
  datanode* end        = nullptr;                                //尾节点
  int       NodeInsert(const int& index, const int& age, const std::string& name);    //中间插入
  int       NodePushBack(const int& age, const std::string& name);                    //末尾插入
  int       NodeDelete(const int& index);
  datanode* operator[](const int& index);
  void      print();
  int       find(int age);
  int       sort_by_age();
  int friend swap(Linklist*, datanode*, datanode*);
};

#endif    // LIST_H
