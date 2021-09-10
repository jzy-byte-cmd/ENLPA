#include "ElementaryHandle.h"


void elementaryhandle::MMP(DicTree &trie)
{
    string big,find_copy,big_copy;
    bool OK=false;
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
           find.compare("'")==0||find.compare("?")==0||find.compare("!")==0||find.compare("\"")==0||
           find.compare("(")==0||find.compare(")")==0||find.compare("[")==0||find.compare("]")==0||
           find.compare(":")==0||find.compare("-")==0||find.compare("0")==0||find.compare("1")==0||
           find.compare("2")==0||find.compare("3")==0||find.compare("4")==0||find.compare("5")==0||
           find.compare("6")==0||find.compare("7")==0||find.compare("8")==0||find.compare("9")==0)
           {
               cut.push_back(find);
               find="";
               big="";
           }
           else
           {
            if(trie.Search(find)==false)
            {
                for(int g=1;g<find.size();g++)
                {
                    for(int n=g;n<find.size();n++)
                    {
                        find_copy+=find[n];
                        big_copy+=big[n];
                    }
                    if(trie.Search(find_copy)==true)
                    {
                        string find_another;
                        for(int o=0;o<g;o++)
                        {
                            find_another+=big[o];
                        }
                        cut.push_back(find_another);
                        //cout<<"find_another:"<<endl;
                        //cout<<find_another<<endl;
                        //system("pause");
                        find=find_copy;
                        big=big_copy;
                        OK=true;
                        break;
                    }
                }
                if(OK==false)
                {
                find.pop_back();
                big.pop_back();
                //cout<<"putin:"<<endl<<find<<endl;
                //system("pause");
                cut.push_back(big);
                find = "";
                big="";
                l--;
                //cout << "无法找到" << endl
                  //   << find << endl;
                //system("pause");
                }
                OK=false;
                find_copy.clear();
                big_copy.clear();
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

void elementaryhandle::MM(DicTree &trie)
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
           find.compare("'")==0||find.compare("?")==0||find.compare("!")==0||find.compare("\"")==0||
           find.compare("(")==0||find.compare(")")==0||find.compare("[")==0||find.compare("]")==0||
           find.compare(":")==0||find.compare("-")==0||find.compare("0")==0||find.compare("1")==0||
           find.compare("2")==0||find.compare("3")==0||find.compare("4")==0||find.compare("5")==0||
           find.compare("6")==0||find.compare("7")==0||find.compare("8")==0||find.compare("9")==0)
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
                    //cout << "无法找到" << endl
                      //   << find << endl;
                    //cout << "退出..." << endl
                        // << endl;
                    return;
                }
            }
            else
            {
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
        writer << cut[k];
        if (cut[k].compare(",") != 0 && cut[k].compare(";") != 0 && cut[k].compare(".") != 0 &&
            cut[k].compare("'") != 0 && cut[k].compare("?") != 0 && cut[k].compare("!") != 0 &&
            cut[k].compare("\"") != 0 && cut[k].compare("(") != 0 && cut[k].compare(")") != 0 &&
            cut[k].compare("[") != 0 && cut[k].compare("]") != 0&&cut[k].compare(":")!=0&&
            cut[k].compare("-")!=0&&cut[k].compare("0")!=0&&cut[k].compare("1")!=0&&
            cut[k].compare("2")!=0&&cut[k].compare("3")!=0&&cut[k].compare("4")!=0&&
            cut[k].compare("5")!=0&&cut[k].compare("6")!=0&&cut[k].compare("7")!=0&&
            cut[k].compare("8")!=0&&cut[k].compare("9")!=0)
        {
            if (k != cut.size() - 1)
            {
                // cout<<cut[k]<<endl;
                if (cut[k + 1].compare(",") != 0 && cut[k + 1].compare(";") != 0 && cut[k + 1].compare(".") != 0 &&
                    cut[k + 1].compare("'") != 0 && cut[k + 1].compare("?") != 0 && cut[k + 1].compare("!") != 0 &&
                    cut[k + 1].compare("\"") != 0 && cut[k + 1].compare("(") != 0 && cut[k + 1].compare(")") != 0 &&
                    cut[k + 1].compare("[") != 0 && cut[k + 1].compare("]") != 0 && cut[k + 1].compare(":") != 0 &&
                    cut[k + 1].compare("-") != 0 && cut[k + 1].compare("0") != 0 && cut[k + 1].compare("1") != 0 &&
                    cut[k + 1].compare("2") != 0 && cut[k + 1].compare("3") != 0 && cut[k + 1].compare("4") != 0 &&
                    cut[k + 1].compare("5") != 0 && cut[k + 1].compare("6") != 0 && cut[k + 1].compare("7") != 0 &&
                    cut[k + 1].compare("8") != 0 && cut[k + 1].compare("9") != 0)
                {
                    writer << " ";
                }
            }
        }
    }
    writer<<endl; 
    cut.clear();
    writer.close();
    target_sentence.clear();
    return;
}

void elementaryhandle::read()
{
    fstream read_file;
    string context,A_sentence;
    read_file.open("test.txt",ios::in);
    while(read_file.peek()!=EOF)
    {
        getline(read_file,context);
        sentences+=context;
        context.clear();
    }
    read_file.close();
    int len=0;
    long long k=0;
    //cout<<sentences<<endl;
    for(;k<sentences.size();k++)
    {
        if(sentences[k]=='.'||sentences[k]==';'||sentences[k]=='?'||sentences[k]=='!'||sentences[k]==':')//如果字符为;或.或?或!,切割
        {
            for(;len<=k;len++)
            {
                A_sentence+=sentences[len];
            }
            target_sentence.push_back(A_sentence);
            A_sentence.clear();
        }
    }
    for(;len<k;len++)
    {
        A_sentence+=sentences[len];
        target_sentence.push_back(A_sentence);
            A_sentence.clear();
    }
    
    return;
}
