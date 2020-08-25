
#include<iostream>
using namespace std;
#include<vector>
class PriorityQueue {
    // Complete this class
    vector<int> pq;
    public:

    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.size()==0;
    }

    int getSize(){
        return pq.size();
    }

    int getMax(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);
        int childIndex = pq.size()-1;
        while(childIndex>0){
            int parentIndex = (childIndex-1)/2;

            if(pq[childIndex]>pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMax(){
        if(isEmpty()){
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        int parentIndex = 0;
        int LCI = 2*parentIndex+1;
        int RCI = 2*parentIndex+2;
        while(LCI<pq.size()){
            int maxIndex = parentIndex;
            if(pq[LCI]>pq[maxIndex]){
                maxIndex = LCI;
            }
            if(pq[RCI]>pq[maxIndex] && RCI<pq.size()){
                maxIndex = RCI;
            }
            if(maxIndex == parentIndex){
                break;
            }
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
            LCI = 2*parentIndex+1;
        	RCI = 2*parentIndex+2;
        }
        return ans;
    }

};



int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMax
                cout << pq.getMax() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMax() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}
