#include <bits/stdc++.h>
using namespace std;

const int minN=0, maxN=26;
const vector<string> fillCharList = {
    "-", "--", "---", "-+-", "++", "*", "***", "-*-", "!", "@", "#", "$", "%", "^", "&", "-!-", "-@-", "-#-", "-$-", "-%-", "-^-", "-&-", "=", "==", "===", "-=-", "=-=", "=!=", "=@=", "=#=", "=$=", "=%=", "=^=", "=&=", "=*=", "+!+", "+@+", "+#+", "+$+", "+%+", "+^+", "+&+", "+-+", "+*+", "+=+" "++!++", "++@++", "++#++", "++$++", "++%++", "++^++", "++&++", "_", "__", "___", "==!==", "==@==", "==#==", "==$==", "==%==", "==^==", "==&==", "_!_", "_@_", "_#_", "_$_", "_%_", "_^_", "_&_", "<->", ">-<", "-?-", "-{}-", "}-{", "-:-", "-.-", "-[]-", "]-[", "-()-", ")-(", "<=>", ">=<", "=?=", "={}=", "}={", "=:=", "=.=", "=[]=", "]=[", "=()=", ")=(", "<+>", ">+<", "+?+", "+{}-+", "}+{", "+:+", "+.+", "+[]+", "]+[", "+()+", ")+(", " ! ", " @ ", " # ", " $ ", " % ", " ^ ", " & ", "< >", "> <", " ? ", " {} ", "} {", " : ", " . ", " [] ", "] [", " () ", ") (", " - ", " + ", " * " , " = ", " ~ ", "~!~", "~@~", "~#~", "~$~", "~%~", "~^~", "~&~", "<~>", ">~<", "~?~", "~{}~", "}~{", "~:~", "~.~", "~[]~", "]~[", "~()~", ")~(", "~-~", "~+~", "~*~" , "~=~", "~~~", "~", "~~", "-~-" , "+~+", "=~="
};
const int TestCases = 150;

void testCaseGenerator(){
    bool flag = true;
    int TestCount = TestCases;
    while(TestCount--){
        string str;
        if(TestCount < 10){
            str = "../testcases/p-a-t-t-e-r-n-testcases/input/input00" + to_string(TestCount) + ".txt";
        }
        else if(TestCount < 100){
            str = "../testcases/p-a-t-t-e-r-n-testcases/input/input0" + to_string(TestCount) + ".txt";
        }
        else{
            str = "../testcases/p-a-t-t-e-r-n-testcases/input/input" + to_string(TestCount) + ".txt";
        }
        ofstream fout;
        fout.open(str);
        if(!fout){
            flag = false;
            break;
        }
        
        int n = rand()%maxN+1;
        if(n < minN){
            n += (minN-n);
        }
        int i = rand()%fillCharList.size();
        fout << n << endl << fillCharList[i];

        std::cout << str  << " created successfully..." << endl;
        fout.close();
    }
    if(!flag){
        std::cout << "some error in creating input files" << endl;
    }
    else{
        std::cout << "All input files created!" << endl;
    }
}

void outputGenerator(){
    bool flag = true;
    int TestCount = TestCases;
    while(TestCount--){
        ifstream fin;
        ofstream fout;
		string str1, str2;
		if(TestCount < 10){
            str1 = "../testcases/p-a-t-t-e-r-n-testcases/input/input00" + to_string(TestCount) + ".txt";
			str2 = "../testcases/p-a-t-t-e-r-n-testcases/output/output00" + to_string(TestCount) + ".txt";
        }
        else if(TestCount < 100){
            str1 = "../testcases/p-a-t-t-e-r-n-testcases/input/input0" + to_string(TestCount) + ".txt";
			str2 = "../testcases/p-a-t-t-e-r-n-testcases/output/output0" + to_string(TestCount) + ".txt";
        }
        else{
            str1 = "../testcases/p-a-t-t-e-r-n-testcases/input/input" + to_string(TestCount) + ".txt";
			str2 = "../testcases/p-a-t-t-e-r-n-testcases/output/output" + to_string(TestCount) + ".txt";
        }
        fin.open(str1);
        fout.open(str2);
        if(!fout || !fin){
            flag = false;
            break;
        }
	    string alphabets = "abcdefghijklmnopqrstuvwxyz";
        string tempString = "ABA";
        int count;
        fin >> count;
        string fillChar, temp;
        getline(fin, temp);
        getline(fin, fillChar);
        int rowLen = (count * (fillChar.size() + 1)) + ((count-1)*(fillChar.size() + 1) - fillChar.size());
        vector<vector<string>>pattern((count*2 - 1), vector<string>(rowLen, fillChar));
        vector<string> list;
    
        for(int i=0; i<count; i++){
            string temp = "";
            for(int j=0; j<i+1; j++){
                if(i == j){
                    temp = temp + alphabets[j];
                }
                else{
                    temp = temp + alphabets[j] + tempString;
                }
            }
            list.push_back(temp);
        }

        for(int i=list.size()-1; i>=0; i--){
            if(i != 0){
                string temp = list[i];
                temp.pop_back();
                reverse(temp.begin(), temp.end());
                list[i] = list[i] + temp;
                int loc = list[i].find(tempString);
                while(loc < list[i].size()){
                    list[i].replace(loc, tempString.size(), fillChar);
                    loc = list[i].find(tempString, loc+fillChar.size());
                }
            }
            if(i != list.size()-1){
                list.push_back(list[i]);
            }
        }

        for(int i=0; i<pattern.size(); i++){
            int start = (rowLen/2) - (list[i].size()/2);
            pattern[i][start] = list[i];
            for(int j=0; j<start; j++){
                pattern[i][j] = " ";
            }
            pattern[i].erase(pattern[i].begin()+start+1, pattern[i].end());
        }

        for(int i=0; i<pattern.size(); i++){
            for(int j=0; j<pattern[i].size(); j++){
                fout << pattern[i][j];
            }
            fout << endl;
        }
        std::cout << str2  << " created successfully..." << endl;
        fin.close();
        fout.close();
    }
    if(!flag){
        std::cout << "some error in creating output files" << endl;
    }
    else{
        std::cout << "All output files created!" << endl;
    }
}

int main(){
    srand(time(NULL));

    testCaseGenerator();
    outputGenerator();

    cout << "fillChar list size: " << fillCharList.size() << endl;

    return 0;
}