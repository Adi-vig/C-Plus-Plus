#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

#define MAX 10
using namespace std;

class process{
    public:
    int pid;
    int at;
    int bt;
    int wt;
    int tat;
    int ct;
};



vector<process> calcWT(int n, vector<process>&P  ){
    vector<process>res(n);
    vector<bool>executed(n,0);
    priority_queue< pair <int , int> >pq;  //at , process
    //push
    //pop
    //top
    // for(auto i : P){

    //     pair <int, int>temp;
    //     temp.first = -i.at;
    //     temp.second = -i.pid;
    //     pq.push(temp);
    // }

    int curtime=0;

    process current;

    int noofexecuted=0;

    while(noofexecuted<n){

        for(auto i : P){
            if(i.at <= curtime && executed[i.pid]==0){
                pair<int, int>temp;
                temp.first = -i.bt;
                temp.second = -i.pid;
                pq.push(temp);
                executed[i.pid]=1;
            }
        }   
        cout<<"Current time : "<<curtime<<endl;
        if(pq.empty()){
            curtime++;
            continue;
        }



        current = P[-pq.top().second];
        
        cout<<"P"<<current.pid+1<<" AT="<<current.at<<" \n\n"<<endl;

        pq.pop();

        current.wt = curtime- current.at;

        curtime += current.bt;

        executed[current.pid]=1;

        noofexecuted++;


        current.ct  = curtime;
        current.tat = curtime-current.at;
        res[current.pid]=current;
    }

    return res;

}







int main(){


    // priority_queue<pair<int, process>>pq;
    // at and process


    // for(int i=0; i<MAX; i++)p[i].pid=i+1;

    // for(int i=0; i<MAX; i++){
    //     cin>>p[i].pid;
    //     cin>>p[i].at;
    //     cin>>p[i].bt;
    // }

    int n;
    

    // cout<<"Enter number of processes: ";
    // cin>>n;

    // vector<process> p(n);

    // for(int i=0; i<n; i++){
    //     p[i].pid=i;
    //     cout<<"Enter AT and BT for P"<<i+1<<endl;
    //     cin>>p[i].at>>p[i].bt;
    // }
    
    
    
    
    n=5;
    vector<process> p(5);

    p[0].pid=0;
    p[1].pid=1;
    p[2].pid=2;
    p[3].pid=3;
    p[4].pid=4;

    p[0].at =1;
    p[1].at =3;
    p[2].at =6;
    p[3].at =7;
    p[4].at =9;


    p[0].bt =7;
    p[1].bt =3;
    p[2].bt =2;
    p[3].bt =10;
    p[4].bt =8;

    







    
    printf("Pid     AT      BT      WT      TAT       CT\n");
    for(auto i : p){
        printf(" %d ",      i.pid+1 );
		printf("	 %d ",  i.at  );
		printf("	 %d\n",   i.bt  );
		// printf("	 %d",   i.wt  );
		// printf("	 %d",   i.tat );
		// printf("	 %d\n", i.ct  );


    }

    vector<process>res = calcWT(n,p);
    cout<<"*************************\n\n"<<endl;

    printf("Pid     AT      BT      WT      TAT       CT\n");
    float AWT=0;
    float ATAT=0;
    for(auto i : res){
        printf(" %d ",      i.pid+1 );
		printf("	 %d ",  i.at );
		printf("	 %d",   i.bt );
		printf("	 %d",   i.wt );
		printf("	 %d",   i.tat );
		printf("	 %d\n", i.ct );
        AWT+=i.wt;
        ATAT+=i.tat;

    }
    
    cout<<"Average WT = "<<AWT/res.size()<<endl;
    cout<<"Average TAT = "<<ATAT/res.size()<<endl;


    return 0;
}