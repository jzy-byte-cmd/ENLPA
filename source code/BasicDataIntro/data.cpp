#include "standard.h"
#include "data.h"

void CBasicDataIntro::RdNew()
{
    system("BDI_operate1.cmd");//�����BDI_operate1.cmd�е�����
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
        cout<<"���������ݱ����,��3s���˳�����..."<<endl;
        Sleep(3000);
        exit(0);
    }
}

void CBasicDataIntro::AskAdd()
{
    for(int k=1;k<=m_context.size();k++)//��context�ڵ������ַ����Ӽ�ֵ1��ʼ���θ���index
        {
            m_index.insert({k,m_context[k-1]});
        }
        cout<<"�������ݱ����,�����������ѡ��Ҫ�������ݿ������,���ö��ŷָ�(�ұ���ȷ������Ϊ���[Ӣ��])"<<endl;
        cout<<"��:ѡ�����1,2,3"<<endl<<"������"<<endl<<"1,2,3"<<endl<<"���Իس���β"<<endl;
        cout<<"��Ҳ��������all,������������ȫ���������ݿ�"<<endl<<endl;
        for(int k=1;k<=m_index.size();k++)//��ӡindex�����еļ�ֵ��Ԫ��
        {
            cout<<k<<"."<<m_index[k]<<endl;
        }
        bool co_check=true;//���Ʊ���
        string command;
        while (co_check)
        {
            int co_getch = 0;
            cout << "������..." << endl
                 << endl;
            cin >> command;
            cout << "�������ָ��Ϊ:" << endl
                 << command << endl;
            cout << "���鿪ͷ��ĩβ��û�ж���ķ���(��������[���],�Լ������ַ�)" << endl
                 << "������ж���ķ��ſ��ܵ��³���������" << endl;
            cout << "����Y����ȷ��" << endl
                 << "����N������������" << endl;
            co_getch = getch();
            if (co_getch == 89 || co_getch == 121) //�������y��
            {
                co_check = false;
                continue; //����ѭ��������һ��
            }
            else
            {
                if(co_getch==78||co_getch==110)
                {
                    continue;//��������
                }
                else//���û�а�����ȷ��ʾ����ָ��  �����ٶ�һ��ѭ���ж� �������ֱ�����û���������
                {
                    continue;
                }
            }
        }
        if(command.compare("all")!=0)//��Ŀ���ļ���ȫ������m_target
        {
            stringstream converter;//���ַ����͵ġ����֡� תΪ int ���͵������Ա��index�ļ�ֵ���Ͷ�Ӧ
            string temp;//��ʱ���(�ַ�������)���ֵı���
            int temp_converted=0;//��ʱ���(int ����)���ֵı���
            for(int k=0;k<command.size();k++)
            {
                if(command[k]!=',')
                {
                    temp+=command[k];
                }
                else//�������������ǰ������ֽ���ת��
                {
                    converter<<temp;
                    converter>>temp_converted;
                    m_target.push_back(m_index.at(temp_converted));//ʹ��at����ֹԽ�����
                    temp.clear();
                    temp_converted=0;
                }
            }
            converter<<temp;
            converter>>temp_converted;
            m_target.push_back(m_index.at(temp_converted));//ʹ��at����ֹԽ�����
            temp.clear();
            temp_converted=0;
        }
        else
        {
            for(int k=1;k<m_index.size();k++)//���ȫ���������ݿ�  ֱ�ӱ���index ��Ŀ���ļ���ȫ������m_target
            {
                m_target.push_back(m_index.at(k));
            }
        }
}


void CBasicDataIntro::CfIntro()
{
    ifstream in;
    ofstream out;
    string location=_pgmptr;//��ȡ�������ڵ�ȫ·��
    for(int k=0;k<7;k++)//��Ϊ�˳���̶�����ΪBDI.exe ����ַ�����Ϊ7,��ôĨȥ7��Ԫ�صõ�����Ŀ¼
    {
        location.erase(location.end()-1);
    }
    location+="DataBase\\last_location.txt";
    in.open(location,ios::in);
    if(in.fail())
    {
        cout<<"��ʧ�ؼ��ļ�last_location.txt"<<endl<<"�����Ƿ��˳�����?"<<endl;
        cout<<"";//2021��7��22�� 23:36
    }
}