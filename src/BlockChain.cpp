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

#include "BlockChain.h"

BlockChain::BlockChain(int work) {
	this->work = work;

	Block genesisBlock("HEAD", "0");
	genesisBlock.MineBlock(this->work);
	this->chain.push_back(genesisBlock);
}

void BlockChain::AddBlock(string record){
	Block block(record, this->chain.back().GetHash());
	block.MineBlock(this->work);
	this->chain.push_back(block);
}

bool BlockChain::IsValid(){
	int chainSize = this->chain.size();

	for(int i=1;i<chainSize;i++){
		Block prevBlock = this->chain.at(i-1);
		Block currentBlock = this->chain.at(i);

		if(prevBlock.GetHash() != currentBlock.GetPreviousHash()){
			return false;
		}

		if(!currentBlock.IsValid()){
			return false;
		}

		if(!currentBlock.IsMined(this->work)){
			return false;
		}
	}

	return true;
}

BlockChain::~BlockChain() {

}

