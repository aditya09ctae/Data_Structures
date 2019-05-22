#include <bits/stdc++.h>
using namespace std;

struct trieNode
{
    unordered_map<char,trieNode*> um;
    bool isLeaf;
    trieNode()
    {
        unordered_map<char,trieNode*> temp;
        um = temp;
        isLeaf = false;
    }
};

void insert(trieNode* &head,string s)
{

    if(head == NULL)
    {
        head = new trieNode();
    }

    trieNode* tn = head;

    for(int i =0; i< s.length(); i++)
    {
        char c = s[i];

        if(tn->um.find(c) == tn->um.end())
        {
            trieNode* temp_node = new trieNode();
            tn->um[c] = temp_node;
        }

        tn = tn->um[c];
    }

    tn -> isLeaf = true;
}

int search(trieNode* head,string s)
{
    if(head == NULL)
    {
       // cout << "head is null\n";
        return 0;
    }

    trieNode* tn = head;
    for(int i = 0; i< s.length(); i++)
    {
        char c = s[i];

        if(tn->um.find(c) == tn->um.end())
        {
        //cout << "inside um if\n";
           return 0;
        }

        tn = tn->um[c];
    }

    if(tn->isLeaf == false)
    {
        //cout << "isleaf is false\n";
    return 0;
    }

    return 1;
}

bool deleteNodeHelper(trieNode* &head,string s, int curr_pos)
{
    if(curr_pos == s.length())
    {
        if(head->isLeaf == false)
        return false;

        head->isLeaf = false;

        return head->um.size() == 0;
    }

    char c = s[curr_pos];

    if(head->um.find(c) == head->um.end())
    return false;

    bool shouldDelete = deleteNodeHelper(head->um[c],s,curr_pos+1);

    if(shouldDelete == true)
    {
        head->um.erase(c);
        return head->um.size() == 0;
    }

    return false;
}

void deleteNode(trieNode* &head, string s)
{
    /*if(head == NULL)
    return;

    if(s.length() == 0)
    return;*/

    deleteNodeHelper(head,s,0);
}
int main()
{
    trieNode* head = NULL;

    insert(head,"hello");

    insert(head,"hell");

    insert(head,"ball");

    insert(head,"cat");

    insert(head,"rat");

    cout << "cat is :" << search(head,"cat") << "\n";
    cout << "hello is : " << search(head,"hello") << "\n";
    cout << "hellow is : " << search(head,"hellow") << "\n";
    cout << "enpty string is : " << search(head , "") << "\n";

    cout << "hell is : " << search(head , "hell") << "\n";
    deleteNode(head,"hell");
    cout << "hell is :" << search(head , "hell") << "\n";
    deleteNode(head,"hellow");
    cout << "cat is :" << search(head , "cat") << "\n";
    return 0;
}
