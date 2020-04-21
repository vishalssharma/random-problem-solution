#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
struct dictionary{
    string word;
    unsigned int freq;
};
dictionary dict[5000];
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
        dict[i].word = row[0];
        dict[i].freq = stoi(row[1]);
        i++;


    }


    for(int j=0;j<=i;j++){
        cout<<dict[j].word<<" "<<dict[j].freq;
        cout<<endl;
    }

}
bool printTopWords(string s){
    return true;

}
int main(){
    insertWords();
    char c;
    cin>>c;
    string s;
    while(c != '#'){
        s += c;
        auto start = high_resolution_clock::now();
        bool flag = printTopWords(s);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop-start);
        if(flag == false){
            cout<<"No match Found !!        "<<duration.count()<<" μs"<<endl;
            cout<<"Exiting"<<endl;

            return 0;
        }
        cout<<"        "<<duration.count()<<" μs"<<endl;
        cin>>c;
    }
    cout<<"Exiting";
    return 0;
}


