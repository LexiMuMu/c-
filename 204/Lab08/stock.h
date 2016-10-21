/********************************************************************************
 * Filename: stock.h
 * Name & Student No.: Yanhong Ben, 4845675
 * Lab No: 8
 * File Description: head file of stock
 * Date Last Modified: 24/09/2015
 *********************************************************************************/

#ifndef STOCK_H
#define STOCK_H

class Stock
{
	private:
		char tag[5];
		int cost;
		int vol;
	public:
		Stock();
		void setTag(char*);
		void setCost(int);
		void setVol(int);
		char* getTag();
		int getCost();
		int getVol();
		bool operator>(Stock &)const;
		bool operator<(Stock &)const;
	friend std::ostream& operator<<(std::ostream &, const Stock &);
};

std::ostream& operator<<(std::ostream &, const Stock &);

#endif


