#include<bits/stdc++.h>
using namespace std;
struct dict{
    string str;
    unsigned int freq;
};
dict d[5000];
void insertWords(){
    ifstream fin;
    fin.open("../source/EnglishDictionary.csv",ios::in);
    if(!fin)
        cout<<"read error";

    string line, word, temp;
    vector<string> row;
    char c;
    unsigned int f;
    int i = 0;
    while(fin){
        row.clear();
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,',')){
            row.push_back(word);
        }
        d[i].str = row[0];
        d[i].freq = stoi(row[1]);
        i++;


    }


    for(int j=0;j<=i;j++){
        cout<<d[j].str<<" "<<d[j].freq;
        cout<<endl;
    }

}
bool printTopWords(string s){
    

}
int main(){
    insertWords();
    char c;
    cin>>c;
    string s;
    while(c != '#'){
        s += c;
        bool flag = printTopWords(s);
        if(flag == false){
            cout<<"No match Found !!"<<endl;
            cout<<"Exiting"<<endl;
            return 0;
        }
        cin>>c;
    }
    cout<<"Exiting";
    return 0;
}


