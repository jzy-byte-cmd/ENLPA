#include "control.h"
#include "standard.h"

void Control::option()
{
    bool check = true;
    string Exe_location=_pgmptr;//获取程序全路径
    for(int k=0;k<9;k++)//因为此程序固定名称为ENLPA.exe 这个字符串长为9,那么抹去9个元素得到工作目录
        {
        Exe_location.erase(Exe_location.end()-1);
        }
        string cmd_command=Exe_location+"data\\BDI.exe";
        dataconfirm datacheck;
    while (check)
    {
        cout << "现有功能:" << endl
             << "1.基本数据引入" << endl
             << "2.数据检查" << endl; //后续可以添加
        cout << "请选择功能..." << endl;
        int choose = _getch();
        switch (choose)
        {
        case 49:
        system(cmd_command.c_str());//调用程序BDI.exe
            break;
        case 50:
        datacheck.GetDataList();
        datacheck.GetData();
        datacheck.print();
            break;
        default:
            cout << "请输入正确的序号..." << endl;
            continue;
            break;
        }
    }
}

