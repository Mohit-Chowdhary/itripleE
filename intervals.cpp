#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class intervalManager{
    private:
    vector<vector<int>> intervals;

    public:
    void addInterval(int start,int end){
        intervals.push_back({start,end});
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> merged;
        for(const auto& i: intervals){
            if(!merged.empty() && merged.back()[1]>=i[0]){      // if merged array is not empty and the end index of last element(of merged) is greater than the satrt index of next element, meaning an overlap
                merged.back()[1]=max(merged.back()[1],i[1]);
            }
            else{
                merged.push_back(i);
            }
        }
        intervals=merged;
    }


    void printIntervals() {
        for (const auto& i : intervals) {
            cout << "[" << i[0] << ", " << i[1] << "] ";
        }
        cout << endl;
    }
};

int main() {
    intervalManager im;
    int finish=0;
    do{
        cout<<"Enter interval"<<endl;
        int a,b;
        cin>>a>>b;
        im.addInterval(a,b);
        im.printIntervals();
        cout<<"End? 0/1";
        cin>>finish;

    }while(finish!=1);
    return 0;
}