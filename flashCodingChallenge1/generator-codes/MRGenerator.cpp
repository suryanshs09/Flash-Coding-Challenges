#include <bits/stdc++.h>
using namespace std;

const int minT=1, maxT=100;
const int minN=2, maxN=20;
const int minA=0, maxA=1000;

const int TestCases = 50;

void testCaseGenerator() {
    bool flag = true;
    int TestCount = TestCases;
    while(TestCount--){
        int t = rand()%maxT;
        if(t < minT){
            t += (minT-t);
        }
        string str;
        if(TestCount < 10){
            str = "../testcases/matrix-reloaded-testcases/input/input0" + to_string(TestCount) + ".txt";
        }
        else{
            str = "../testcases/matrix-reloaded-testcases/input/input" + to_string(TestCount) + ".txt";
        }
        ofstream fout;
        fout.open(str);
        if(!fout){
            flag = false;
            break;
        }
        fout << t << endl;
        while(t--){    
            int N = rand()%maxN;
            if(N < minN){
                N += (minN-N);
            }
            fout << N << endl;
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    int a = rand()%maxA;
                    if(a < minA){
                        a += (minA-a);
                    }
                    if((rand()%10) % 2 == 0){
                        a = -a;
                    }
                     fout << a << " ";
                }
                fout << endl;
            }
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

void outputGenerator() {
    bool flag = true;
    int TestCount = TestCases;
    while(TestCount--){
        ifstream fin;
        ofstream fout;
		string str1, str2;
		if(TestCount < 10){
            str1 = "../testcases/matrix-reloaded-testcases/input/input0" + to_string(TestCount) + ".txt";
			str2 = "../testcases/matrix-reloaded-testcases/output/output0" + to_string(TestCount) + ".txt";
        }
        else{
            str1 = "../testcases/matrix-reloaded-testcases/input/input" + to_string(TestCount) + ".txt";
			str2 = "../testcases/matrix-reloaded-testcases/output/output" + to_string(TestCount) + ".txt";
        }
        fin.open(str1);
        fout.open(str2);
        if(!fout || !fin){
            flag = false;
            break;
        }
	    int t;
	    fin >> t;
    	while(t--){
		    int n;
		    fin >> n;
		    int digSum = 0;
		    int oDigSum = 0;
		    for(int i=0; i<n; i++){
			    for(int j=0; j<n; j++){
				    int temp;
				    fin >> temp;
				    if(i==j){
					    digSum += abs(temp);
				    }
				    if(i+j == n-1){
					    oDigSum += abs(temp);
				    }
			    }
		    }
		    fout << digSum * oDigSum << endl;
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

    return 0;
}