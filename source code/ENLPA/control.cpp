#include "control.h"
#include "standard.h"

void Control::option()
{
    bool check = true;
    string Exe_location=_pgmptr;//��ȡ����ȫ·��
    for(int k=0;k<9;k++)//��Ϊ�˳���̶�����ΪENLPA.exe ����ַ�����Ϊ9,��ôĨȥ9��Ԫ�صõ�����Ŀ¼
        {
        Exe_location.erase(Exe_location.end()-1);
        }
        string cmd_command=Exe_location+"data\\BDI.exe";
        dataconfirm datacheck;
    while (check)
    {
        cout << "���й���:" << endl
             << "1.������������" << endl
             << "2.���ݼ��" << endl; //�����������
        cout << "��ѡ����..." << endl;
        int choose = _getch();
        switch (choose)
        {
        case 49:
        system(cmd_command.c_str());//���ó���BDI.exe
            break;
        case 50:
        datacheck.GetDataList();
        datacheck.GetData();
        datacheck.print();
            break;
        default:
            cout << "��������ȷ�����..." << endl;
            continue;
            break;
        }
    }
}

