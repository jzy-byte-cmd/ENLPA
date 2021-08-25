#include "ElementaryHandle.h"


void elementaryhandle::MMP(DicTree &trie)
{
    string big;
    int error=0;
    string find;
    for(int k=0;k<target_sentence.size();k++)
    {
        for(int l=0;l<target_sentence[k].size();l++)
        {
            big+=target_sentence[k][l];
            if((int)target_sentence[k][l]>=65&&(int)target_sentence[k][l]<=90)
            {
                find+=(char)((int)target_sentence[k][l]+32);
            }
            else
            {
                find+=target_sentence[k][l];
            }
            //cout<<find<<endl;
           // system("pause");
           if(find.compare(",")==0||find.compare(".")==0||find.compare(";")==0||
           find.compare("'")==0||find.compare("?")==0||find.compare("!")==0||find.compare("\"")==0)
           {
               cut.push_back(find);
               find="";
               big="";
           }
           else
           {
            if(trie.Search(find)==false)
            {
                find.pop_back();
                big.pop_back();
                //cout<<"putin:"<<endl<<find<<endl;
                //system("pause");
                cut.push_back(big);
                find = "";
                big="";
                l--;
                error++;
                if (error == 10)
                {
                    cout << "无法找到" << endl
                         << find << endl;
                    cout << "退出..." << endl
                         << endl;
                    return;
                }
            }
            else
            {
                cut.push_back(big);//最小匹配原则
                error=0;
            }
           }
        }
    }
    /*
    for(int k=0;k<cut.size();k++)
    {
        cout<<cut[k]<<endl;
        system("pause");
    }
    */
    return;
}


void elementaryhandle::answer()
{
    fstream writer;
    writer.open("answer.txt",ios::trunc|ios::out);
    for(int k=0;k<cut.size();k++)
    {
        writer<<cut[k];
        if(cut[k].compare(",")!=0&&cut[k].compare(";")!=0&&cut[k].compare(".")!=0&&cut[k].compare("'")!=0&&cut[k].compare("?")!=0)
        {
            if(k!=cut.size()-1)
            {
                cout<<cut[k]<<endl;
                if(cut[k+1].compare(",")!=0&&cut[k+1].compare(";")!=0&&cut[k+1].compare(".")!=0&&cut[k].compare("'")!=0&&cut[k].compare("?")!=0)
                {
                    writer<<" ";
                }
            }
        }
    }
    writer<<endl;
    cut.clear();
    writer.close();
    return;
}

void elementaryhandle::read()
{
    fstream read_file;
    string context,A_sentence;
    read_file.open("test.txt",ios::in);
    if(read_file.fail())
    {
        read_file.open("test.docx",ios::in);
    }
    while(read_file.peek()!=EOF)
    {
        getline(read_file,context);
        sentences+=context;
        context.clear();
    }
    read_file.close();
    int len=0;
    for(int k=0;k<sentences.size();k++)
    {
        if(sentences[k]=='.'||sentences[k]==';')//如果字符为分号或者句号,切割
        {
            for(;len<=k;len++)
            {
                A_sentence+=sentences[len];
            }
            target_sentence.push_back(A_sentence);
            A_sentence.clear();
        }
    }
    return;
}
