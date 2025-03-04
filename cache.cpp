//same code, but w minheap (priority queue)
//no its not mb

#include <iostream>
#include <map>
#include <queue>
//#include <intervals2.cpp>

using namespace std;

class cache{

    protected:
    priority_queue <tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    public:
    void addInterval(int start, int value, int expiryTime){

        pq.push({expiryTime,start,value});

    }

    void getInterval(int start){

        bool found = false;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> temp;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            if(get<1>(top) != start){
                temp.push(top);
            }
            else{
                found = true;
                cout << "Start: " << get<1>(top) <<", Value: " << get<2>(top) << endl;
            }
        }

        if(!found){
            cout << "Key " << start << " was not found." << endl;
        }

        pq = move(temp);
    }
};

int main() {
    cache c;
    int choice;

    do {
        cout << "\n1. Add Interval\n2. Get Interval\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int start, value, expiryTime;
            cout << "Enter start, value, expiryTime: ";
            cin >> start >> value >> expiryTime;
            c.addInterval(start, value, expiryTime);
        } 
        else if (choice == 2) {
            int start;
            cout << "Enter start value to retrieve: ";
            cin >> start;
            c.getInterval(start);
        } 
        else if (choice == 3) {
            cout << "Exiting...\n";
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
