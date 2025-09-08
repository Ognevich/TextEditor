#ifndef _CURSOR_HPP_
#define _CURSOR_HPP_

class Cursor {

private:
	int rows;
	int cols;

public:
	
	Cursor();

	int getRows();
	int getCols();

	void setRows(int newRows);
	void setCols(int newCols);

};


#endif

