#include <iostream>
#include <map>

using namespace std;

class intervalManager{

    protected:
    map<int,int> intervals;

    public:
    void addInterval(int start, int end){
        auto i = intervals.lower_bound(start);              // gives lowest index after start

        if(i != intervals.begin()){
            auto prv = prev(i);                             // goes to prev index
            if(start <= prv->second){                       // overlap
                start = prv->first;
                end = max(prv->second,end);
                intervals.erase(prv);
            }
        }

        while(i != intervals.end() && end >= i->first){
            end = max(end,i->second);
            i = intervals.erase(i);                     
        }

        intervals[start] = end;

    }

    void getIntervals(){
        for (const auto& i : intervals) {
            cout << "[" << i.first << ", " << i.second << "] ";
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
        if(a>b){
            printf("Invalid interval!");
        }
        im.addInterval(a,b);
        im.getIntervals();
        cout<<"End? 0/1";
        cin>>finish;

    }while(finish!=1);
    return 0;
}