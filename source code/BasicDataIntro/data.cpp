//BDI.exe

#include "standard.h"
#include "data.h"

void CBasicDataIntro::RdNew()
{
    string Exe_location=_pgmptr;//��ȡ����ȫ·��
    string cmd_command;
    for(int k=0;k<7;k++)//��Ϊ�˳���̶�����ΪBDI.exe ����ַ�����Ϊ7,��ôĨȥ7��Ԫ�صõ�����Ŀ¼
    {
        Exe_location.erase(Exe_location.end()-1);
    }
    cmd_command="dir \""+Exe_location+"target\\\" /b /a-d >"+Exe_location+"list.txt";
    system(cmd_command.c_str());
    fstream file;
    file.open(Exe_location+"list.txt",ios::in);
    if(file.fail())
    {
        cout<<"fail!"<<endl;
        file.open(Exe_location+"list.txt",ios::in);
    }
    while(file.peek()!=EOF)
    {
        string temp_in;
        getline(file,temp_in);
        mV_context.push_back(temp_in);
        mN_counter++;
        temp_in.clear();
        //cout<<mN_counter<<endl;
    }
    cout<<mN_counter<<endl;
    for(int k=0;k<mV_context.size();k++)
    {
        cout<<mV_context[k]<<endl;
    }
    file.close();  
    return;
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
    return;
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
    return;
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
    file_write.open(temp_location_write,ios::out|ios::app);
    mV_changed.push_back(temp_location_write);
    bool valid=false;
    int code=0;
    for(int k=0;k<mV_target.size();k++)//ע��1 ��ʵ��
    {
        temp_location_read=location_read+mV_target[k];
        file_read.open(temp_location_read,ios::in);
        cout<<"��ȡλ��:"<<endl<<temp_location_read<<endl;
        cout<<"д��λ��"<<endl<<temp_location_write<<endl;
        while(file_read.peek()!=EOF)
        {
            getline(file_read,target_context);
            valid=this->CfValid(target_context,location_write,code);
            code=1;
            if(valid==true)//�������ĵ��������ݿ���û��,��ô���˵�����������ݿ�
            {
            file_write<<target_context<<endl;
            str_introduced.push_back(target_context);
            valid=false;
            target_context.clear();
            attN_target_L++;
            }
            else//����µ��ʺ����ݿ��еĵ����ظ�,�������˵���
            {
                target_context.clear();
                valid=false;
            }
            if(attN_target_L==2001)//һ��txt�ļ����������
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
    return;
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
    return;
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
    converter.str("");
    for(int k=0;k<mV_target.size();k++)//����������������ݵ� \record\Introduced
    {
        string move="copy \""+location+"target\\"+mV_target[k]+"\" \""+location+"record\\Introduced\\\"";
        system(move.c_str());
        //cout<<"probable error"<<endl;  debug
        //system("pause");
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
    return;
}

bool CBasicDataIntro::CfValid(const string str,string location,const int code)
{
    if (code == 0) //�������0  �������Ҫ�ռ����ݿ������еĵ���
    {
        vector<string> str_file; //ǰ��Ϊ���ݿ������е�ȫ������,����Ϊ���ݿ��е��ʷ������ļ�������
        fstream file_read;
        string cmd_command = "dir " + location + " " + "/b /a-d " + ">" + location + "current.txt";
        system(cmd_command.c_str());
        string location_current = location + "current.txt";
        string str_deliver, read_location;
        file_read.open(location_current, ios::in);
        while (file_read.peek() != EOF) //��ȡ���ݿ������е��ʷ������ļ���
        {
            getline(file_read, str_deliver);
            str_file.push_back(str_deliver);
            str_deliver.clear();
        }
        file_read.close();
        cmd_command="del "+location+"current.txt";
        system(cmd_command.c_str());
        vector<string>::iterator it=find(str_file.begin(),str_file.end(),"last_location.txt");
        str_file.erase(it);
        it=find(str_file.begin(),str_file.end(),"current.txt");
        str_file.erase(it);
        for (int k = 0; k < str_file.size(); k++) //��ȡ���ݿ������е���
        {
           // cout<<str_file[k]<<endl;//debug ��ӡ���ݿ������������ļ�(���ʷ���)����
            read_location = location + str_file[k];
            file_read.open(read_location, ios::in);
            while (file_read.peek() != EOF)
            {
                getline(file_read, str_deliver);
                str_stored.push_back(str_deliver);
                str_deliver.clear();
            }
            file_read.close();
        }
        /*
        for(int k=0;k<str_file.size();k++)//��ӡ�����ļ���
        {
            cout<<k<<endl;
            cout<<str_file[k]<<endl;
            system("pause");
        }
        for(int k=0;k<str_stored.size();k++)//debug  ��ӡ���еĵ���
        {
            cout<<"owned:"<<endl<<str_stored[k]<<endl;
        }
        */
    }
    cout<<"Ѱ�ҵ���:"<<endl<<str<<endl;
    if (find(str_stored.begin(), str_stored.end(), str) != str_stored.end()//����������ݿ����Ѿ���������ĵ���
    ||
    find(str_introduced.begin(),str_introduced.end(),str)!=str_introduced.end()) //������ֱ��������д����ظ����뵥��
    {
        cout<<"false"<<endl;
        return false; //������ӵ���ָʾ
    }
    else
    {
        cout<<"true"<<endl;
        return true;//��ӵ���ָʾ
    }
}

