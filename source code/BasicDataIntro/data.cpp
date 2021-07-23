#include "standard.h"
#include "data.h"

void CBasicDataIntro::RdNew()
{
    system("BDI_operate1.cmd");//详情见BDI_operate1.cmd中的内容
    fstream file;
    file.open("list.txt",ios::in);
    if(file.fail())
    {
        file.open("list.txt",ios::in);
    }
    while(file.peek()!=EOF)
    {
        string temp_in;
        getline(file,temp_in);
        mV_context.push_back(temp_in);
        mN_counter++;
        temp_in.clear();
        cout<<mN_counter<<endl;
    }
    file.close();  
}

void CBasicDataIntro::JuAdd()
{
    if(mN_counter>0)
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
    for(int k=1;k<=mV_context.size();k++)//将context内的所有字符串从键值1开始依次赋给index
        {
            mM_index.insert({k,mV_context[k-1]});
        }
        cout<<"有新数据被添加,请输入序号以选择要移入数据库的数据,并用逗号分隔(且必须确定逗号为半角[英文])"<<endl;
        cout<<"例:选择序号1,2,3"<<endl<<"则输入"<<endl<<"1,2,3"<<endl<<"并以回车结尾"<<endl;
        cout<<"您也可以输入all,来将以下数据全部移入数据库"<<endl<<endl;
        for(int k=1;k<=mM_index.size();k++)//打印index中所有的键值和元素
        {
            cout<<k<<"."<<mM_index[k]<<endl;
        }
        bool coB_check=true;//控制变量
        string command;
        while (coB_check)
        {
            int coN_getch = 0;
            cout << "请输入..." << endl
                 << endl;
            cin >> command;
            cout << "您输入的指令为:" << endl
                 << command << endl;
            cout << "请检查开头和末尾有没有多余的符号(包括逗号[半角],以及任意字符)" << endl
                 << "如果含有多余的符号可能导致程序发生错误" << endl;
            cout << "按下Y键以确定" << endl
                 << "按下N键以重新输入" << endl;
            coN_getch = getch();
            if (coN_getch == 89 || coN_getch == 121) //如果按下y键
            {
                coB_check = false;
                continue; //跳出循环进行下一步
            }
            else
            {
                if(coN_getch==78||coN_getch==110)//如果按下n键
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
            int tempN_converted=0;//临时存放(int 类型)数字的变量
            for(int k=0;k<command.size();k++)
            {
                if(command[k]!=',')
                {
                    temp+=command[k];
                }
                else//如果遇到逗号则将前面的数字进行转换
                {
                    converter<<temp;
                    converter>>tempN_converted;
                    mV_target.push_back(mM_index.at(tempN_converted));//使用at来防止越界访问
                    temp.clear();
                    tempN_converted=0;
                    converter.clear();
                    converter.str("");
                }
            }
            converter<<temp;
            converter>>tempN_converted;
            mV_target.push_back(mM_index.at(tempN_converted));//使用at来防止越界访问
            temp.clear();
            tempN_converted=0;
            converter.clear();
            converter.str("");
        }
        else
        {
            for(int k=1;k<=mM_index.size();k++)//如果全部导入数据库  直接遍历index 将目标文件名全部推入mV_target
            {
                mV_target.push_back(mM_index.at(k));
            }
        }
}


void CBasicDataIntro::CfIntro()
{
    fstream file,file_write,file_read;
    string location=_pgmptr;//获取程序所在的全路径
    string location_write,location_read,location_first,location_backup;
    for(int k=0;k<7;k++)//因为此程序固定名称为BDI.exe 这个字符串长为7,那么抹去7个元素得到工作目录
    {
        location.erase(location.end()-1);
    }
    location_write=location+"DataBase\\";
    location_read=location+"target\\";
    location_first=location+"DataBase\\1.txt";
    location_backup=location+"DataBase\\Backup\\";
    location+="DataBase\\last_location.txt";
    file.open(location,ios::in);
    int coN_getch=0;
    bool coB_check=true,coB_check_second=true;
    if(file.fail())
    {
        while (coB_check)
        {
            cout << "丢失关键文件last_location.txt" << endl
                 << "请问是否退出程序?" << endl;
            cout << "如果您是首次使用该程序,没有文件last_location.txt 是正常的" << endl;
            cout << "请继续使用程序" << endl;
            while (coB_check_second)
            {
                cout << "继续使用请按Y,否则按N" << endl;
                coN_getch = getch();
                if (coN_getch == 89 || coN_getch == 121) //如果按下y键
                {
                    coB_check_second=false;
                    coB_check=false;
                    continue;
                }
                else
                {
                    if(coN_getch==78||coN_getch==110)//如果按下n键
                    {
                        cout<<"程序正在退出..."<<endl;
                        Sleep(3000);
                        exit(0);
                    }
                    else//用户没按照指示输入
                    {
                        cout<<"输入的指令不正确"<<endl<<"请重新输入"<<endl;
                        coN_getch=0;
                        continue;
                    }
                }
            }
        }
        file.open(location,ios::out|ios::app);//如果是首次运行程序 写入 1和1
        file<<"1"<<endl<<"1"<<endl;
        file.close();
        file.open(location_first,ios::out|ios::app);//创建1.txt
        file.close();
        file.open(location,ios::in);
    }
    string att_target,att_target_L;//string类型的 变量
    int attN_target_L=0,attN_target=0;
    getline(file,att_target);//从last_location中读取2个索引 
    getline(file,att_target_L);
    file.close();
    stringstream converter;
    converter<<att_target_L;//通过stringstring 将2个索引转化为整型方便后面判断行数
    converter>>attN_target_L;
    converter.clear();
    converter.str("");              
    converter<<att_target;
    converter>>attN_target;
    converter.clear();
    converter.str("");
    string temp_location_read,temp_location_write;//临时的读取文件位置和写入文件位置  详情见注解1
    string target_context,reset_target;
    temp_location_write=location_write+att_target+".txt";
    reset_target=att_target;
    string cmd_command="copy "+temp_location_write+" "+location_backup;//备份即将更改的数据库文件
    system(cmd_command.c_str());
    system("pause");
    file_write.open(temp_location_write,ios::out|ios::ate);
    mV_changed.push_back(temp_location_write);
    for(int k=0;k<mV_target.size();k++)//注解1 的实现
    {
        temp_location_read=location_read+mV_target[k];
        file_read.open(temp_location_read,ios::in);
        cout<<temp_location_read<<endl;
        cout<<temp_location_write<<endl;
        while(file_read.peek()!=EOF)
        {
            getline(file_read,target_context);
            file_write<<target_context<<endl;
            target_context.clear();
            attN_target_L++;
            if(attN_target_L==201)
            {
                attN_target++;
                converter<<attN_target;
                att_target=converter.str();
                cout<<att_target<<endl;
                converter.clear();
                converter.str("");
                attN_target_L=1;
                file_write.close();
                temp_location_write=location_write+att_target+".txt";
                file_write.open(temp_location_write,ios::out|ios::app);//创建新文档
                mV_changed.push_back(temp_location_write);
                continue;
            }
        }
        file_read.close();
    }
    file_write.close();
    file_read.close();
    //ok
po: cmd_command=location_backup+reset_target+".txt "+location_write;
    this->RmAdd(cmd_command,location_write,attN_target,attN_target_L);
}

void CBasicDataIntro::RmAdd(string reset_command,string location_write,int attN_target,int attN_target_L)
{
    cout << "数据录入已完成!" << endl;
    cout << "已更改的数据:" << endl;
    for (int k = 0; k < mV_changed.size(); k++)
    {
        cout << k << "." << mV_changed[k] << endl;
    }
    cout << endl;
    cout << "是否保存更改?" << endl;
    bool coB_check = true;
    int coN_getch = 0;
    while (coB_check)
    {
        cout << "保存请按Y,撤销更改请按N" << endl;
        coN_getch = getch();
        if (coN_getch == 78 || coN_getch == 110) //撤销更改
        {
            string delete_command;
            for (int k = 0; k < mV_changed.size(); k++)
            {
                delete_command = "del " + mV_changed[k];
                system(delete_command.c_str());
            }
            delete_command = reset_command;
            reset_command = "copy " + reset_command;
            system(reset_command.c_str());
            for (int k = 0; k <= location_write.size(); k++) //抹去location_write和 前面的空格 见标签 po 大致位于239行
            {
                delete_command.erase(delete_command.end() - 1);
            }
            string save_command = "del " + delete_command;
            system(save_command.c_str()); //删除备份
            cout << "更改已撤销,即将退出程序..." << endl;
            Sleep(3000);
            exit(0);
        }
        else
        {
            if (coN_getch == 89 || coN_getch == 121) //按下y键 保存更改
            {
                coB_check = false;
                for(int k=0;k<=location_write.size();k++)//抹去location_write和 前面的空格 见标签 po 大致位于239行
                {
                    reset_command.erase(reset_command.end()-1);
                }
                string save_command="del "+reset_command;
                system(save_command.c_str());//删除备份
                location_write+="last_location.txt";
                fstream file;
                file.open(location_write,ios::out|ios::trunc);
                file<<attN_target<<endl<<attN_target_L<<endl;
                file.close();//更新 last_location.txt 中的内容 
                return; //执行CgRecord
            }
            else //用户没有输入正确指令
            {
                cout << "您输入的指令错误" << endl
                     << "请重新输入" << endl;
                continue;
            }
        }
    }
}

void CBasicDataIntro::CgRecord()
{
    string location=_pgmptr;//获取程序所在的全路径
    for(int k=0;k<7;k++)//因为此程序固定名称为BDI.exe 这个字符串长为7,那么抹去7个元素得到工作目录
    {
        location.erase(location.end()-1);
    }
    string location_record_index=location+"record\\index.txt";
    fstream file;
    file.open(location_record_index,ios::in);
    int coN_getch=0;
    bool coB_check=true,coB_check_second=true;
    if(file.fail())
    {
        while (coB_check)
        {
            cout<<"读取记录索引失败,是否退出程序?"<<endl;
            cout<<"如果您是第1次使用本程序,请继续使用"<<endl<<endl;
            while (coB_check_second)
            {
                cout << "继续使用请按Y,否则按N" << endl;
                coN_getch = getch();
                if (coN_getch == 89 || coN_getch == 121) //如果按下y键
                {
                    coB_check_second=false;
                    coB_check=false;
                    continue;
                }
                else
                {
                    if(coN_getch==78||coN_getch==110)//如果按下n键
                    {
                        cout<<"程序正在退出..."<<endl;
                        Sleep(3000);
                        exit(0);
                    }
                    else//用户没按照指示输入
                    {
                        cout<<"输入的指令不正确"<<endl<<"请重新输入"<<endl;
                        coN_getch=0;
                        continue;
                    }
                }
            }
        }
        file.open(location_record_index,ios::out|ios::app);//创建索引
        file<<"1"<<endl;
        file.close();
        file.open(location_record_index,ios::in);
    }
    string index;
    int N_index;
    getline(file,index);
    file.close();
    stringstream converter;
    converter<<index;
    converter>>N_index;
    converter.clear();
    for(int k=0;k<mV_target.size();k++)//将引入的数据做备份到 \record\Introduced
    {
        string move="copy "+location+"target\\"+mV_target[k]+" "+location+"record\\Introduced\\";
        system(move.c_str());
    }
    string del_target="rd "+location+"target /q /s";
    string mk_target="mkdir "+location+"target";
    system(del_target.c_str());//删除target目录及目录里的所有文件
    system(mk_target.c_str());//新建target目录
    string location_record=location+"record\\"+index+".txt";
    file.open(location_record,ios::out|ios::app);
    // 基于当前系统的当前日期/时间
    time_t now = time(0);
   
   // 把 now 转换为字符串形式
    char* dt = ctime(&now);
    file<<"当地时间:"<<endl<<dt<<endl<<endl;//写入时间
    file<<"引入的数据:"<<endl;
    for(int k=0;k<mV_target.size();k++)
    {
        file<<k<<". "<<mV_target[k]<<endl;
    }
    file<<endl;
    file<<"数据库中由于数据的引入而被更改的文件:"<<endl;
    for(int k=0;k<mV_changed.size();k++)
    {
        file<<k<<". "<<mV_changed[k]<<endl;
    }
    file<<endl;
    file.close();
    N_index++;
    file.open(location_record_index,ios::out|ios::trunc);
    file<<N_index<<endl;
    file.close();
}