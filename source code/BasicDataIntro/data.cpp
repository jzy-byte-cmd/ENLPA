#include "standard.h"
#include "data.h"

void CBasicDataIntro::RdNew()
{
    system("BDI_operate1.cmd");//详情见BDI_operate1.cmd中的内容
    ifstream in;
    in.open("list.txt",ios::in);
    if(in.fail())
    {
        in.open("list.txt",ios::in);
    }
    while(in)
    {
        string temp_in;
        getline(in,temp_in);
        m_context.push_back(temp_in);
        m_counter++;
        temp_in.clear();
        cout<<m_counter<<endl;
    }
    m_counter--;
    m_context.pop_back();
    in.close();  
}

void CBasicDataIntro::JuAdd()
{
    if(m_counter>0)
    {
        this->AskAdd();
    }
    else
    {
        cout<<"暂无新数据被添加,在3s内退出程序..."<<endl;
        Sleep(3000);
        exit(0);
    }
}

void CBasicDataIntro::AskAdd()
{
    for(int k=1;k<=m_context.size();k++)//将context内的所有字符串从键值1开始依次赋给index
        {
            m_index.insert({k,m_context[k-1]});
        }
        cout<<"有新数据被添加,请输入序号以选择要移入数据库的数据,并用逗号分隔(且必须确定逗号为半角[英文])"<<endl;
        cout<<"例:选择序号1,2,3"<<endl<<"则输入"<<endl<<"1,2,3"<<endl<<"并以回车结尾"<<endl;
        cout<<"您也可以输入all,来将以下数据全部移入数据库"<<endl<<endl;
        for(int k=1;k<=m_index.size();k++)//打印index中所有的键值和元素
        {
            cout<<k<<"."<<m_index[k]<<endl;
        }
        bool co_check=true;//控制变量
        string command;
        while (co_check)
        {
            int co_getch = 0;
            cout << "请输入..." << endl
                 << endl;
            cin >> command;
            cout << "您输入的指令为:" << endl
                 << command << endl;
            cout << "请检查开头和末尾有没有多余的符号(包括逗号[半角],以及任意字符)" << endl
                 << "如果含有多余的符号可能导致程序发生错误" << endl;
            cout << "按下Y键以确定" << endl
                 << "按下N键以重新输入" << endl;
            co_getch = getch();
            if (co_getch == 89 || co_getch == 121) //如果按下y键
            {
                co_check = false;
                continue; //跳出循环进行下一步
            }
            else
            {
                if(co_getch==78||co_getch==110)
                {
                    continue;//重新输入
                }
                else//如果没有按照正确提示输入指令  避免再多一层循环判断 保险起见直接让用户重新输入
                {
                    continue;
                }
            }
        }
        if(command.compare("all")!=0)//将目标文件名全部推入m_target
        {
            stringstream converter;//将字符串型的“数字” 转为 int 类型的数字以便和index的键值类型对应
            string temp;//临时存放(字符串类型)数字的变量
            int temp_converted=0;//临时存放(int 类型)数字的变量
            for(int k=0;k<command.size();k++)
            {
                if(command[k]!=',')
                {
                    temp+=command[k];
                }
                else//如果遇到逗号则将前面的数字进行转换
                {
                    converter<<temp;
                    converter>>temp_converted;
                    m_target.push_back(m_index.at(temp_converted));//使用at来防止越界访问
                    temp.clear();
                    temp_converted=0;
                }
            }
            converter<<temp;
            converter>>temp_converted;
            m_target.push_back(m_index.at(temp_converted));//使用at来防止越界访问
            temp.clear();
            temp_converted=0;
        }
        else
        {
            for(int k=1;k<m_index.size();k++)//如果全部导入数据库  直接遍历index 将目标文件名全部推入m_target
            {
                m_target.push_back(m_index.at(k));
            }
        }
}


void CBasicDataIntro::CfIntro()
{
    ifstream in;
    ofstream out;
    string location=_pgmptr;//获取程序所在的全路径
    for(int k=0;k<7;k++)//因为此程序固定名称为BDI.exe 这个字符串长为7,那么抹去7个元素得到工作目录
    {
        location.erase(location.end()-1);
    }
    location+="DataBase\\last_location.txt";
    in.open(location,ios::in);
    if(in.fail())
    {
        cout<<"丢失关键文件last_location.txt"<<endl<<"请问是否退出程序?"<<endl;
        cout<<"";//2021年7月22日 23:36
    }
}