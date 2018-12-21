#ifndef STRINGTABNODE_H_
#define STRINGTABNODE_H_

#define MEM 2000

class StringTabNode {
	public:
		StringTabNode();
		virtual ~StringTabNode();
		char* getVector();
		void setNext(StringTabNode* next);
		StringTabNode* getNext();
	private:
		char vector[MEM];
		StringTabNode* next;
};


#endif /* STRINGTABNODE_H_ */
