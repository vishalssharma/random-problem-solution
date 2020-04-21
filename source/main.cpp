#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
int lb = 0;
int ub = 4998;
struct dictionary{
    string word;
    int freq;
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


    // for(int j=0;j<=i;j++){
    //     cout<<dict[j].word<<" "<<dict[j].freq;
    //     cout<<endl;
    // }

}
void printTopWords(){
    int left = lb;
    int right = ub;
    // int maximum = INT_MIN;
    // string str;
    // for(int i=lb;i<ub;i++){
    //     if(dict[i].freq > maximum){
    //         maximum = max(maximum,dict[i].freq);
    //         str = dict[i].word;
    //     }
    // }
    // cout<<str<<'\t';
    map<int,string> m;
    for(int i=lb;i<ub;i++)
    m[dict[i].freq] = dict[i].word;

    map<int,string>::iterator itr;
    itr = m.end();
    itr--;
    int i =0;
    while(itr !=m.end() && i<5){
        cout<<itr->second<<'\t';
        i++;
        itr--;
    }
}
// int findFirstOccurance(int left,int right,int lastIndex,char c){
//     while(right >= left){
//         int mid = left + (right-left)/2;

//         if(mid == 0 || tolower(dict[mid].word[lastIndex]) == c && dict[mid-1].word[lastIndex] > c)
//             return mid;
//         else if( c > tolower(dict[mid].word[lastIndex])){

//         }
//     }
// }
bool findTopWords(string str){
    int lastIndex = str.size() -1;
    char c = str[lastIndex];
    int left = lb;
    int right = ub-1;
    int posMiddle = -1;
    // new binary search
    // int firstOccurance = findFirstOccurance(left,right,lastIndex,c);
    // binary search to find all matching words 
    while(left<=right){
        int mid = left + (right-left)/2;
        if(dict[mid].word[lastIndex] == c){
            posMiddle = mid;
            break; 
        }
        else if(dict[mid].word[lastIndex] > c){
            right = mid - 1;

        }
        else{
            left = mid + 1;
        }
        
    }
    if( posMiddle == -1)
        return false;
    int firstOccurance = posMiddle;
    while(firstOccurance >= 0 && (toupper(dict[firstOccurance].word[lastIndex]) == c || tolower(dict[firstOccurance].word[lastIndex]) == c)){
        firstOccurance--;
    }
    lb = firstOccurance+1;
    
    int lastOccurance = posMiddle;
    while(lastOccurance != 4998 && (toupper(dict[lastOccurance].word[lastIndex]) == c || tolower(dict[lastOccurance].word[lastIndex]) == c)){
        lastOccurance++;
    }
    ub = lastOccurance + 1;

    cout<<lb<<"  "<<ub<<endl;
    if((ub - lb) == 1){
        cout<<dict[lb].word<<'\t';
    }
    else if((ub - lb) == 2){
        if(dict[lb].freq >= dict[lb+1].freq){
            cout<<dict[lb].word<<'\t';
            cout<<dict[lb+1].word<<'\t';
            
        }
        else{
            cout<<dict[lb+1].word<<'\t';
            cout<<dict[lb].word<<'\t';
        }
    }
    else
        printTopWords();
    

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
        bool flag = findTopWords(s);
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


