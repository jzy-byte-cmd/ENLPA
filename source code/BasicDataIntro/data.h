//BDI.exe
#include "standard.h"


/*
CBasicDataIntro��: RdNew()->JuAdd()--AskAdd()->[CfIntro()|CfValid()]--RmAdd()--CgRecord()
                                   --exit               --exit   --exit
*/
class CBasicDataIntro
{
public:
    void RdNew();
    //��ȡtarget�ļ����ڵ������ļ�

    void JuAdd();
    //�ж�target�ļ������Ƿ����ļ�����(�ж�������������Ҫ������)

    void AskAdd();
    //ѯ����Щ������Ҫ������(�Ƿ���Ҫ������)

    void RmAdd(string reset_command, string location_write,int attN_target,int attN_target_L);
    //������������

    void CfIntro();//��CfValid()����
    //ȷ����������,������
    bool CfValid(const string str,string location,const int code);//��CfIntro()����
    //�������������Ƿ����ʷ�����ظ�

    void CgRecord(); 
    //�������ݿ���ļ�¼  


private:
    int mN_counter=0;
    //��ȡlist.txt�Ĵ���(�������ļ���)
    
    vector<string> mV_context;
    //���浱ǰtargetĿ¼�������ļ���
    
    map<int,string> mM_index;

    vector<string> mV_target;
    //��Ҫ�������ݿ���ļ�

    vector<string> mV_changed;
    //���ݿ����и��ĵ��ļ�

    vector<string> str_stored;
    //���ݿ��������Ѵ���ĵ���

    vector<string> str_introduced;
    //ĳһ����������е���

};
