#include <bits/stdc++.h>
using namespace std;

const int minLB=50, maxLB=150;
const int minWB=50, maxWB=150;
const int minH=1, maxH=100;
const int TestCases = 100;
const double floorHeight = 15;

void testCaseGenerator(){
    bool flag = true;
    int TestCount = TestCases;
    while(TestCount--){
        string str;
        if(TestCount < 10){
            str = "../testcases/ted-the-builder-testcases/input/input0" + to_string(TestCount) + ".txt";
        }
        else{
            str = "../testcases/ted-the-builder-testcases/input/input" + to_string(TestCount) + ".txt";
        }
        ofstream fout;
        fout.open(str);
        if(!fout){
            flag = false;
            break;
        }
        int temp1 = rand()%10 + 2;
        int temp2 = rand()%10 + 2;
        int LB = rand()%maxLB;
        if(LB < minLB){
            LB += (minLB-LB);
        }
        int WB = rand()%maxWB;
        if(WB < minWB){
            WB += (minWB-WB);
        }
        int L = LB * temp1;
        int W = WB * temp2;
        fout << L << " " << W << " " << LB << " " << WB << endl;
        for(int i=0; i<temp1; i++){
            for(int j=0; j<temp2; j++){
                int h = rand()%maxH;
                if(h < minH){
                    h += (minH-h);
                }
                fout << h << " ";
            }
            fout << endl;
        }
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
            str1 = "../testcases/ted-the-builder-testcases/input/input0" + to_string(TestCount) + ".txt";
			str2 = "../testcases/ted-the-builder-testcases/output/output0" + to_string(TestCount) + ".txt";
        }
        else{
            str1 = "../testcases/ted-the-builder-testcases/input/input" + to_string(TestCount) + ".txt";
			str2 = "../testcases/ted-the-builder-testcases/output/output" + to_string(TestCount) + ".txt";
        }
        fin.open(str1);
        fout.open(str2);
        if(!fout || !fin){
            flag = false;
            break;
        }
	    int L, LB, W, WB;
        fin >> L >> W >> LB >> WB;
	    int n = L/LB;
        int m = W/WB;
        int Sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int temp;
                fin >> temp;
                Sum += temp;
            }
        }
    	double h = (floorHeight / 3.280839895) * (double)Sum;
        fout << (long long)ceil(LB * WB * h);
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

    return 0;
}