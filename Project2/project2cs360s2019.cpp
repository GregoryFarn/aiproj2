#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

struct hero{
	hero(int id_,
		double pow_,
		double teaMast_,
		double oppMast_,
		int memb_) :
		id(id_),
		pow(pow_),
		teaMast(teaMast_),
		oppMast(oppMast_),
		memb(memb_){}
	int id;
	double pow;
	double teaMast;
	double oppMast;
	int memb;
};

struct node {
	double value;
	hero choice;
	node* parent;
	std::vector<node*> children;
};

int main(int argc, const char* argv[]) {

	std::ifstream file("input0.txt", std::ifstream::in);
	std::string temp;
	int hNum;
	std::string searchType;


	file >> hNum;
	file >> searchType;

	std::vector<hero> unchose;
	int numChose=0;
	for(int i =0; i<hNum; ++i) {
		file >> temp;
		int id = stoi(temp.substr(0, temp.find_first_of(",")));
		temp = temp.substr(temp.find_first_of(",") + 1);
		double pow = stod(temp.substr(0, temp.find_first_of(",")));
		temp = temp.substr(temp.find_first_of(",") + 1);
		double teaMast = stod(temp.substr(0, temp.find_first_of(",")));
		temp = temp.substr(temp.find_first_of(",") + 1);
		double oppMast = stod(temp.substr(0, temp.find_first_of(",")));
		temp = temp.substr(temp.find_first_of(",") + 1);
		int memb = stoi(temp);

		if (memb == 0) {
			unchose.push_back(hero(id, pow, teaMast, oppMast, memb));
		}
		else if (memb == 1) {

		}
	}

	std::sort(unchose.begin(),unchose.end(), [](hero a, hero b) {
		return a.id < b.id;
	});

		return 1;
}

int minMax(std::vector<hero> unchose) {
	
}