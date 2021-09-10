#include "control.h"


vector<string> words_of_tree;

void Control::option()
{
    double time=0;  
    double counts=0;  
    LARGE_INTEGER nFreq;  
    LARGE_INTEGER nBeginTime;  
    LARGE_INTEGER nEndTime;  
    QueryPerformanceFrequency(&nFreq);  
    DicTree trie;
    elementaryhandle gaven;
    string consult;
    vector<string>::iterator it;
    bool check = true;
    string Exe_location = _pgmptr; //获取程序全路径
    for (int k = 0; k < 9; k++)    //因为此程序固定名称为ENLPA.exe 这个字符串长为9,那么抹去9个元素得到工作目录
    {
        Exe_location.erase(Exe_location.end() - 1);
    }
    string cmd_command = Exe_location + "data\\BDI.exe";
    dataconfirm datacheck, tree_get_word;
    while (check)
    {
        cout << "现有功能:" << endl
             << "1.基本数据引入" << endl
             << "2.数据检查" << endl
             << "3.构建字典树" << endl
             << "4.查询单词是否在库中" << endl
             <<"5.ENLP(英文分词)[trie] MMP"<<endl
             <<"6.ENLP(英文分词)[trie] MM"<<endl
             << "0.退出" << endl; //后续可以添加
        cout << "请选择功能..." << endl;
        int choose = _getch();
        switch (choose)
        {
        case 48:
            cout << "退出程序中..." << endl;
            Sleep(3000);
            exit(0);
            break;
        case 49:
            cout << cmd_command << endl
                 << endl;
            system(cmd_command.c_str()); //调用程序BDI.exe
            break;
        case 50:
            datacheck.GetDataList();
            datacheck.GetData();
            datacheck.print();
            break;
        case 51:
            cout << endl
                 << endl
                 << "开始 英文分词..." << endl;
            cout << "构建字典树中......." << endl;
            get_words();
            it = words_of_tree.begin();
            while (it != words_of_tree.end())
            {
                cout << *it << endl;
                trie.Insert(*it);
                it++;
            }
            cout << "字典树构建完毕..." << endl;
            break;
        case 52:
        cout << "请输入想要查询的单词..." << endl;
        cin >> consult;
        if (trie.Search(consult) == true)
        {
            cout << endl
                 << consult << "存在于数据库中." << endl;
        }
        else
        {
            cout << endl
                 << consult << "不存在于数据库中." << endl;
        }
        consult.clear();
        break;
        case 53://5
        QueryPerformanceCounter(&nBeginTime);
        gaven.read();
        gaven.MMP(trie);
        gaven.answer();
        QueryPerformanceCounter(&nEndTime);//停止计时  
        time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//计算程序执行时间单位为s  
        cout<<"程序5执行时间："<<time*1000<<"ms"<<endl;  
        break;
        case 54://6
        QueryPerformanceCounter(&nBeginTime);
        gaven.read();
        gaven.MM(trie);
        gaven.answer();
        QueryPerformanceCounter(&nEndTime);//停止计时  
        time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//计算程序执行时间单位为s  
        cout<<"程序6执行时间："<<time*1000<<"ms"<<endl;  
        break;
    default:
        cout << "请输入正确的序号..." << endl<<endl<<endl;
        continue;
        break;
        }
    }
}
