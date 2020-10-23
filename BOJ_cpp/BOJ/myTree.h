#include <vector>

class MyTree{
public:
	MyTree();
	template <typename T> MyTree(T value);

	MyTree* getChild(int childNo);
	bool setChild(int childNo, MyTree* child);
	template <typename T> bool setChild(int childNo, T child);
	std::vector<MyTree*> getChildList();
	bool setChildList(MyTree list);

	MyTree* getParent();
	bool setParent(MyTree* parent);

	bool insertChild(MyTree* child);
	template <typename T> bool insertChild(T childValue);
	MyTree* eraseChild(int childNo);
	template <typename T> MyTree* eraseChild(T childValue);
	MyTree* eraseAllChild();

	void sort(bool sortByIncrease = true);
	template <typename T> void sort(bool(*compareFunction)(T, T), bool sortByIncrease = true);

	int getWayCount();
	bool setWayCount();

	int getChildCount();


public:
	MyTree* left;
	MyTree* right;
//	template <typename T> T value;
	

private:
	int wayCount = 2;
	bool wayResizeableByInsert = false;
	bool autoBalancing = false;
	std::vector<MyTree*> childList;
};


MyTree::MyTree()
{

}