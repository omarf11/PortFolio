//Omar Faheem of58
// project 1  PM1

#include <iostream>
using namespace std;
#define MAX2 10

void inputFunction(double arr[MAX2][MAX2],int rows, int columns){
    
    arr[rows][columns]={};
    
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<columns; j++)
        {
            cout<<" Enter Value for index ("<<i<<","<<j<<") "<<flush;
            cin>>arr[i][j];
        }
    }
    
}

void displayFunction(double arr[][MAX2],int rows,int columns)
{
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<columns; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

void additionFunction(double arr1[MAX2][MAX2], double arr2[MAX2][MAX2], double solution[MAX2][MAX2],int rows, int columns)
{
    for (int i = 0; i<rows; i++)
    {   for (int j =0; j<columns; j++){
        solution[i][j]= arr1[i][j]+ arr2[i][j];
    }
    }
    
    
}

void subtractionFunction(double arr1[MAX2][MAX2], double arr2[MAX2][MAX2], double solution[MAX2][MAX2],int rows, int columns)
{
    for (int i = 0; i<rows; i++)
    {   for (int j =0; j<columns; j++){
        solution[i][j]= arr1[i][j]-arr2[i][j];
    }
    }
    
    
}

void transpose(double arr[][MAX2],int rows, int columns, double tArr[][MAX2])
{
    for (int i=0; i<columns; i++)
    {
        for (int j=0; j<rows; j++)
        {
            
            tArr[i][j] = arr[j][i];
        }
    }
    
    
    for (int i =0; i<columns; i++)
    {
        for (int j =0; j<rows; j++)
        {  cout<<tArr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

void multiplicationFunction ( double arr[][MAX2], double arr2[][MAX2], double arr1rows,int arr1columns , int arr2columns,double solution[][MAX2])
{
    
    
    for(int i=0; i<arr1rows; i++)
    {
        for(int j=0; j < arr2columns; j++)
        { solution[i][j]=0;
            for(int k=0; k < arr1columns; k++)
            {
                solution[i][j]+=arr[i][k]*arr2[k][j];
            }
            
        }
    }
}

int determinant(double arr[][MAX2],int rows,int columns){
    int det=0;
    int posSum=0;
    
    for (int j =0; j<columns; j++ )
    {
        int prod=1, counter =j;
        for ( int i =0;i<rows; i++)
        {
            prod *=arr[i][counter];
            
            counter= counter + 1;
            counter = counter % columns;
            
        }
        posSum += prod;
        
    }
    
    int negSum=0;
    
    for (int j =columns-1; j >= 0; j--)
    {
        int prod1=1, counter1 =j;
        for ( int i =0;i<rows; i++)
        {
            prod1 *=arr[i][counter1];
            
            counter1= counter1 - 1;
            if (counter1<0)
            {counter1 = counter1 + columns;}
            counter1 = counter1 % columns;
            
            
        }
        
        negSum = negSum+ prod1;
        
    }
    
    det = posSum - negSum;
    
    return det;
}

void inverse(double arr1[][MAX2], double arr2[][MAX2], int arr1rows, int arr1columns,double arrSol[][MAX2],int det )
{
    
    
    arr2[arr1rows][arr1columns] = {};
    
    
    
    arr2[0][0]=arr1[1][1]*arr1[2][2]-arr1[1][2]*arr1[2][1];
    arr2[0][1]=-1*(arr1[1][0]*arr1[2][2]-arr1[1][2]*arr1[2][0]);
    arr2[0][2]=arr1[1][0]*arr1[2][1]-arr1[1][1]*arr1[2][0];              //getting the cofactor
    arr2[1][0]=-1*(arr1[0][1]*arr1[2][2]-arr1[2][1]*arr1[0][2]);
    arr2[1][1]=arr1[0][0]*arr1[2][2]-arr1[0][2]*arr1[2][0];
    arr2[1][2]=-1*(arr1[0][0]*arr1[2][1]-arr1[0][1]*arr1[2][0]);
    arr2[2][0]=arr1[0][1]*arr1[1][2]-arr1[0][2]*arr1[1][1];
    arr2[2][1]=-1*(arr1[0][0]*arr1[1][2]-arr1[0][2]*arr1[1][0]);
    arr2[2][2]=arr1[0][0]*arr1[1][1]-arr1[0][1]*arr1[1][0];
    
    
    for (int k=0; k<arr1columns; k++)
    {
        for (int l=0; l<arr1rows; l++)
        {                                       //Transpose the cofactor
            
            arrSol[k][l] = arr2[l][k];
        }
    }
    
    
    
    
    for (int i =0; i<arr1rows; i++)
    {
        for ( int j = 0; j<arr1columns; j++)                //final calculation for inverse
        {
            arr1[i][j] = (arrSol[i][j])/det;
        }
    }
    
}




int main()
{
    int choice;
    double arr1[MAX2][MAX2];
    double arr2[MAX2][MAX2];
    double arrSol[MAX2][MAX2];
    double det ;
    bool power= true;
    
    
    
    int arr1rows, arr1columns;
    int arr2rows, arr2columns;
    
    
    while (power == true)
    {
        std::cout<<"======= Matrix Operation Menu ======="<<"\n"<<"\n"<<"Choice 1: addition "<<"\n"<<"Choice 2: Subtraction "<<"\n" <<"Choice 3: Multiplication "<<endl <<"Choice 4: Transpose "<<endl<<"Choice 5: Determinant "<<endl<<"Choice 6: Inverse "<<endl <<"Choice 0: EXIT"<<endl <<" Please Enter Your Choice:   "<<flush;
        
        cin>>choice;
        
        switch (choice)
        {
            case 1:                             //addition
                cout<<" Addition "<<endl;
                
                cout<<endl<<"Please Enter the number of Rows for your matrices: "<<flush;
                cin>>arr1rows;
                
                cout<<endl<<"Please Enter the number of columns for your matrices: "<<flush;
                cin>>arr1columns;
                
                cout<<endl<<" Please enter values for matrix 1: "<<endl;
                inputFunction(arr1,arr1rows,arr1columns);          //array1 formatting
                displayFunction(arr1,arr1rows,arr1columns);
                
                
                cout<<endl<<" Please enter values for matrix 1: "<<endl;
                inputFunction(arr2,arr1rows,arr1columns);
                displayFunction (arr2,arr1rows,arr1columns);        //array2 formatting
                
                additionFunction( arr1,  arr2, arrSol,arr1rows,arr1columns);
                cout<<endl<<" The sum of the matrices is: "<<endl;      //operation
                displayFunction(arrSol,arr1rows,arr1columns);
                
                break;
                
                
            case 2 :                        //subtraction
                
                cout<<" Subtraction "<<endl;
                
                
                cout<<endl<<"Please Enter the number of Rows for your matrices: "<<flush;
                cin>>arr1rows;
                
                cout<<endl<<"Please Enter the number of columns for your matrices: "<<flush;
                cin>>arr1columns;
                
                cout<<endl<<" Please enter values for matrix 1: "<<endl;
                inputFunction(arr1,arr1rows,arr1columns);          //array1 formatting
                displayFunction(arr1,arr1rows,arr1columns);
                
                
                cout<<endl<<" Please enter values for matrix 2: "<<endl;
                inputFunction(arr2,arr1rows,arr1columns);
                displayFunction (arr2,arr1rows,arr1columns);        //array2 formatting
                
                subtractionFunction( arr1,  arr2, arrSol,arr1rows,arr1columns);
                
                cout<<endl<<" The difference of the matrices is: "<<endl;      //operation
                displayFunction(arrSol,arr1rows,arr1columns);
                
                break;
                
            case 3:                          //multiplication
                cout<<" Multiplication"<<endl;
                
                cout<<endl<<"Please Enter the number of Rows for  matrix 1: "<<flush;
                cin>>arr1rows;
                
                cout<<endl<<"Please Enter the number of columns for your matrix 1: "<<flush;
                cin>>arr1columns;
                
                cout<<endl<<"Please Enter the number of Rows for your matrix 2: "<<flush;
                cin>>arr2rows;
                
                cout<<endl<<"Please Enter the number of columns for your matrix 2: "<<flush;
                cin>>arr2columns;
                
                if (arr1columns != arr2rows){
                    cout<< " !ERROR!: FOR MATRIX MULTIPLICATION, MATRIX 1 COLUMNS MUST EQUAL MATRIX 2 ROWS"<<endl;
                }
                else{
                    inputFunction(arr1,arr1rows,arr1columns);
                    displayFunction(arr1,arr1rows,arr1columns);
                    
                    inputFunction(arr2,arr2rows,arr2columns);
                    displayFunction (arr2,arr2rows,arr2columns);
                    
                    multiplicationFunction ( arr1, arr2,arr1rows, arr1columns ,arr2columns,arrSol);
                    cout<<endl<<" Your Product is:"<<endl;
                    displayFunction(arrSol,arr1rows,arr2columns);
                }
                break;
                
            case 4:                          //transpose
                cout<<" Transpose "<<endl;
                
                cout<<endl<<"Please Enter the number of Rows for your matrix: "<<flush;
                cin>>arr1rows;
                
                cout<<endl<<"Please Enter the number of columns for your matrix: "<<flush;
                cin>>arr1columns;
                
                inputFunction(arr1,arr1rows,arr1columns);               //array1 formatting
                cout<<endl<<" Your original matrix is:  "<<endl;
                displayFunction(arr1,arr1rows,arr1columns);
                
                cout<<endl<<" The Transpose of the matrix is: "<<endl;
                transpose( arr1, arr1rows,  arr1columns, arrSol);
                
                break;
                
            case 5:                          //determinant
                cout<<" Determinant "<<endl;
                
                
                cout<<endl<<"Please Enter the number of Rows for your matrix: "<<flush;
                cin>>arr1rows;
                
                cout<<endl<<"Please Enter the number of columns for your matrix: "<<flush;
                cin>>arr1columns;
                
                if (arr1columns!=3 || arr1rows!=3){
                    cout<<" ERROR YOUR MATRIX MUST BE 3X3 "<<endl;
                }
                else{
                    inputFunction(arr1,arr1rows,arr1columns);
                    displayFunction(arr1,arr1rows,arr1columns);
                    
                    
                    det = determinant( arr1, arr1rows, arr1columns);
                    cout<<" Your determinant  is: "<<det<<endl;
                }
                break;
                
            case 6:
                cout<<"Inverse"<<endl;
                
                cout<<endl<<"Please Enter the number of Rows for your matrix: "<<flush;
                cin>>arr1rows;
                
                cout<<endl<<"Please Enter the number of columns for your matrix: "<<flush;
                cin>>arr1columns;
                
                if (arr1columns!=3 || arr1rows!=3){
                    cout<<" ERROR YOUR MATRIX MUST BE 3X3 "<<endl;
                }
                
                else{
                    inputFunction(arr1,arr1rows,arr1columns);
                    displayFunction(arr1,arr1rows,arr1columns);
                    
                    det = determinant( arr1, arr1rows, arr1columns);
                    if(det==0){
                        cout<<" THIS MATRIX DOES NOT HAVE AN INVERSE!"<<endl;
                    }
                    else
                    {
                        inverse(arr1, arr2,arr1rows,  arr1columns,arrSol,det );
                        
                        
                        cout<<" The inverse of your matrix is : "<<endl;
                        displayFunction(arr1,arr1rows,arr1columns );
                        
                        
                    }
                }
                
                break;
                
            case 0:  // exit
                cout<<" Exit "<<endl;
                power = false;
                break;
                
            default:
                cout<<endl<<" ERROR:  !You must enter a choice from the menu above! "<<endl<<endl;
                
                
        }
    }
    return 0;
}



