#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "AVLNode.h"
#include "AVLTree.h"
#include "CancerData.h"

/*
Programer: Kyan Kotschevar-Smead
Date// 4/24/2023
Pa 3 Avl Trees
*/
/*
* (2 pts) What is the worst-case Big-O of the insert() algorithm for the AVL tree? Explain.
* Insert is o logn . this is ecuase AVL tree is a Bst that sorts its data making sure insertions can done efficently.
* the regular bst insert is ologn plus the const time which is negleible thus ologn
° (5 pts) What is the worst-case Big-O of the printInOrder() algorithm for the AVL tree? Explain.
O(n) becuase it traverses every element of the tree. like a regular bst this is no different becuase avl is only special with its rotations.
° (3 pts) What is the worst-case Big-O of the findMax() algorithm for the AVL tree? Expla
ologn becuase you are only travesing one side of the tree and not every to node to find or min or max.
*/
//Function to read and insert file data in tree
void readI(ifstream& fileIn, AVLTree &tree) {
	string temp;
	string c;
	float number = 0;
	char country[50];
	while (fileIn) {
		getline(fileIn, temp);
		strcpy(country, temp.c_str());
		c = strtok(country, ",");
		number = atof(strtok(NULL, ","));
		CancerData data(c, number);
		tree.Insert(data);
	}
}
// Main is the platform for prints.
int main() {
	ifstream womenC;
	ifstream menc;
	ifstream all;

	womenC.open("womencancerdata2018.csv");
	menc.open("mencancerdata2018.csv");
	all.open("allcancerdata2018.csv");


	AVLTree womenCt;
	AVLTree MenCt;
	AVLTree Allct;
	readI(womenC, womenCt);
	readI(menc, MenCt);
	readI(all, Allct);
	womenC.close();
	menc.close();
	all.close();
	cout << "All Data Ranked: \n\n";
	Allct.printInOrder();
	cout << "\nMen Data Ranked:\n\n";
	MenCt.printInOrder();
	cout << "\nWomen Data Ranked:\n\n";
	womenCt.printInOrder();

	cout << "\n\n 1rst Ranked Nations for Cancer Rates " << endl;
	cout << "Male: " << MenCt.findMax()->getData().getName() << " " << MenCt.findMax()->getData().getRate();
	cout << "\nFemale: " << womenCt.findMax()->getData().getName() << " " << womenCt.findMax()->getData().getRate() << endl;
	cout << "All : " << Allct.findMax()->getData().getName() << " " << Allct.findMax()->getData().getRate() << endl;

	cout << "\n\n Last Ranked Nations for Cancer Rates " << endl;
	cout << "Male: " << MenCt.findMin()->getData().getName() << " " << MenCt.findMin()->getData().getRate();
	cout << "\nFemale: " << womenCt.findMin()->getData().getName() << " " << womenCt.findMin()->getData().getRate() << endl;
	cout << "All : " << Allct.findMin()->getData().getName() << " " << Allct.findMin()->getData().getRate() << endl;
	MenCt.Clear();
	womenCt.Clear();
	Allct.Clear();
	
}