#include <cstdio>
#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef map<pair<int, int>, int> dataMapType;
typedef map<pair<int, int>, int>::iterator mapIter;

typedef set<int>::iterator setIter;

void printMap(dataMapType mdataMap) {
	cout << "---------" << endl;
	for(mapIter iter=mdataMap.begin();iter!=mdataMap.end();iter++) {
		cout << (iter->first).first << " " << (iter->first).second << " "
				<< iter->second << endl;
	}
}

void printSet(set<int> mset) {
	cout << "elements" << endl;
	for(setIter iter=mset.begin();iter!=mset.end();iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

void fillWeightMap(dataMapType &mWeightMap, int N) {
//	cout << "fillWeightMap, N=" << N << endl;
	for(int i=1;i<=N;i++) {
		for(int j=i+1;j<=N;j++) {
			pair<int, int> dataPair(i, j);
			mWeightMap[dataPair]= -1;
		}
	}
}

void fill(dataMapType &mWeightMap, set<int> mset) {
	cout << "fill: ";
	printSet(mset);
	if (mset.size()<=2) return;
	else {
	for(setIter iter=mset.begin();iter!=mset.end();iter++) {
		cout << *iter << " ";
		mset.erase(iter);
		fill(mWeightMap, mset);
	}
	cout << endl;
	}
}

/*
void fill(dataMapType &mWeightMap, set<int> mset) {
	for(setIter iter=mset.begin();iter!=mset.end();iter++) {
		for(setIter iter2=iter;iter2!=mset.end();iter2++) {
			if(*iter != *iter2) {
				pair<int, int> dataPair(*iter, *iter2);
	//			if(mWeightMap[dataPair]!= -1) {}
				cout << "fill " << *iter << " " << *iter2 << " " << mWeightMap[dataPair] << endl;
			}
		}
	}
}
*/

void algorithm(dataMapType &mWeightMap, dataMapType mdataMap) {
	set<int> mset;
	for(mapIter iter=mdataMap.begin();iter!=mdataMap.end();iter++) {
		mWeightMap[iter->first]=iter->second;

		mset.insert(iter->first.first);
		mset.insert(iter->first.second);
		printSet(mset);

		if (mset.size()>2) fill(mWeightMap, mset);
	}
}

int main(int argc, char** argv)
{
	dataMapType dataMap;
	dataMapType weightMap;
    int tc, T, N, A, B, D, help;

    freopen("sample_input.txt", "r", stdin);

    cin >> T;
    for(tc = 0; tc < 1; tc++)
    {
        cin >> N;
        for(int i=0;i<N-1;i++) {
            cin >> A;
            cin >> B;
            if(B<A) {
            	help=A;
            	A=B;
            	B=help;
            }
            pair<int, int> dataPair(A, B);
            cin >> D;
            dataMap[dataPair]=D;
        }
        printMap(dataMap);
        fillWeightMap(weightMap, N);
        printMap(weightMap);
        algorithm(weightMap, dataMap);
        printMap(weightMap);
    }

    return 0;
}
