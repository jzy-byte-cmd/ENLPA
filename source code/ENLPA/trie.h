#include "standard.h"
#include <stdexcept>

struct Node
{
    bool isWord;//判断当前字母是否为单词的最后一个字母标识
    Node *next[50];//26叉  改为100
    Node()
    {
        isWord = false;
        for(int i = 0;i != 50; ++ i)
        {
            next[i] = NULL;//清空26叉  改为100
        }
    }
};

void get_words();

class DicTree
{
public:
    Node *root;//根节点
    DicTree()
    {
        root = NULL;//在构造函数中初始化
    }
    void Insert(string str)
    {
        if (!root)
        {
            root = new Node;//如果root现在不空，需要重新开辟一个根节点
        }
        Node *head = root;//根节点不能变，找一个新的指针指向根节点方便操作
        for(long int i = 0;i != str.length(); ++ i)
        {
            int num = str[i] - 'a';//获取当前字母应该存储的位置
            if (head ->next[num] == NULL)
            {
                head->next[num] = new Node;
            }
            head = head->next[num];
        }
        head->isWord = true;
    }
    bool Search(string str)
    {
        Node *head = root;
        for (long int i = 0; i != str.length(); ++ i)
        {
            int num = str[i] - 'a';
            if(num<0)
            {
                return false;
            }
            if (head->next[num] == NULL)
            {
                return false;
            }
            else
            {
                head = head->next[num];
            }
        }
        return true;
    }
};

