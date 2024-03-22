namespace gne
{
	class Node
	{
	public:
		Node(char* name, char* label = nullptr);
		~Node();

		char* getName() { return _name; };
		char* getLabel() { return _label; };
	private:
		char* _name;
		char* _label;
	};
}