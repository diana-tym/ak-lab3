#include <iostream>
#include <getopt.h>
#include <vector>
#include <algorithm>

//namespace std;

void print_opt (std::string, char*);

int main (int argc, char *argv[]){

	const char* short_options = "hu::v::s::S:";

	const struct option long_options[] = {
		{"help",no_argument,NULL,'h'},
		{"user",optional_argument,NULL,'u'},
		{"value",optional_argument,NULL,'v'},
		{"size",optional_argument,NULL,'s'},
		{"sort",required_argument,NULL,'S'},
		{NULL,0,NULL,0}
	};

	int res;
	int index;
	std::vector<int> parsed_args;

	while((res = getopt_long(argc,argv,short_options,long_options,&index)) != -1)
	{
		if (std::find(parsed_args.begin(), parsed_args.end(), res) != parsed_args.end())
		{
			continue;
		}
		else
		{
			parsed_args.push_back(res);
		}

		switch(res)
		{
			case 'h':
				print_opt("Help", optarg);
				break;
			case 'u': 
				print_opt("User", optarg);
				break;
			case 'v':
				print_opt("Value", optarg);
				break;
			case 's': 
				print_opt("Size", optarg);
				break;
			case 'S': 
				print_opt("Sort", optarg);
				break;
			case '?': default:
				std::cout << "Option unknown" << std::endl;
				exit(1);
		};
	};
	return 0;
};


void print_opt (std::string name, char *value)
{
	if (value)
		std::cout << "Arg: " << name << " = " << value << std::endl;
	else
		std::cout << "Arg: " << name << std::endl;

}

