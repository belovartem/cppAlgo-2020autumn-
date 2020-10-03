/*
 * =====================================================================================
 *
 *       Filename:  solD.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03.10.2020 09:41:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

using handle_t = int*;

class D final{
	D(D const &src) = delete;
	D& operator=(D const &src) = delete;

	D(D &&src) : handle(src.handle){
		src.handle = nullptr;
	}

	D& operator=(D &&src){
		D tmp(std::move(src));
		std::swap(this->handle, tmp.handle);
		return *this;
	}

	void take_from(D &src){
		this->handle = src.handle;
		src.handle = nullptr;
	}

	D(handle_t handle): handle(handle){}
	~D(){rawClose(handle);}
		
};
