#include "list.h"
using namespace std;

int main()
{
  system("chcp 65001 >>null");
  Linklist Mylist;
  Mylist.NodeInit(12, "NULL");

  Mylist.NodePushBack(2, "laowang");
  Mylist.NodePushBack(12, "laozhang");
  Mylist.NodePushBack(78, "laosun");
  Mylist.NodePushBack(4, "laohu");
  Mylist.NodePushBack(43, "laolan");
  Mylist.NodePushBack(12, "laofuck");
  Mylist.NodePushBack(21, "laolaolao");
  Mylist.NodePushBack(7, "qiqiguaugia");

  while (1)
    {
      cout << endl;
      cout << "0: 追加    "
           << "1: 插入    "
           << "2: 按年龄查找    "
           << "3: 打印表    "
           << "4: 按索引删除    "
           //<< "5: 按年龄排序    "
           << endl;
      cout << endl;

      int input;
      cin >> input;
      switch (input)
        {
          case 0:
            {
              int         age;
              std::string age_string;
              std::string name;
              cout << "输入年龄:";
              cin >> age_string;
              if (Check_int(age_string))
                {
                  age = atoi(age_string.c_str());
                  cin.clear();
                  cout << "输入姓名:";
                  cin >> name;
                  Mylist.NodePushBack(age, name);
                  cout << "长度:" << Mylist.LinkLength << endl;
                  break;
                }
              else
                {
                  cout << endl;
                  cout << "请输入正确的年龄!" << endl;
                  break;
                }
            }

          case 1:
            {
              std::string index_string;
              std::string age_string;
              std::string name;
              cout << "输入索引:";
              cin >> index_string;
              cout << "输入年龄:";
              cin >> age_string;
              cout << "输入姓名:";
              cin >> name;

              if (Check_int(index_string) && Check_int(age_string))
                {
                  cout << endl;
                  Mylist.NodeInsert(atoi(index_string.c_str()), atoi(age_string.c_str()), name);
                  cout << "长度:" << Mylist.LinkLength << endl;
                  break;
                }
              else
                {
                  cout << endl;
                  cout << "请输入正确的信息!" << endl;
                  break;
                }
            }
          case 3:
            {
              Mylist.print();
              break;
            }
          case 2:
            {
              std::string age;
              cout << endl;
              cout << "输入查询的年龄: ";
              cin >> age;
              if (Check_int(age))
                {
                  Mylist.find(atoi(age.c_str()));
                  cout << endl;
                  break;
                }
              else
                {
                  cout << endl;
                  cout << "请输入正确的信息!!" << endl;
                  break;
                }
            }
          case 4:
            {
              std::string index;
              cin.clear();
              cout << endl;
              cout << "删除的索引号:";
              cin >> index;
              if (Check_int(index))
                {
                  Mylist.NodeDelete(atoi(index.c_str()));
                  cout << endl;
                  cout << "长度:" << Mylist.LinkLength << endl;
                  cin.clear();
                  break;
                }
              else
                {
                  cout << endl;
                  cin.clear();
                  cout << endl;
                  cout << "请输入正确的信息!!" << endl;
                  break;
                }
            }

          default:
            break;
        }
    }
  return 0;
}
