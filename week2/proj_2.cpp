#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


struct file_cell {
    file_cell *m_father;
    file_cell *m_children[100];
    const string m_filename;
    file_cell(string &str, file_cell *father):m_filename(str){
        m_father = father;
        memset(m_children, 0, sizeof(m_children));
    };
};


struct filename_comp {
    bool operator()(file_cell *left, file_cell *right){
        if (left->m_filename[0] == right->m_filename[0]){
            if (left->m_filename[0] == 'f')
                return left->m_filename < right->m_filename;
            else {
                return left->m_filename[0] < right->m_filename[0];
            }
        }
        return left->m_filename < right->m_filename;
    }
} myobject;



file_cell *parse_input(file_cell *father, string &filename)
{
    file_cell *ret = new file_cell(filename, father);
    if (filename[0] != 'f') {
        int i = 0;
        while (true) {
            string child;
            cin >> child;
            if (child[0] == '#'){
                delete ret;
                return NULL;
            }
            if (child[0] == ']' || child[0] == '*')
                break;
            ret->m_children[i++] = parse_input(ret, child);
        }
        
    }
    return ret;
};

void pretty_sort(file_cell *root)
{
    int i = 0;
    for (; i < 100; ++i) {
        if (!root->m_children[i])
            break;
    }
    sort(root->m_children, root->m_children+i, myobject);
    for (int j = 0; j < i; ++j) {
        if (root->m_children[j]->m_filename[0] == 'd') {
            pretty_sort(root->m_children[j]);
        }
    }
}

void pretty_print(file_cell *root, string prefix)
{
    int i = 0;
    for (; i < 100; ++i) {
        if (!root->m_children[i])
            break;
        else if (root->m_children[i]->m_filename[0] == 'd'){
            cout << "|     " << prefix << root->m_children[i]->m_filename << endl;
            string next_prefix = "|     " + prefix;
            pretty_print(root->m_children[i], next_prefix);
        } else {
            cout << prefix << root->m_children[i]->m_filename << endl;
        }
    }
    
}

void free_fileroot(file_cell *root)
{
    for (int i = 0; i < 100; ++i)
        if (root->m_children[i])
            if (root->m_children[i]->m_filename[0] == 'd')
                free_fileroot(root->m_children[i]);
    
    for (int i = 0; i < 100; ++i)
        delete root->m_children[i];
}



int main(int argc, char *argv[])
{
    int i = 0;
    while (true) {
        string root("ROOT");
        file_cell *file_root = parse_input(NULL, root);
        if (!file_root)
            break;
        ++i;
        pretty_sort(file_root);
        string prefix = "";
        cout << "DATA SET " << i << ":" << endl;
        cout << "ROOT" << endl;
        pretty_print(file_root, prefix);
        cout << endl;
        free_fileroot(file_root);
    }
    return 0;
}

