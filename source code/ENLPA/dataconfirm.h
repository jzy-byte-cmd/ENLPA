#include "standard.h"

class dataconfirm//���ݺ˲���
{
    public:
void GetDataList();
//��ȡ�������ݵ�txt�ļ���

void GetData();
//��ȡ�������ݿ��еĵ���,���м��

bool DataCheck(const string str);
//����ַ����Ϸ���

void print();
//��ӡ���ɵ������ַ�������λ��,���˹����

    private:
vector<string> str_unvalid_location;
//������ܲ��Ϸ��ַ�����λ�õı���

vector<string> str_unvalid;
//������ܲ��Ϸ����ַ���

};