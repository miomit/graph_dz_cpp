namespace gne
{
	class Node
	{
	public:
		Node(char name[50], char label[50]);

		char* getName() { return _name; };
		char* getLabel() { return _label; };
	private:
		char _name[50], _label[50];
	};
}