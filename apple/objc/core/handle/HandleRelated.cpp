/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <WCDB/Assertion.hpp>
#include <WCDB/Handle.hpp>
#include <WCDB/HandleRelated.hpp>

namespace WCDB {

HandleRelated::HandleRelated(AbstractHandle *handle) : m_handle(handle)
{
    WCTInnerAssert(m_handle != nullptr);
}

HandleRelated::~HandleRelated()
{
}

bool HandleRelated::exitAPI(int rc)
{
    return m_handle->exitAPI(rc);
}

bool HandleRelated::exitAPI(int rc, const String &sql)
{
    return m_handle->exitAPI(rc, sql);
}

bool HandleRelated::exitAPI(int rc, const char *sql)
{
    return m_handle->exitAPI(rc, sql);
}

AbstractHandle *HandleRelated::getHandle() const
{
    return m_handle;
}

sqlite3 *HandleRelated::getRawHandle()
{
    return m_handle->getRawHandle();
}

} //namespace WCDB
