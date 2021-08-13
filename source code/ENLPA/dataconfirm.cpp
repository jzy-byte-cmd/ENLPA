#include "standard.h"
#include "dataconfirm.h"

void dataconfirm::GetDataList()
{
    string Exe_location=_pgmptr,db_location,cmd_command;
    for(int k=0;k<9;k++)//��Ϊ�˳���̶�����ΪENLPA.exe ����ַ�����Ϊ9,��ôĨȥ9��Ԫ�صõ�����Ŀ¼
    {
        Exe_location.erase(Exe_location.end()-1);
    }
    db_location=Exe_location+"data\\DataBase\\";//���ݿ�·��
    cmd_command="dir \""+db_location+"\" /b /a-d >list.txt";//�������ݿ��������ļ�������ǰĿ¼�µ�list.txt�ļ�
    system(cmd_command.c_str());
    return;
}


void dataconfirm::GetData()
{
    fstream read_list,read_file;
    string Exe_location=_pgmptr,db_location,reading_file,reading_file_location,
    str_need_check;
    stringstream converter;
    int index=1;//�����ַ�����λ��
    for(int k=0;k<9;k++)//��Ϊ�˳���̶�����ΪENLPA.exe ����ַ�����Ϊ9,��ôĨȥ9��Ԫ�صõ�����Ŀ¼
    {
        Exe_location.erase(Exe_location.end()-1);
    }
    db_location=Exe_location+"data\\DataBase\\";//���ݿ�·��
    read_list.open("list.txt",ios::in);
    while(read_list.peek()!=EOF)//ѭ��ֱ��list.txt�ļ�����
    {
        getline(read_list,reading_file);
        reading_file_location=db_location+reading_file;
        read_file.open(reading_file_location,ios::in);
        index=1;
        while(read_file.peek()!=EOF)//ѭ��ֱ�����ݿ��ļ�������//��2000��
        {
            getline(read_file,str_need_check);
            bool result=this->DataCheck(str_need_check);//��鲢�õ����
            if(result==false)//�����������ַ���������
            {
                str_unvalid.push_back(str_need_check);
                converter<<index;//����������ת��Ϊ�ַ���
                str_unvalid_location.push_back(reading_file+"  "+converter.str());
                converter.clear();
                converter.str("");//���ת����
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
        if((int)str[k]<97||(int)str[k]>122)//�����ַ�����Сд��ĸ,a��ascii��Ϊ97,zΪ122
        {
            if((int)str[k]<65||(int)str[k]>90)//�����ַ��Ȳ���Сд��ĸҲ���Ǵ�д��ĸ,A 65,Z 90
            {
                return false;//������ѯ
            }
        }
    }
    return true;
}

void dataconfirm::print()//��ӡ�����ַ���
{
    for(int k=0;k<str_unvalid.size();k++)
    {
        cout<<str_unvalid[k]<<endl;
        cout<<str_unvalid_location[k]<<endl;
    }
    return;
}