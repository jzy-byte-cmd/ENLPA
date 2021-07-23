#include "standard.h"
#include "data.h"

void CBasicDataIntro::RdNew()
{
    system("BDI_operate1.cmd");//�����BDI_operate1.cmd�е�����
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
        cout<<"���������ݱ����,��3s���˳�����..."<<endl;
        Sleep(3000);
        exit(0);
    }
}

void CBasicDataIntro::AskAdd()
{
    for(int k=1;k<=mV_context.size();k++)//��context�ڵ������ַ����Ӽ�ֵ1��ʼ���θ���index
        {
            mM_index.insert({k,mV_context[k-1]});
        }
        cout<<"�������ݱ����,�����������ѡ��Ҫ�������ݿ������,���ö��ŷָ�(�ұ���ȷ������Ϊ���[Ӣ��])"<<endl;
        cout<<"��:ѡ�����1,2,3"<<endl<<"������"<<endl<<"1,2,3"<<endl<<"���Իس���β"<<endl;
        cout<<"��Ҳ��������all,������������ȫ���������ݿ�"<<endl<<endl;
        for(int k=1;k<=mM_index.size();k++)//��ӡindex�����еļ�ֵ��Ԫ��
        {
            cout<<k<<"."<<mM_index[k]<<endl;
        }
        bool coB_check=true;//���Ʊ���
        string command;
        while (coB_check)
        {
            int coN_getch = 0;
            cout << "������..." << endl
                 << endl;
            cin >> command;
            cout << "�������ָ��Ϊ:" << endl
                 << command << endl;
            cout << "���鿪ͷ��ĩβ��û�ж���ķ���(��������[���],�Լ������ַ�)" << endl
                 << "������ж���ķ��ſ��ܵ��³���������" << endl;
            cout << "����Y����ȷ��" << endl
                 << "����N������������" << endl;
            coN_getch = getch();
            if (coN_getch == 89 || coN_getch == 121) //�������y��
            {
                coB_check = false;
                continue; //����ѭ��������һ��
            }
            else
            {
                if(coN_getch==78||coN_getch==110)//�������n��
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
            int tempN_converted=0;//��ʱ���(int ����)���ֵı���
            for(int k=0;k<command.size();k++)
            {
                if(command[k]!=',')
                {
                    temp+=command[k];
                }
                else//�������������ǰ������ֽ���ת��
                {
                    converter<<temp;
                    converter>>tempN_converted;
                    mV_target.push_back(mM_index.at(tempN_converted));//ʹ��at����ֹԽ�����
                    temp.clear();
                    tempN_converted=0;
                    converter.clear();
                    converter.str("");
                }
            }
            converter<<temp;
            converter>>tempN_converted;
            mV_target.push_back(mM_index.at(tempN_converted));//ʹ��at����ֹԽ�����
            temp.clear();
            tempN_converted=0;
            converter.clear();
            converter.str("");
        }
        else
        {
            for(int k=1;k<=mM_index.size();k++)//���ȫ���������ݿ�  ֱ�ӱ���index ��Ŀ���ļ���ȫ������mV_target
            {
                mV_target.push_back(mM_index.at(k));
            }
        }
}


void CBasicDataIntro::CfIntro()
{
    fstream file,file_write,file_read;
    string location=_pgmptr;//��ȡ�������ڵ�ȫ·��
    string location_write,location_read,location_first,location_backup;
    for(int k=0;k<7;k++)//��Ϊ�˳���̶�����ΪBDI.exe ����ַ�����Ϊ7,��ôĨȥ7��Ԫ�صõ�����Ŀ¼
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
            cout << "��ʧ�ؼ��ļ�last_location.txt" << endl
                 << "�����Ƿ��˳�����?" << endl;
            cout << "��������״�ʹ�øó���,û���ļ�last_location.txt ��������" << endl;
            cout << "�����ʹ�ó���" << endl;
            while (coB_check_second)
            {
                cout << "����ʹ���밴Y,����N" << endl;
                coN_getch = getch();
                if (coN_getch == 89 || coN_getch == 121) //�������y��
                {
                    coB_check_second=false;
                    coB_check=false;
                    continue;
                }
                else
                {
                    if(coN_getch==78||coN_getch==110)//�������n��
                    {
                        cout<<"���������˳�..."<<endl;
                        Sleep(3000);
                        exit(0);
                    }
                    else//�û�û����ָʾ����
                    {
                        cout<<"�����ָ���ȷ"<<endl<<"����������"<<endl;
                        coN_getch=0;
                        continue;
                    }
                }
            }
        }
        file.open(location,ios::out|ios::app);//������״����г��� д�� 1��1
        file<<"1"<<endl<<"1"<<endl;
        file.close();
        file.open(location_first,ios::out|ios::app);//����1.txt
        file.close();
        file.open(location,ios::in);
    }
    string att_target,att_target_L;//string���͵� ����
    int attN_target_L=0,attN_target=0;
    getline(file,att_target);//��last_location�ж�ȡ2������ 
    getline(file,att_target_L);
    file.close();
    stringstream converter;
    converter<<att_target_L;//ͨ��stringstring ��2������ת��Ϊ���ͷ�������ж�����
    converter>>attN_target_L;
    converter.clear();
    converter.str("");              
    converter<<att_target;
    converter>>attN_target;
    converter.clear();
    converter.str("");
    string temp_location_read,temp_location_write;//��ʱ�Ķ�ȡ�ļ�λ�ú�д���ļ�λ��  �����ע��1
    string target_context,reset_target;
    temp_location_write=location_write+att_target+".txt";
    reset_target=att_target;
    string cmd_command="copy "+temp_location_write+" "+location_backup;//���ݼ������ĵ����ݿ��ļ�
    system(cmd_command.c_str());
    system("pause");
    file_write.open(temp_location_write,ios::out|ios::ate);
    mV_changed.push_back(temp_location_write);
    for(int k=0;k<mV_target.size();k++)//ע��1 ��ʵ��
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
                file_write.open(temp_location_write,ios::out|ios::app);//�������ĵ�
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
    cout << "����¼�������!" << endl;
    cout << "�Ѹ��ĵ�����:" << endl;
    for (int k = 0; k < mV_changed.size(); k++)
    {
        cout << k << "." << mV_changed[k] << endl;
    }
    cout << endl;
    cout << "�Ƿ񱣴����?" << endl;
    bool coB_check = true;
    int coN_getch = 0;
    while (coB_check)
    {
        cout << "�����밴Y,���������밴N" << endl;
        coN_getch = getch();
        if (coN_getch == 78 || coN_getch == 110) //��������
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
            for (int k = 0; k <= location_write.size(); k++) //Ĩȥlocation_write�� ǰ��Ŀո� ����ǩ po ����λ��239��
            {
                delete_command.erase(delete_command.end() - 1);
            }
            string save_command = "del " + delete_command;
            system(save_command.c_str()); //ɾ������
            cout << "�����ѳ���,�����˳�����..." << endl;
            Sleep(3000);
            exit(0);
        }
        else
        {
            if (coN_getch == 89 || coN_getch == 121) //����y�� �������
            {
                coB_check = false;
                for(int k=0;k<=location_write.size();k++)//Ĩȥlocation_write�� ǰ��Ŀո� ����ǩ po ����λ��239��
                {
                    reset_command.erase(reset_command.end()-1);
                }
                string save_command="del "+reset_command;
                system(save_command.c_str());//ɾ������
                location_write+="last_location.txt";
                fstream file;
                file.open(location_write,ios::out|ios::trunc);
                file<<attN_target<<endl<<attN_target_L<<endl;
                file.close();//���� last_location.txt �е����� 
                return; //ִ��CgRecord
            }
            else //�û�û��������ȷָ��
            {
                cout << "�������ָ�����" << endl
                     << "����������" << endl;
                continue;
            }
        }
    }
}

void CBasicDataIntro::CgRecord()
{
    string location=_pgmptr;//��ȡ�������ڵ�ȫ·��
    for(int k=0;k<7;k++)//��Ϊ�˳���̶�����ΪBDI.exe ����ַ�����Ϊ7,��ôĨȥ7��Ԫ�صõ�����Ŀ¼
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
            cout<<"��ȡ��¼����ʧ��,�Ƿ��˳�����?"<<endl;
            cout<<"������ǵ�1��ʹ�ñ�����,�����ʹ��"<<endl<<endl;
            while (coB_check_second)
            {
                cout << "����ʹ���밴Y,����N" << endl;
                coN_getch = getch();
                if (coN_getch == 89 || coN_getch == 121) //�������y��
                {
                    coB_check_second=false;
                    coB_check=false;
                    continue;
                }
                else
                {
                    if(coN_getch==78||coN_getch==110)//�������n��
                    {
                        cout<<"���������˳�..."<<endl;
                        Sleep(3000);
                        exit(0);
                    }
                    else//�û�û����ָʾ����
                    {
                        cout<<"�����ָ���ȷ"<<endl<<"����������"<<endl;
                        coN_getch=0;
                        continue;
                    }
                }
            }
        }
        file.open(location_record_index,ios::out|ios::app);//��������
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
    for(int k=0;k<mV_target.size();k++)//����������������ݵ� \record\Introduced
    {
        string move="copy "+location+"target\\"+mV_target[k]+" "+location+"record\\Introduced\\";
        system(move.c_str());
    }
    string del_target="rd "+location+"target /q /s";
    string mk_target="mkdir "+location+"target";
    system(del_target.c_str());//ɾ��targetĿ¼��Ŀ¼��������ļ�
    system(mk_target.c_str());//�½�targetĿ¼
    string location_record=location+"record\\"+index+".txt";
    file.open(location_record,ios::out|ios::app);
    // ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
    time_t now = time(0);
   
   // �� now ת��Ϊ�ַ�����ʽ
    char* dt = ctime(&now);
    file<<"����ʱ��:"<<endl<<dt<<endl<<endl;//д��ʱ��
    file<<"���������:"<<endl;
    for(int k=0;k<mV_target.size();k++)
    {
        file<<k<<". "<<mV_target[k]<<endl;
    }
    file<<endl;
    file<<"���ݿ����������ݵ�����������ĵ��ļ�:"<<endl;
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