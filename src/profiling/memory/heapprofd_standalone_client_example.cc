/*
 * Copyright (C) 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "perfetto/profiling/memory/client_ext.h"

#include <unistd.h>

int main(int, char**) {
  uint32_t heap_id = heapprofd_heap_register(heapprofd_heapinfo_create("test"));
  for (uint64_t i = 0; i < 100000; ++i) {
    heapprofd_report_allocation(heap_id, i, i);
    sleep(1);
  }
}
