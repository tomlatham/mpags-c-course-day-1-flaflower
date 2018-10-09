#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <vector>


int main(int argc, char*argv[])
{

  const std::vector<std::string> cmdLineArgs {argv, argv+argc}; //translates argc and argv arguments to main in C++11

  std::string input_file;
  std::string output_file;

  for (int i=1;i<cmdLineArgs.size();i++)
    {
      //std::cout<<"Argument or flag: "<<cmdLineArgs[i]<<" \n";
      if(cmdLineArgs[i]=="-h" || cmdLineArgs[i]=="--help")
	{
	  std::cout<<"Hello, your argument was: "<<cmdLineArgs[i]<<", This is where you would have help \n";
	}else if(cmdLineArgs[i]=="-i" )
	{
	  if (i!=cmdLineArgs.size()-1)
	    {
	      input_file = cmdLineArgs[i+1];
	      std::cout<<"Input file: "<<input_file<<"\n";
	    }else{
	    std::cout<<"ERROR (-i): No input file name given. \n";
	  }
	  
	}else if(cmdLineArgs[i]=="-o" )
	{
	  if (i!=cmdLineArgs.size()-1)
	    {
	      output_file = cmdLineArgs[i+1];
	      std::cout<<"Output file: "<<output_file<<"\n";
	    }else{
	    std::cout<<"ERROR (-o): No output file name given. \n";
	  }
	  
	}else if(cmdLineArgs[i]=="--version" )
	{
	    std::cout<<"Version of 09/10/2018, developed by Maria Flavia Cicala, Ph.D. student at University of Warwick.  \n";
	  
	}else if(cmdLineArgs[i]!="-h" || cmdLineArgs[i]!="--help" || cmdLineArgs[i]!="--version" || cmdLineArgs[i]!="-i")
	{ 
	  //std::cout<<"In non-known argument if, out of i-1 if \n";
	  if(cmdLineArgs[i-1]!="-i" && cmdLineArgs[i-1]!="-o")
	  {
	  std::cout<<"ERROR: Argument "<<cmdLineArgs[i]<<" is not an avaliable option. Use -h or --help, --version, -i or -o. \n";
	   }
	} 
    }


  std::cout<<"Hello world!\n";
  
  int a{2};
  double b{3.5};
  double c = a*b;

  const double e{6.9};
  int d = b;

  double f  = c/2;
  int g = b/2;


  std::string msg {"Hello"};
  std::string msg1 {"My name is Flavia"};

  char H {msg1[11]};

  std::cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << ", const e = " << e << ", f = " << f << " , g = " << g << ", H = " << H << std::endl;

  std::cout << msg << "\n";

  std::string out_str;

  //start of cipher program:
  char in_char{'x'}; // create character in_char and give it value x
  std::cout << "Please insert character:  (press ctr d to  exit)\n";

  while (std::cin >> in_char) // as long as the user inputs a character, save it in in_char
    {
      //To change numbers to words:
      switch (in_char)
	{
	case 1:
	  // std::string one {"ONE"};
	  out_str += "ONE";
	  break;

	  // To convert character inserted in in_char to uppercase:
	  char up_char = toupper(in_char);
     
	  //putchar (toupper(in_char));
	  
	  //out_str += up_char;
	  
	}
      std::cout << out_str;
    }
  std::cout << out_str;


  return 0;

}
