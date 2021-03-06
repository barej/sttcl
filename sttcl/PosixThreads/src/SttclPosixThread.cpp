/**
 * @file SttclPosixThread.cpp
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

#include "../../include/SttclConfig.h"
#include "../SttclPosixThread.h"
#include <unistd.h>

#if defined(STTCL_POSIX_THREADS) or defined(STTCL_POSIX_IMPL)

using namespace sttcl;
using namespace sttcl::internal;
using namespace sttcl::internal::posix_impl;
using sttcl::internal::posix_impl::SttclPosixThread;

SttclPosixThread::SttclPosixThread(ThreadMethodPtr argThreadMethod)
: threadMethod(argThreadMethod)
, pthreadHandle()
, valid(false)
{
}

SttclPosixThread::~SttclPosixThread()
{
	detach();
}

bool SttclPosixThread::run(void* args)
{
	if(threadMethod && !valid)
	{
		if(pthread_create(&pthreadHandle,NULL,threadMethod,args) == 0)
		{
			valid = true;
		}
	}

	return valid;
}

void SttclPosixThread::join()
{
	if(valid)
	{
		pthread_join(pthreadHandle, NULL);
		valid = false;
	}
}

void SttclPosixThread::detach()
{
	if(valid)
	{
		pthread_detach(pthreadHandle);
		valid = false;
	}
}

bool SttclPosixThread::isSelf(const SttclPosixThread& otherThread)
{
	return pthread_equal(pthread_self(),otherThread.pthreadHandle) != 0;
}

void SttclPosixThread::sleep(const TimeDuration<>& duration)
{
#if defined(STTCL_POSIX_NANOSLEEP)
    TimeDuration<>::NativeTimeDuration retval;
    nanosleep(&duration.getNativeValue(),&retval);
#else
    usleep(duration.microseconds());
#endif
}

#endif
