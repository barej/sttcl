/**
 * @file SttclBoostThread.h
 *
 * Copyright (c) 2012, Guenther Makulik All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that
 * the following conditions are met:
 *
 * 1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 *    disclaimer.
 * 2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided with the distribution.
 * 3) Neither the name STTCL nor the names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef STTCLBOOSTTHREAD_H_
#define STTCLBOOSTTHREAD_H_

#if defined(STTCL_BOOST_THREADS) or defined(STTCL_BOOST_IMPL)
#include <boost/thread.hpp>
#include "../include/SttclTime.h"

namespace sttcl
{
namespace internal
{
namespace boost_impl
{
/**
 * The boost default implementation for sttcl::SttclThread<>.
 */
class SttclBoostThread
{
public:
	typedef boost::thread ThreadNativeType;

	typedef void* (*ThreadMethodPtr)(void*);

	SttclBoostThread(ThreadMethodPtr argThreadMethod);
	virtual ~SttclBoostThread();

	bool run(void* args);
	void join();
	void detach();
	static bool isSelf(const SttclBoostThread& otherThread);
    static void sleep(const TimeDuration<>& duration);

private:
	ThreadMethodPtr threadMethod;
	ThreadNativeType thread;

};
}
}
}

#endif
#endif /* STTCLBOOSTTHREAD_H_ */
