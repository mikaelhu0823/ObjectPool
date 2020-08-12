#pragma once
//========================================================================
//[File Name]:NonCopyable.h
//[Description]:
//[Author]:Nico Hu
//[Date]:2020-07-14
//[Other]:
//========================================================================


class NonCopyable {
protected:
	NonCopyable() = default;
	virtual ~NonCopyable() = default;
	NonCopyable(const NonCopyable&) = delete;
	NonCopyable& operator=(const NonCopyable&) = delete;
};