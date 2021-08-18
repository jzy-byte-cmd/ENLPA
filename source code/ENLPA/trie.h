#include "standard.h"

class node
{
public:

int get_size();
//获取此节点字符串长度

void set_size(const int length);
//设定节点字符串长度

char get_character();
//获取此节点储存的字符

void set_character(const char context);
//设定节点储存的字符

vector<node> get_next_node();
//获取此节点分支

int get_next_node_amount();
//获取节点分支数量

void set_next_node(const node next);
//添加节点分支

node get_next_node(int num);
//访问next_node的值 num为数组元素下标

void set_code(const int status);
//设置状态码

int get_code();
//读取状态码

private:

int size;
//到这个节点为止,字符串的长度

char character;
//这个节点储存的字符

vector<node> next_node;
//这个节点的分支

int code=0;
//这个节点的状态码
//0 表明这个节点的所有分支节点中不包含word的字符,需要创建新的分支
//1 表明这个节点不是末尾节点(意思是词成功在子串中被找到了)

};

class tree
{
public:
node check_node(node current,int now,const string word);
//检查单词有没有包含在子串中,    ！！这里传入的参数必须是根节点！！now 必须是0
//因为要做递归

void insert_word(string word);
//插入单词

void insert_character(node current,const string word);
//用递归添加字符

void initialization();
//trie树初始化

void add_node();
//添加新节点

private:
node trie_tree;

};