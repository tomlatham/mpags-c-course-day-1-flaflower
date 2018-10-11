#include <iostream>
#include <cctype>
#include <string>
#include <vector>


int main(int argc, char*argv[])
{

  const std::vector<std::string> cmdLineArgs {argv, argv+argc}; //translates argc and argv arguments to main in C++11

  // Add a typedef that assigns another name for the given type for clarity
  typedef std::vector<std::string>::size_type size_type;
  const size_type nCmdLineArgs {cmdLineArgs.size()};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string input_file;
  std::string output_file;

  for (size_type i{1};i<nCmdLineArgs;i++)
    {
      //std::cout<<"Argument or flag: "<<cmdLineArgs[i]<<" \n";
      if(cmdLineArgs[i]=="-h" || cmdLineArgs[i]=="--help")
	{
	  helpRequested = true;
	}
      else if(cmdLineArgs[i]=="-i" )
	{
	  if (i!=cmdLineArgs.size()-1)
	    {
	      input_file = cmdLineArgs[i+1];
	      ++i; // skip processing of the file name argument
	    }
	  else
	    {
	      std::cerr<<"ERROR (-i): No input file name given. \n";
	      return 1;
	    }
	  
	}
      else if(cmdLineArgs[i]=="-o" )
	{
	  if (i!=cmdLineArgs.size()-1)
	    {
	      output_file = cmdLineArgs[i+1];
	      ++i; // skip processing of the file name argument
	    }
	  else
	    {
	    std::cout<<"ERROR (-o): No output file name given. \n";
	    return 1;
	    }
	}
      else if(cmdLineArgs[i]=="--version" )
	{
	    versionRequested = true;
	}
      else
	{ 
	  std::cout<<"ERROR: Argument "<<cmdLineArgs[i]<<" is not an avaliable option. Use -h or --help to see available options.\n";
	  return 1;
	} 
    }

  if ( helpRequested )
    {
      // Line splitting for readability
      std::cout
        << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
        << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
        << "Available options:\n\n"
        << "  -h|--help        Print this help message and exit\n\n"
        << "  --version        Print version information\n\n"
        << "  -i FILE          Read text to be processed from FILE\n"
        << "                   Stdin will be used if not supplied\n\n"
        << "  -o FILE          Write processed text to FILE\n"
        << "                   Stdout will be used if not supplied\n\n";
      // Help requires no further action, so return from main
      // with 0 used to indicate success
      return 0;
    }

  if ( versionRequested )
    {
      std::cout<<"Version of 09/10/2018, developed by Maria Flavia Cicala, Ph.D. student at University of Warwick.  \n";
      return 0;
    }


  //start of cipher program:
  char in_char{'x'}; // create character in_char and give it value x
  std::string out_str;
  std::cout << "Please insert character:  (press ctr d to  exit)\n";

  // Warn that input file option not yet implemented
  if (!input_file.empty()) {
    std::cout << "[warning] input from file ('"
              << input_file
              << "') not implemented yet, using stdin\n";
  }

  // Loop over each character from user input
  // (until Return then CTRL-D (EOF) pressed)
  while (std::cin >> in_char) // as long as the user inputs a character, save it in in_char
    {
      // Uppercase alphabetic characters
      if (std::isalpha(in_char)) {
        out_str += std::toupper(in_char);
        continue;
      }

      //To change numbers to words:
      switch (in_char)
	{
	  case '0':
	    out_str += "ZERO";
	    break;
	  case '1':
	    out_str += "ONE";
	    break;
	  case '2':
	    out_str += "TWO";
	    break;
	  case '3':
	    out_str += "THREE";
	    break;
	  case '4':
	    out_str += "FOUR";
	    break;
	  case '5':
	    out_str += "FIVE";
	    break;
	  case '6':
	    out_str += "SIX";
	    break;
	  case '7':
	    out_str += "SEVEN";
	    break;
	  case '8':
	    out_str += "EIGHT";
	    break;
	  case '9':
	    out_str += "NINE";
	    break;
	}
      
      // For any other type of character we do not add it to our string
    }

  // Warn that output file option not yet implemented
  if (!output_file.empty()) {
    std::cout << "[warning] output to file ('"
              << output_file
              << "') not implemented yet, using stdout\n";
  }

  std::cout << out_str << std::endl;


  return 0;
}
