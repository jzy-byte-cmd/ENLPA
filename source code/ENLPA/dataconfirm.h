#include "standard.h"

class dataconfirm//数据核查类
{
    public:
void GetDataList();
//获取所有数据的txt文件名

void GetData();
//读取所有数据库中的单词,进行检查

bool DataCheck(const string str);
//检查字符串合法性

void print();
//打印可疑的问题字符串和其位置,供人工检查

    private:
vector<string> str_unvalid_location;
//储存可能不合法字符串的位置的变量

vector<string> str_unvalid;
//储存可能不合法的字符串

};