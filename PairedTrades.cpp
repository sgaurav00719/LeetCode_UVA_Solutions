/*
 * PairedTrades.cpp
 *
 *  Created on: Apr 29, 2017
 *      Author: ik.yola
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <fstream>


#include <bits/stdc++.h>
#define rep(i,n) for(size_t i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9
typedef long long i64;
typedef unsigned long long ui64;
typedef std::string st;
typedef std::vector<int> vi;
typedef std::vector<st> vs;
typedef std::map<int, int> mii;
typedef std::map<st, int> msi;
typedef std::set<int> si;
typedef std::set<st> ss;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
#define mx 0

//Tokenizer
vs csvParser(st& line) {
	std::stringstream ss(line);
	vs result;
	st cell;
	while (std::getline(ss, cell, ',')) {
		result.pb(cell);
	}
	//Check for an empty element
	if (!ss && cell.empty()) {
		// Add an empty element if there is a trailing comma.
		result.pb("");
	}
	return result;
}

struct quotes {
	int time;
	st symbol;
	double bid;
	double ask;
};

struct trades {
	int time;
	st symbol;
	st side;
	double price;
	int quantity;
};

void tradePairs(std::multimap<int, quotes>& quotesData,
		std::multimap<st, trades>& tradesDataBuy,
		std::multimap<st, trades>& tradesDataSell) {
	for (auto cl = tradesDataSell.begin(); cl != tradesDataSell.end();
			++cl) {
		auto op = tradesDataBuy.find(cl->second.symbol);
		//Found pair
		if (op != tradesDataBuy.end()) {
			double PNL, openBid, openAsk, closeBid, closeAsk;
			int newQuantity;
			st openLiq, closeLiq;
			if (op->second.quantity >= cl->second.quantity) {
				newQuantity = cl->second.quantity;
				//update open quantity
				op->second.quantity -= newQuantity;

				// removing element if quantity becomes zero
				if (op->second.quantity == 0)
					tradesDataBuy.erase(op);
				PNL = newQuantity * cl->second.price
						- newQuantity * op->second.price;

				//Liquidity info for open
				for (auto qIt = quotesData.begin(); qIt != quotesData.end();
						++qIt) {
					if (op->second.symbol == qIt->second.symbol
							&& qIt->first <= op->second.time) {
						openBid = qIt->second.bid;
						openAsk = qIt->second.ask;
						if (op->second.price <= openBid) {
							openLiq = "P";
						} else if (op->second.price >= openAsk) {
							openLiq = "A";
						}else openLiq = " ";
					}
					if (qIt->first > op->second.time)
						break;
				}

				//Liquidity info for close
				for (auto qIt = quotesData.begin(); qIt != quotesData.end();
						++qIt) {
					if (cl->second.symbol == qIt->second.symbol
							&& qIt->first <= cl->second.time) {
						closeBid = qIt->second.bid;
						closeAsk = qIt->second.ask;
						if (cl->second.price >= closeAsk) {
							closeLiq = "P";
						} else if (op->second.price <= closeBid) {
							closeLiq = "A";
						}else closeLiq = " ";
					}
					if (qIt->first > cl->second.time)
						break;
				}
			} else {
				newQuantity = op->second.quantity;
				PNL = newQuantity * cl->second.price
						- newQuantity * op->second.price;

				//update close quantity, create new entry in tradeDataBuy and delete previous close entry
				trades newEntry;
				cl->second.quantity -= newQuantity;
				newEntry.quantity = cl->second.quantity;
				newEntry.price = cl->second.price;
				newEntry.side = "B";
				newEntry.symbol = cl->second.symbol;
				newEntry.time = cl->second.time;
				tradesDataBuy.insert(std::make_pair(cl->second.symbol,newEntry));
				tradesDataBuy.erase(cl);
				//Liquidity info for open
				for (auto qIt = quotesData.begin(); qIt != quotesData.end();
						++qIt) {
					if (op->second.symbol == qIt->second.symbol
							&& qIt->first <= op->second.time) {
						openBid = qIt->second.bid;
						openAsk = qIt->second.ask;
						if (op->second.price <= openBid) {
							openLiq = "P";
						} else if (op->second.price >= openAsk) {
							openLiq = "A";
						}else openLiq = " ";
					}
					if (qIt->first > op->second.time)
						break;
				}

				//Liquidity info for close
				for (auto qIt = quotesData.begin(); qIt != quotesData.end();
						++qIt) {
					if (cl->second.symbol == qIt->second.symbol
							&& qIt->first <= cl->second.time) {
						closeBid = qIt->second.bid;
						closeAsk = qIt->second.ask;
						if (cl->second.price >= closeAsk) {
							closeLiq = "P";
						} else if (op->second.price <= closeBid) {
							closeLiq = "A";
						}else closeLiq = " ";
					}
					if (qIt->first > cl->second.time)
						break;
				}
				// removing element because closing trade is larger
				tradesDataBuy.erase(op);
			}

			//Printing Result
			std::cout << op->second.time << " "  <<  cl->second.time << " " << op->second.symbol << " "  << newQuantity  << " " << PNL
					<< " " << op->second.side << " " << cl->second.side << " " << op->second.price << " " << cl->second.price << " "
					<< openBid << " " << closeBid << " " << openAsk << " " << closeAsk << " " << openLiq << " " << closeLiq << std::endl;
		}
	}

}

int main(int argc, char *argv[]) {

	//Reading Quotes File
	std::multimap<int, quotes> quotesData;
	std::ifstream quotesIn(argv[1]);
	st lineQ;
	int count = 0; //count to skip the header
	while (getline(quotesIn, lineQ)) {
		if (count > 0) {
			quotes _quotes;
			vs l = csvParser(lineQ);
			_quotes.time = std::stoi(l[0]);
			_quotes.symbol = l[1];
			_quotes.bid = std::stod(l[2]);
			_quotes.ask = std::stod(l[3]);
			quotesData.insert(std::make_pair(_quotes.time, _quotes));
		}
		count++;
	}

	//Reading Trades File
	std::multimap<st, trades> tradesDataBuy;
	std::multimap<st, trades> tradesDataSell;
	std::ifstream tradesIn(argv[2]);
	st lineT;
	count = 0; //count to skip the header
	while (getline(tradesIn, lineT)) {
		if (count > 0) {
			trades _trades;
			vs l = csvParser(lineT);
			_trades.time = std::stoi(l[0]);
			_trades.symbol = l[1];
			_trades.side = l[2];
			_trades.price = std::stod(l[3]);
			_trades.quantity = std::stoi(l[4]);
			if (_trades.side == "B"){
				tradesDataBuy.insert(std::make_pair(_trades.symbol, _trades));
			}
			else
				tradesDataSell.insert(std::make_pair(_trades.symbol, _trades));
		}
		count++;
	}

	tradePairs(quotesData, tradesDataBuy, tradesDataSell);

	/*
	std::cout << "\n\n";
	for(auto i : tradesDataBuy)
		std::cout << i.second.time << " " << i.second.symbol << " "
		<< i.second.side << " " << i.second.price << " " << i.second.quantity <<std::endl;
	std::cout << "\n\n";
	for(auto i : tradesDataSell)
			std::cout << i.second.time << " " << i.second.symbol << " "
			<< i.second.side << " " << i.second.price << " " << i.second.quantity <<std::endl;
			*/

	return 0;
}

