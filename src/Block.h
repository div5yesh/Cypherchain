/*****************************************************************************
Copyright (c) 2018 Divyesh Chitroda

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#ifndef SRC_BLOCK_H_
#define SRC_BLOCK_H_

#include <string>
#include <time.h>

#include "picosha2.h"

using namespace std;

class Block {
	string hash;
	string data;
	string prevHash;
	long timestamp;

	int nonce;

	string SHA256(string data);
	string CalculateHash();
public:
	Block(string data, string prevHash);
	virtual ~Block();

	string GetHash();
	string GetPreviousHash();
	bool IsValid();
	void MineBlock(int work);
	bool IsMined(int work);
};

#endif /* SRC_BLOCK_H_ */
