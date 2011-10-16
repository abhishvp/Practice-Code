#include "binTree.h"

int main (int argc,char *argv[]) {
		BinTree *asdf = new BinTree();
		asdf->insert(5);
		asdf->insert(3);
		asdf->insert(10);
		asdf->insert(1);
		asdf->insert(4);
		asdf->insert(7);
		asdf->insert(12);
		
		std::cout << asdf->search(7)->getKeyVal()<< std::endl;
		
		asdf->preorderTraversal();
		
		std::cout << std::endl;

		delete asdf;

//		system("PAUSE");
		return 1;
}

