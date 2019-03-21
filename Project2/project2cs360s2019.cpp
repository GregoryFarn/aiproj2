#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

struct hero{
	hero() {
	}
	hero(int id_,
		double pow_,
		double teaMast_,
		double oppMast_,
		int memb_) :
		id(id_),
		pow(pow_),
		teaMast(teaMast_),
		oppMast(oppMast_),
		memb(memb_) {}

	/*hero(hero& x) :
		id(x.id),
		pow(x.pow),
		teaMast(x.teaMast),
		oppMast(x.oppMast),
		memb(x.memb) {}

	hero operator=(hero& x) :
		id(x.id),
		pow(x.pow),
		teaMast(x.teaMast),
		oppMast(x.oppMast),
		memb(x.memb) {
	return *this
	}*/

	int id;
	double pow;
	double teaMast;
	double oppMast;
	int memb;
};

struct treeNode {
	treeNode() :
		val(0),
		choice(nullptr),
		par(nullptr)
	{
	};
	treeNode(double val_,hero* choice_,treeNode* par_) :
	val(val_),
	choice(choice_),
	par(par_)
	{
	};
	double val;
	hero *choice;
	treeNode* par;
	std::vector<treeNode*> children;
};

int findMax(std::vector<treeNode*> child){
	int max = 0;
	for (int i = 0; i < child.size(); i++) {
		if (child[i]->val > max) {
			max = i;
		}
}
	return max;
}

int findMin(std::vector<treeNode*> child) {
	int min = 1000;
	for (int i = 0; i < child.size(); i++) {
		if (child[i]->val < min) {
			min = i;
		}
	}
	return min;
}
void minMaxTree(std::vector<hero*> unchose,int level, treeNode* parent,bool oppTea) {
	if (level == 0) {
		parent->children = {};
		if (oppTea) {
			parent->val = parent->choice->pow * parent->choice->teaMast;
		}
		else {
			parent->val = parent->choice->pow * parent->choice->oppMast;
		}
		return;
	}
	std::vector<treeNode*> child;
	for (int i = 0; i < unchose.size(); i++) {
		std::vector<hero*> unchoseTemp(unchose);
		child.push_back(new treeNode(-1, unchose[i], parent));
		unchoseTemp.erase(unchoseTemp.begin() + i);
		minMaxTree(unchoseTemp, level - 1, child[i],!oppTea);
	}
	parent->children = child;
}



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
			numChose++;
		}
	}

	std::sort(unchose.begin(),unchose.end(), [](hero a, hero b) {
		return a.id < b.id;
	});

	std::vector<hero*> unchosePoint;
	
	std::transform(unchose.begin(), unchose.end(), std::back_inserter(unchosePoint), [](hero &a) {
		return &a;
	});

	treeNode * root = new treeNode();
	minMaxTree(unchosePoint, (5-numChose) *2,root,true);
	std::cout << "blek\n";
		return 1;
}
