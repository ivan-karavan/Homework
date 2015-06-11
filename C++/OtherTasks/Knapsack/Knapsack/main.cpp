#include "knapsack.h"

//class test : public knapsack
//{
//public:
//	test()
//	{
//		item* items = new item[6];
//		items[0] = item(55, 3);
//		items[1] = item(80, 2);
//		items[2] = item(60, 4);
//		items[3] = item(45, 1);
//		items[4] = item(105, 3);
//		items[5] = item(50, 1);
//	}
//	item* getItems()
//	{
//		return items;
//	}
//};

int main()
{
	//item* items = new item[6];
	//items[0] = item(55, 3);
	//items[1] = item(80, 2);
	//items[2] = item(60, 4);
	//items[3] = item(45, 1);
	//items[4] = item(105, 3);
	//items[5] = item(50, 1);

	int max;
	//test* rukzak = new test();
	//rukzak.items;
	knapsack rukzak;
	rukzak.items = new item[6];
	rukzak.items[0] = item(55, 3);
	rukzak.items[1] = item(80, 2);
	rukzak.items[2] = item(60, 4);
	rukzak.items[3] = item(45, 1);
	rukzak.items[4] = item(105, 3);
	rukzak.items[5] = item(50, 1);
	
	max = rukzak.dynamic_knapsack(rukzak.items, 6, 8);
	cout << max << endl;
	max = rukzak.greedy_knapsack(rukzak.items, 6, 8);
	cout << max << endl;
	max = rukzak.backtrack_knapsack(rukzak.items, 6, 8);
	cout << max;

	delete[] rukzak.items;
	//delete rukzak;

	system("pause");
	return 0;
}

