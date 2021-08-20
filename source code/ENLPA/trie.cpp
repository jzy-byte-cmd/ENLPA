#include "trie.h"

extern vector<string> words_of_tree;


void get_words()
{
    string Exe_location=_pgmptr,db_location,reading_file,
    reading_file_location,context;
    fstream read_list,read_file;
    for(int k=0;k<9;k++)//因为此程序固定名称为ENLPA.exe 这个字符串长为9,那么抹去9个元素得到工作目录
    {
        Exe_location.erase(Exe_location.end()-1);
    }
    db_location=Exe_location+"data\\DataBase\\";//数据库路径
    read_list.open("list.txt",ios::in);
    while(read_list.peek()!=EOF)//循环直到list.txt文件读完
    {
        getline(read_list,reading_file);
        if(reading_file!="last_location.txt")
        {
        reading_file_location=db_location+reading_file;
        read_file.open(reading_file_location,ios::in);
        while(read_file.peek()!=EOF)//循环直到数据库文件被读完//即2000行
        {
            getline(read_file,context);
            for(int sm=0;sm<context.size();sm++)     
            {
                if((int)context[sm]>=65&&(int)context[sm]<=90)//表明是大写字母
                {
                    context[sm]=(char)((int)context[sm]+32);//转为小写
                }
            }
            words_of_tree.push_back(context);
            context.clear();
        }
        read_file.close();
        }
    }
    read_list.close();
    return;
}