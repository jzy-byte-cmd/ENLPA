#include "standard.h"
#include "trie.h"

class elementaryhandle
{
public:

void read();
//读取文本


void MMP(DicTree &trie);
//MM 算法 mm  改 0825

void answer();

private:

vector<string> target_sentence;

vector<string> cut;

string sentences;
};