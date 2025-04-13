#pragma once
#include"cCandidate.h"
#include<iostream>
#include<vector>
using namespace std;
class cListCandidate:public cCandidate
{
private:
	int n;
	vector<cCandidate>arr;
public:
	void Nhap();
	void Xuat();
	void candidateMax();
	void sapXepGiam();

};

