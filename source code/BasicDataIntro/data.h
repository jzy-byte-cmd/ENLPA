#include "standard.h"


/*
CBasicDataIntro��: RdNew()->JuAdd()--AskAdd()->CfIntro()--RmAdd()->CgRecord()
                                   --exit    
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

    void RmAdd();
    //�����ض����кŵ���������

    void CfIntro();
    //ȷ����������,������

    void CgRecord();
    //�������ݿ���ļ�¼


private:
    int m_counter=0;
    //��ȡlist.txt�Ĵ���(�������ļ���)
    
    vector<string> m_context;
    //���浱ǰtargetĿ¼�������ļ���
    
    map<int,string> m_index;

    vector<string> m_target;
    //��Ҫ�������ݿ���ļ�

};
