/**
 * @file SttclPosixMutex.h
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

#ifndef STTCLPOSIXMUTEX_H_
#define STTCLPOSIXMUTEX_H_

#include <pthread.h>
#include "../include/SttclTime.h"

#if defined(STTCL_POSIX_THREADS) or defined(STTCL_POSIX_IMPL)

namespace sttcl
{
namespace internal
{
namespace posix_impl
{

/**
 * The POSIX default implementation for sttcl::SttclMutex<>.
 */
class SttclPosixMutex
{
public:
	SttclPosixMutex();
	~SttclPosixMutex();

	void lock();
	bool try_lock(const TimeDuration<>& timeout);
	void unlock();

private:
	pthread_mutex_t mutexHandle;
	bool valid;
};

}
}
}
#endif
#endif /* STTCLPOSIXMUTEX_H_ */
