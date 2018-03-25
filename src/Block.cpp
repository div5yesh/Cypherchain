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

#include <iostream>

#include "Block.h"

Block::Block(string data, string prevHash) {
	this->prevHash = prevHash;
	this->data = data;
	this->timestamp = time(0);
	this->hash = CalculateHash();
	this->nonce = 0;
}

string Block::SHA256(string data){
	return picosha2::hash256_hex_string(data);
}

string Block::CalculateHash(){
	return SHA256(this->prevHash + this->data + to_string(this->timestamp) + to_string(this->nonce));
}

string Block::GetHash(){
	return this->hash;
}

string Block::GetPreviousHash(){
	return this->prevHash;
}

bool Block::IsValid(){
	return (this->hash == this->CalculateHash());
}

void Block::MineBlock(int work){
	string target(work, '0');
	while(!(this->hash.substr(0, work) == target)){
		this->nonce++;
		this->hash = CalculateHash();
	}
	cout<<GetHash()<<endl;
}

bool Block::IsMined(int work){
	string target(work, '0');
	return (this->hash.substr(0, work) == target);
}

Block::~Block() {

}

