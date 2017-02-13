#pragma once
#include <vector>
#include <iostream>

class Position
{
public:
	double x_, y_, z_ = 0;

	Position()
	{}

	Position(double _x, double _y, double _z)
		:x_(_x), y_(_y), z_(_z)
	{}

	
};

std::ostream& operator<<(std::ostream& os, const Position& p)
{
	os << "[" << p.x_ << ", " << p.y_ << ", " << p.z_ << "]";
	return os;
}

class Cluster
{
private:
	
	
	double cost;

public:
	std::vector<Position> position_set;
	double total_;
	Position center_;

	Cluster()
	{}

	Cluster(Position c)
		:center_(c)
	{
		position_set.push_back(center_);
	}

	double calCost(Position comp)
	{
		//Manhattan Distance
		double x = abs(center_.x_ - comp.x_);
		double y = abs(center_.y_ - comp.y_);
		double z = abs(center_.z_ - comp.z_);

		return x + y + z;
	}

	void findCenter()
	{
		double total = 0;
		for (int i = 0; i < position_set.size(); i++)
		{
			Position temp_center_ = position_set[i];
			for (int i = 0; i < position_set.size(); i++)
			{
				total += abs(temp_center_.x_ - position_set[i].x_);
				total += abs(temp_center_.y_ - position_set[i].y_);
				total += abs(temp_center_.z_ - position_set[i].z_);
			}

			if (total_ > total)
			{
				center_ = temp_center_;
				total_ = total;
			}
		}
		
	}
};