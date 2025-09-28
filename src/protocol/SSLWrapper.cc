/*
  Copyright (c) 2021 Sogou, Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  Author: Xie Han (xiehan@sogou-inc.com)
*/

#include <errno.h>
#include <string.h>
#include "SSLWrapper.h"

namespace protocol
{

// 移除 OpenSSL 依赖后的存根实现
int SSLHandshaker::encode(struct iovec vectors[], int max)
{
	// 简单返回错误，表示SSL握手功能不可用
	errno = ENOSYS;
	return -1;
}

int SSLHandshaker::append(const void *buf, size_t *size)
{
	// 简单返回错误，表示SSL握手功能不可用
	errno = ENOSYS;
	return -1;
}

int SSLWrapper::encode(struct iovec vectors[], int max)
{
	// 直接传递给底层消息编码
	return this->ProtocolWrapper::encode(vectors, max);
}

#define BUFSIZE		8192

int SSLWrapper::append_message()
{
	// 返回错误，表示SSL读取功能不可用
	errno = ENOSYS;
	return -1;
}

int SSLWrapper::append(const void *buf, size_t *size)
{
	// 直接传递给底层消息处理
	return this->ProtocolWrapper::append(buf, size);
}

int SSLWrapper::feedback(const void *buf, size_t size)
{
	return this->CommMessageIn::feedback(buf, size);
}

int ServerSSLWrapper::append(const void *buf, size_t *size)
{
	// 返回错误，表示SSL服务器功能不可用
	errno = ENOSYS;
	return -1;
}

}

