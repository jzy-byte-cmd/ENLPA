#include "standard.h"
#include "dataconfirm.h"

void dataconfirm::GetDataList()
{
    string Exe_location=_pgmptr,db_location,cmd_command;
    for(int k=0;k<9;k++)//因为此程序固定名称为ENLPA.exe 这个字符串长为9,那么抹去9个元素得到工作目录
    {
        Exe_location.erase(Exe_location.end()-1);
    }
    db_location=Exe_location+"data\\DataBase\\";//数据库路径
    cmd_command="dir \""+db_location+"\" /b /a-d >list.txt";//导出数据库内所有文件名至当前目录下的list.txt文件
    system(cmd_command.c_str());
    return;
}


void dataconfirm::GetData()
{
    fstream read_list,read_file;
    string Exe_location=_pgmptr,db_location,reading_file,reading_file_location,
    str_need_check;
    stringstream converter;
    int index=1;//问题字符串的位置
    for(int k=0;k<9;k++)//因为此程序固定名称为ENLPA.exe 这个字符串长为9,那么抹去9个元素得到工作目录
    {
        Exe_location.erase(Exe_location.end()-1);
    }
    db_location=Exe_location+"data\\DataBase\\";//数据库路径
    read_list.open("list.txt",ios::in);
    while(read_list.peek()!=EOF)//循环直到list.txt文件读完
    {
        getline(read_list,reading_file);
        reading_file_location=db_location+reading_file;
        read_file.open(reading_file_location,ios::in);
        index=1;
        while(read_file.peek()!=EOF)//循环直到数据库文件被读完//即2000行
        {
            getline(read_file,str_need_check);
            bool result=this->DataCheck(str_need_check);//检查并得到结果
            if(result==false)//如果检查下来字符串有问题
            {
                str_unvalid.push_back(str_need_check);
                converter<<index;//将数字索引转化为字符串
                str_unvalid_location.push_back(reading_file+"  "+converter.str());
                converter.clear();
                converter.str("");//清空转化器
            }
            index++;
        }
        read_file.close();
    }
    read_list.close();
    return;
}

bool dataconfirm::DataCheck(string str)
{
    for(int k=0;k<str.size();k++)
    {
        if((int)str[k]<97||(int)str[k]>122)//表明字符不是小写字母,a的ascii码为97,z为122
        {
            if((int)str[k]<65||(int)str[k]>90)//表明字符既不是小写字母也不是大写字母,A 65,Z 90
            {
                if((int)str[k]!=45)//如果字符不是-       -(ascii) 45
                {
                return false;//发出质询
                }
            }
        }
    }
    return true;
}

void dataconfirm::print()//打印可疑字符串
{
    fstream write_file;
    cout<<"开始打印可疑字符串..."<<endl<<endl;
    for(int k=0;k<str_unvalid.size();k++)
    {
        cout<<str_unvalid[k]<<endl;
        cout<<str_unvalid_location[k]<<endl;
    }
    cout<<"可疑字符串打印完毕."<<endl;
    if(str_unvalid.size()==0&&str_unvalid_location.size()==0)
    {
        cout<<"无可疑字符串."<<endl;
    }
    cout<<endl<<"所有的可疑字符串及其位置将会被打印到bad_char.txt内"<<endl;
    write_file.open("bad_char.txt",ios::trunc|ios::out);
    for(int k=0;k<str_unvalid.size();k++)
    {
        write_file<<str_unvalid[k]<<endl<<str_unvalid_location[k]<<endl;
    }
    write_file.close();
    str_unvalid.clear();
    str_unvalid_location.clear();
    return;
}