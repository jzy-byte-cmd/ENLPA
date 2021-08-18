#include "trie.h"

//---------tree

void tree::insert_word(string word)
{
    node location;
    location=this->check_node(trie_tree,0,word);
    if(location.get_code()==0)//如果状态码为0,需要创建新分支
    {
        insert_character(location,word);
    }
    return;
}

void tree::insert_character(node current,const string word)
{
    if(current.get_size()!=word.size())//表明word还未被完整加入
    {
        node next;
        next.set_size(current.get_size()+1);
        next.set_character(word[current.get_size()]);
        current.set_next_node(next);
        insert_character(next,word);//递归直到word被完全插入
    }
    return;
}

//这段代码可能(大概率,因为找不到合适的词)用注释无法解释清楚,有疑惑可以和我聊   --金哲宇
//我会对这个trie树专门画图解释
node tree::check_node(node node_current,int now,const string word)//important and the hardest
{
    for(int k=0;k<node_current.get_next_node_amount();k++)
    {
        if (word[now] == (node_current.get_next_node(k)).get_character()) //表明找到包含该字符的节点
        {
            if (now == word.size()-1) //表明已检查了word的最后一个字符,word在子串中被发现,那么放弃添加节点
            {
                node_current.set_code(1);//设置状态码
                return node_current;
            }
            now++;                                        //继续检查单词的下一个字符
            node_current = node_current.get_next_node(k); //递归
            this->check_node(node_current, now, word);    //递归直到找不到节点,或者遇到末尾节点
            //此时node_current.get_next_node_amount()为0,for循环根本不会执行
        }
    }
    //跳出for循环说明分支节点没法匹配word的某个字符
    //表明word不在子串中
    return node_current;
}

void tree::initialization()
{
    trie_tree.set_size(0);
    //设置根节点长度
    trie_tree.set_character('#');
    //设置根节点字符,只是起标识作用
    return;
}

//tree end



//-----------node


int node::get_size()
{
    return size;
}

void node::set_size(const int length)
{
    size=length;
    return;
}

char node::get_character()
{
    return character;
}

void node::set_character(const char context)
{
    character=context;
    return;
}

vector<node> node::get_next_node()
{
    return next_node;
}

int node::get_next_node_amount()
{
    return next_node.size();
}

void node::set_next_node(const node next)
{
    next_node.push_back(next);
    return;
}

node node::get_next_node(int num)
{
return next_node[num];
}

void node::set_code(const int status)
{
    code=status;
    return;
}

int node::get_code()
{
    return code;
}

//node end
