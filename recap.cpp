#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
  
int Row_counter();
int Column_counter(string line);
int ID_getter();
string line,rline,aline;




    int Row_counter()// counts the number of lines in the textfile
    {
        ifstream data1("data.txt");
        int row_count=0;
	    
	
        while (getline(data1,aline))
        {
            row_count++;
        }
        data1.seekg(0,ios::beg);
	data1.clear();
	
        return row_count;
    }


    int Column_counter(string bline)// counts the number of columns in every row
    {
        int column_count=0;

        for (int i=0;i<bline.length(); i++)
        {
            
            if (bline[i]==',')
            column_count++;


        }

       return column_count+1;    
    }

 
    int ID_getter()
    {
        string strline;
        int ID=0;

        stringstream ss(line);

        getline(ss,strline,','); 

        stringstream number(strline);

        number>>ID;

        int ipos= line.find(",");

        //line.erase(0,ipos+1);

        return ID;
    }


    
int main()
{

  
string copied;
int row,Column;

int rowcount=Row_counter()-1;

//cout<<rowcount;
	
string *** array = new string **[rowcount];//allocation of memory to 2d dynamic array
//cout<<rowcount;
	
//data.seekg(0,ios::beg);
ifstream data("data.txt");

    int iCount=0;

int *IDstorer = new int[rowcount];
int *Column_storer = new int[rowcount];
string subs_line;
int While_counter=0;
while(getline(data,line))//everything works
	
{

    int pos;
     
   // cout<<"hello";

    //row=ID_getter();
    Column= Column_counter(line);
    //cout<<Column;
    subs_line= line;

         IDstorer[iCount]=ID_getter();
         Column_storer[iCount]= Column;

    {
    array[iCount]= new string *[Column];//column allocation

        for (int column=0; column<Column;column++)
        {
	    pos= subs_line.find(",");


		
	    if (!pos)
	        array[iCount][column]= new string(subs_line);
	     
	     else if (column<=Column);
		 {    
             
			stringstream ss(subs_line);
                         getline(ss,copied,',');

                        array[iCount][column]= new string(copied);

	                 subs_line.erase(0,pos+1);
                 }
	    
            
		
	   
        }
    }

    While_counter++;
    iCount++;
 }

 
 string *** ikeep = new string **[1]; //SORTING OF ROWS


int iKeep_column,iKeep_row;


for (int i=0;i<rowcount+1;i++)//Sorting the rows of the 2D dynamic array as well as the arrays that contain the array's dimensions.
{
    for(int j=i+1;j<rowcount+1;j++)
    {
        
        if (IDstorer[i]>IDstorer[j])
        {
            iKeep_row= IDstorer[i];
            IDstorer[i]= IDstorer[j];
            IDstorer[j]=iKeep_row;


            iKeep_column=Column_storer[i];
            Column_storer[i]=Column_storer[j];
            Column_storer[j]=iKeep_column;

           ikeep[1]= array[i];
            array[i]=array[j];
            array[j]= ikeep[1];

        }
    }
}	



for (int i=0; i<rowcount+1; i++)//solution is found
{


    {



        for (int column1=0; column1<(Column_storer[i]);column1++)//columns were fixed
        {
            //cout<<i<<','<<column1<<endl;
            if(column1==Column_storer[i]-1)
            {
                cout<<*array[i][column1];
            }
            else if (column1<Column_storer[i])
            {
                cout<<*array[i][column1]<<",";
            }
            

        }
    cout<<endl;

    }

}


    for (int row=0; row<rowcount+1; row++)// start of memory deallocation for 2d dynamic array
    {
        for (int column=0; column<Column_storer[row];column++)
        {
            delete array[row][column];
        }
        delete [] array[row];
    }
    delete [] array;
    data.close();
    
    return 0;
}

//Code written by Thapelo Thoka