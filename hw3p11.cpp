#include <iostream>
#include <cstdlib>
#include <string>




class hash{

private:

int tableSize;

public:

hash()
		{

	tableSize= 26;
						//constructer
		}






	int hasher( std::string s, std::string t )									//hash function
	{

		int hashOfS =0;
		int hashOfT=0;
		char characterFound;
		int index;

		


		for (int i=0; i< s.length() ; i++ )
		{

			hashOfS =  hashOfS + (int)s[i];				//each word has its own askey valuu


		}

		for (int j=0; j< t.length() ; j++ )
		{

			hashOfT =  hashOfT + (int) t[j];

		}
		

int difference = hashOfT - hashOfS;				//subtract the difference of the askey values to get the askey value of the letter added		
characterFound = (char)difference ;				//typecast the difference to a char and thats the addede character

											
index = difference % tableSize; 
std::cout<<" found in bucket: "<< index+1<<"\n";			//to show which slot in the hashtable this was found 

return characterFound;
		

	}
};









int main(){

	std::string characterFound;
	hash s,t;


	characterFound= s.hasher("abcd","abcde");
std::cout<<"'"<<characterFound<<"'"<<" is the letter added"<<"\n";




	return 0;
}




















