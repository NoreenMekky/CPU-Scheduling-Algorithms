#include <iostream>
using namespace std;

bool cont(int info[], int rowProcesses)
	{
		for (int i =0; i < rowProcesses ; i++)
		{
			if (info[i])
				return true;
		}
		return false;
	}
void rr()
{




	cout<<endl<< "                           Round Robin CPU Scheduling Algorithm"<<endl<<endl;



	// asking user for number of Processes, and Quantum value
	//number of processes is actually the number of cells in 1D array
	// Setting Quantum Counter to zero that acts as a timeline
	int rowProcesses, qntm, qntmCounter,contextCounter;
	contextCounter=0;
	qntmCounter=0;
	cout << "Enter the Number of Processes: ";
	cin >> rowProcesses;
	cout << "Enter quantum value: ";
	cin >> qntm;


	// Allocating a Dynamic 1D Array
	int *info = new int[rowProcesses];
	int arrwt[rowProcesses];
	int bt[rowProcesses];


	//getting Burst Time info  and filling it into the array
	for (int i=0 ;i < rowProcesses ; i++)
	{


		    cout<< " Burst Time for Process no. " << i+1<< ": ";
			cin >> info[i];

	}
	//assigning info into unchangable array
	for (int i=0 ;i < rowProcesses ; i++)
		{
               bt[i]=info[i];


		}

	// output of the Burst Time array

	cout<<endl<< "Processes and thier Burst time"<<endl;
	for (int i=0 ;i < rowProcesses ; i++)
		{

				cout<<endl;

				cout << "P"<< i+1 <<"     "<<info[i]<<endl;
		}


	//Gantt Chart
	cout<< endl << endl<<"              Gantt Chart of Processes"<<endl;
	cout << 0 <<" ";
	int j =0;

	do
	{
		if (j == rowProcesses )
			j=0;
		if (info[j] == 0)
		{
			//cout<< "P  " << (j+1) << " dakhal el zero value " << info [j] <<endl;
			j++;
			continue;
		}
	   if( info[j] >= qntm)
		{
			qntmCounter += qntm;
			info[j] -= qntm;

			if(info[j] == 0)
				arrwt[j] =qntmCounter;

			cout<< " <P" << j+1 <<"> " << qntmCounter;
			++contextCounter;
			j++;
			continue;
		}
		else if (info [j] < qntm)
		{

			qntmCounter += info[j];
			info[j] = 0;
			cout<< " <P" << j+1 << "> " << qntmCounter ;

			arrwt[j]=qntmCounter;
            ++contextCounter;
			j++;



			continue;
		}

	}while (cont(info, rowProcesses) );
	cout<<endl;
	// WT of each process

		cout<<endl<< "Waiting time for each process"<<endl;
		for (int i=0 ;i < rowProcesses ; i++)
			{

					cout<<endl;
					arrwt[i]-=bt[i];


					cout << "P"<< i+1 <<"     "<<arrwt[i]<<endl;
			}
		cout<<endl<<endl;
		int sum =0;
		for (int i=0;i<rowProcesses; i++)
		{
			sum+=arrwt[i];
		}
		cout<<"Average waiting time is: " << (sum/rowProcesses)<<endl;
		cout<<"Number of Context Switches are: "<< contextCounter-1<<endl<<endl;


	//DeAllocating and freeing space

		delete [] info;


}
void sjf()
{
	cout<<endl<< "                           Shortest Job First CPU Scheduling Algorithm"<<endl<<endl;

    int bt[20],p[20],n,i;
    int awt=0;

 cout<<"Enter number of process: ";
  cin>>n;
int arrwt[n];
arrwt[0] ==0;
 cout<<"\nEnter Burst time: \n";
  for(i=0;i<n;i++)
  {
     cout<<"Process["<<i+1<<"]: ";
     cin>>bt[i];
      p[i]=i+1;
  }

  //sorting array of burst time and
  //array of (no.) of processes as well; to match sorted processes according to burst time
  bool swap;
  int temp,pntemp;
  do
  {
  	swap =false;
  	for (int i =0; i<(n-1); i++)
  	{
  		if(bt[i]> bt[i+1])
  		{


  			temp =bt[i];
  			bt [i] =bt[i+1];
  			bt [i+1] = temp;


  			pntemp= p[i];
  			p[i]= p[i+1];
  			p[i+1] = pntemp;

  			swap = true;
  		}
  	}

  }while(swap);

 /* // this is commented for test
  //output after sorting
  cout<<"\noutbut sorting Burst time: \n";
      for(i=0;i<n;i++)
      {
         cout<<"Process["<<p[i]<<"]: "<<endl;
         cout<<bt[i]<<endl;
      }
      // this is commented for test
         //output after sorting
         cout<<"\noutbut bl 3akss sorting Burst time: \n";
             for(i=n-1;i>=0;i--)
             {
                cout<<"Process["<<p[i]<<"]: "<<endl;
                cout<<bt[i]<<endl;
             }
*/
    //GANTT CHART
      cout<<"\n       GANTT CHART \n\n";
      int ganttCounter=0;
      cout<< ganttCounter;


           for(i=0;i<n;i++)
                 {

                 cout<<" <p"<<p[i]<<"> ";
                 ganttCounter += bt[i];
                 cout<<ganttCounter;
                if(i != (n-1))
                {

                   awt+=ganttCounter;
                }




                		  arrwt[i+1]=ganttCounter ;
               }
           cout<<endl<<endl;

               cout<<"\nWaiting time for each process: \n";
               arrwt[0] =0;
                   for(i=0;i<n;i++)
                   {

                      cout<<"waiting time for Process["<<p[i]<<"]: ";
                      cout<<arrwt[i]<<endl;
                   }

//AWT

    cout<<"\n\naverage waiting time: "<< (awt/n)<<endl;
    cout<< endl << endl;

}

int main()
{
	int choice;
	do{
	cout << " Choose Number of CPU Process scheduling algorithm" << endl;
	cout<< "1 : NonPreemptive Shortest Job First\n2: Preemptive Round Robin\n";
	cout<<"your choice is: "<<endl;
	cin>> choice;
	if (choice ==1)
	{
		sjf();
	   continue;
	}
	if( choice ==2)
	{
		rr();
	continue;
	}
	else
		cout<<"Invalid Choice !!\n";
	continue;
	}while(true);


	return 0;
}

