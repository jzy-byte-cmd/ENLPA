#include "standard.h"


/*
CBasicDataIntro类: RdNew()->JuAdd()--AskAdd()->CfIntro()--RmAdd()->CgRecord()
                                   --exit    
*/
class CBasicDataIntro
{
public:
    void RdNew();
    //读取target文件夹内的所有文件

    void JuAdd();
    //判断target文件夹内是否有文件增加(判断有无新数据需要被引入)

    void AskAdd();
    //询问哪些数据需要被引入(是否需要被引入)

    void RmAdd();
    //撤销特定序列号的数据引入

    void CfIntro();
    //确认数据引入,并引入

    void CgRecord();
    //更新数据库更改记录


private:
    int m_counter=0;
    //读取list.txt的次数(新增的文件数)
    
    vector<string> m_context;
    //储存当前target目录下所有文件名
    
    map<int,string> m_index;

    vector<string> m_target;
    //将要导入数据库的文件

};
