#include "standard.h"


/*
CBasicDataIntro类: RdNew()->JuAdd()--AskAdd()->CfIntro()--RmAdd()--CgRecord()
                                   --exit               --exit   --exit
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

    void RmAdd(string reset_command, string location_write,int attN_target,int attN_target_L);
    //撤销数据引入

    void CfIntro();
    //确认数据引入,并引入

    void CgRecord();
    //更新数据库更改记录


private:
    int mN_counter=0;
    //读取list.txt的次数(新增的文件数)
    
    vector<string> mV_context;
    //储存当前target目录下所有文件名
    
    map<int,string> mM_index;

    vector<string> mV_target;
    //将要导入数据库的文件

    vector<string> mV_changed;
    //数据库中有更改的文件

};
