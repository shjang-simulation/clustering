#include <iostream>
#include <vector>

#include "k-medoids.h"

int main()
{
	Position data[10];
	
	int flag[10];
	for (int i = 0; i < 10; i++)
	{
		flag[i] = 0;
	}


	//initalize data
	data[0].x_ = 2; data[0].y_ = 6;
	data[1].x_ = 3; data[1].y_ = 4;
	data[2].x_ = 3; data[2].y_ = 8;
	data[3].x_ = 4; data[3].y_ = 7;
	data[4].x_ = 6; data[4].y_ = 2;
	data[5].x_ = 6; data[5].y_ = 4;
	data[6].x_ = 7; data[6].y_ = 3;
	data[7].x_ = 7; data[7].y_ = 4;
	data[8].x_ = 8; data[8].y_ = 5;
	data[9].x_ = 7; data[9].y_ = 6;

	Cluster cluster1(data[1]);
	flag[1] = 1;
	Cluster cluster2(data[7]);
	flag[7] = 2;

	//clustering
	for (int i = 0; i < 10; i++)
	{
		double t = cluster1.calCost(data[i]);

		if (flag[i] != 0)
			continue;

		if (t < cluster2.calCost(data[i]))
		{
			cluster1.position_set.push_back(data[i]);
			cluster1.total_ += t;
		}
		else
		{
			cluster2.position_set.push_back(data[i]);
			cluster2.total_ += t;
		}
	}

	//find center
	cluster1.findCenter();
	cluster2.findCenter();

	std::cout << "cluster 1" << std::endl;
	std::cout << "center : " << cluster1.center_ << " total : " << cluster1.total_ << std::endl;
	
	std::cout << "cluster 2" << std::endl;
	std::cout << "center : " << cluster2.center_ << " total : " << cluster2.total_ << std::endl;



	return 0;
}