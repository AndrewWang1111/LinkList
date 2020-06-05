#include "main.cpp"
#include "list.h"

Linklist::Linklist() {}
Linklist::~Linklist() {}

//initialize
int Linklist::NodeInit(const int& temp_age, const std::string& temp_string)
{
  if (LinkLength == 0)    //如果已经初始化，不能再次初始化
    {
      datanode* Real_head = new datanode;
      head                = Real_head;    //初始化一个节点，头节点和尾节点相同
      end                 = Real_head;
      Real_head->age      = temp_age;
      Real_head->name     = temp_string;
      end->next           = nullptr;
      Real_head->pre      = head;
      Real_head->index    = LinkLength++;    //表长度增加,节点索引号设置为当前表长度
      return 0;
    }
  else
    {
      cout << "链表已经初始化！" << endl;
      return -1;
    }
}

//加到尾部
int Linklist::NodePushBack(const int& temp_age, const std::string& temp_name)
{
  datanode* current_node = new datanode;
  end->next              = current_node;    //当前节点连接到原尾节点后
  current_node->pre      = end;             //原尾节点定义为当前节点的前置
  //current_node->next     = head;          //当前节点的下一个设置头节点，头尾相接
  current_node->next  = nullptr;         //当前节点的下一节点为空，头尾不相接
  end                 = current_node;    //当前节点定义为尾节点
  current_node->age   = temp_age;
  current_node->name  = temp_name;
  current_node->index = LinkLength++;    //表长度增加,节点索引号设置为当前表长度
  return 0;
}

//索引访问
datanode* Linklist::operator[](const int& temp_index)
{
  if (temp_index >= 0 && temp_index <= LinkLength)    //判断索引不超限
    {
      for (datanode* node = head; node != nullptr; node = node->next)
        {
          if (node->index == temp_index) return node;
        }
    }
}

//插入到中间
int Linklist::NodeInsert(const int& temp_index, const int& temp_age, const std::string& temp_name)
{
  datanode* temp_node = new datanode;
  temp_node->age      = temp_age;
  temp_node->name     = temp_name;

  if (temp_index >= LinkLength)    //判断插入位置超过链表尾，直接追加在最后
    {
      NodePushBack(temp_age, temp_name);
      return 0;
    }
  else if (temp_index == 0)    //判断插入头位置
    {
      for (datanode* node = head; node != nullptr; node = node->next)
        {
          node->index++;    //所有索引加1
        }
      temp_node->next = head;    //换头
      head            = temp_node;
      head->index     = 0;
      LinkLength++;
      return 0;
    }
  else    //插入中间位置
    {
      for (datanode* node = head; node != nullptr; node = node->next)
        {
          if (node->index >= temp_index)    //插入位置后面的索引加1
            {
              node->index++;
            }
        }
      for (datanode* node = head; node != nullptr; node = node->next)
        {
          if (node->index == temp_index - 1)
            {
              temp_node->next      = node->next;
              temp_node->pre       = node;
              node->next           = temp_node;
              temp_node->next->pre = temp_node;

              temp_node->index = temp_index;
              LinkLength++;
              return 0;
            }
        }
    }
}

//打印表
void Linklist::print()
{
  cout << endl;
  for (datanode* data = head; data != nullptr; data = data->next)
    {
      cout << "索引: " << data->index << "  年龄: " << data->age << "  姓名: " << data->name << endl;
    }
  cout << endl;
}

//查找

//按索引删除节点
int Linklist::NodeDelete(const int& temp_index)
{
  if (LinkLength == 2 && temp_index == 0)    //只剩头尾，不能删除头
    {
      cout << "链表已达到最小长度!" << endl;
    }
  else if (temp_index < 0 || temp_index > LinkLength - 1)    //非法索引
    {
      cout << endl;
      cout << "输入正确的索引!" << endl;
    }
  else if (temp_index == end->index)    //删除尾节点，换尾巴
    {
      end = end->pre;
      delete end->next;
      end->next = nullptr;
      LinkLength--;
    }

  else if (temp_index == head->index)    //删除头节点，换头
    {
      for (datanode* node = head; node != nullptr; node = node->next)
        {
          node->index--;
        }
      delete head;
      head = head->next;
      LinkLength--;
    }
  else    //删除中间节点
    {
      for (datanode* node = head; node != nullptr; node = node->next)
        {
          if (node->index == temp_index)    //找到索引位置
            {
              for (datanode* node2 = node; node2 != nullptr; node2 = node2->next)    //索引位置后面的索引减1
                {
                  node2->index--;
                }
              node->pre->next = node->next;
              node->next->pre = node->pre;
              delete node;
              break;
            }          
        }
      LinkLength--;
    }

  return 0;
}

int Linklist::find(int a)
{
  vector<int> ret;
  for (datanode* node = head; node != nullptr; node = node->next)
    {
      if (node->age == a)
        {
          ret.push_back(node->index);
        }
    }
  cout << endl;
  cout << "年龄 " << a << " 索引结果：";
  for (vector<int>::iterator iter = ret.begin(); iter != ret.end(); iter++)
    {
      cout << *iter << " ";
    }
  cout << endl;
  return 0;
}

int swap(Linklist* list, datanode* a, datanode* b)
{
  datanode* temp_node = new datanode;
  if (a->age > b->age)
    {
    }

  delete temp_node;
}

bool Check_int(std::string str)
{
  for (char x: str)
    {
      if (x < '0' || x > '9')
        {
          return false;
        }
    }
  return true;
}
